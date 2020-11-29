/*
have the function ParallelSums(arr) take the array of integers stored in arr which will always contain an even amount of integers, and determine how they can be split into two even sets of integers each so that both sets add up to the same number. If this is impossible return -1. If it's possible to split the array into two sets, then return a string representation of the first set followed by the second set with each integer separated by a comma and both sets sorted in ascending order. The set that goes first is the set with the smallest first integer.
For example: if arr is [16, 22, 35, 8, 20, 1, 21, 11], then your program should output 1,11,20,35,8,16,21,22
*/

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

string ParallelSums(int arr[], int arrLength) {
  vector<int> arrbag(arr,arr+arrLength);
  sort(arrbag.begin(),arrbag.end(),greater<int>());
  vector<int> left;
  vector<int> right;
  int left_acc=0;
  int right_acc=0;
  int last_insert=0;
  for(auto it=arrbag.begin();it!=arrbag.end();++it){
    if(left_acc<=right_acc){
      left.push_back(*it);
      left_acc+=*it;
      last_insert=0;
    }
    else if(right_acc<left_acc){
      right_acc+=*it;
      right.push_back(*it);
      last_insert=1;
    }
  }

  string ret="";

  if(accumulate(left.begin(),left.end(),0)!=
     accumulate(right.begin(),right.end(),0))
    return "-1";

  else{
    if(last_insert==0){
      for(int i=left.size()-1;i>=0;i--)
        ret+=to_string(left[i])+",";
      for(int i=right.size()-1;i>=0;i--)
        ret+=to_string(right[i])+",";
    }

    else{
      for(int i=right.size()-1;i>=0;i--)
        ret+=to_string(right[i])+",";
      for(int i=left.size()-1;i>=0;i--)
        ret+=to_string(left[i])+",";
    }
  }

  /*DEBUG
  for(auto it=left.begin();it!=left.end();++it){
    cout<<*it;}
  cout<<"--"<<endl;
  for(auto it=right.begin();it!=right.end();++it){
    cout<<*it;}*/
  

  // code goes here  
  return ret.substr(0,ret.size()-1);

}



int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ParallelSums(A, arrLength);
  return 0;
    
}
