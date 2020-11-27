/*
have the function WildcardCharacters(str) read str which will contain two strings separated by a space. The first string will consist of the following sets of characters: +, *, and {N} which is optional. The plus (+) character represents a single alphabetic character, the asterisk (*) represents a sequence of the same character of length 3 unless it is followed by {N} which represents how many characters should appear in the sequence where N will be at least 1. Your goal is to determine if the second string exactly matches the pattern of the first string in the input.
For example: if str is "++*{5} gheeeee" then the second string in this case does match the pattern, so your program should return the string true. If the second string does not match the pattern your program should return the string false.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string Wildcards(string str) {
  int cut = str.find_first_of(" ");
  string pattern = str.substr(0,cut);
  string s = str.substr(cut+1,str.size());
  int sindex=0;
  int pindex=0;
  
  

  while(pindex<pattern.size() && sindex<s.size()){
    // +
    if(pattern[pindex]=='+'){
      ++pindex;
      ++sindex;
      //cout<<"+passed"<<" ";
    }

    // $
    else if (pattern[pindex]=='$'){
      if(s[sindex]>='0' && s[sindex]<='9'){
        ++pindex;
        ++sindex;
        //cout<<"$passed"<<" ";
      }
      else{
        //cout<<"$notpassed"<<" ";
        return "false";
        }
    }

    // *
    else if (pattern[pindex]=='*'){
      int num;
      //cout<<endl<<"-> pindex is: "<<pindex<<endl;;
      if(pindex+3<pattern.size() && pattern[pindex+1]=='{'){
        size_t end=pattern.find_first_of("}",pindex);
        istringstream stream(pattern.substr(pindex+2,end));
        stream>>num;
        pindex=end+1;
        //cout<<"->num is "<< num<<" sindex is "<<sindex<<endl;
      }
      else{
        num=3;
        ++pindex;
      }

      if(sindex+num-1<s.size()){
        char tmp=s[sindex];
        for(int i=1;i<num;i++){
          if(s[sindex+i]!=tmp){
            //cout<<"*notpassed"<<" ";
            return "false";
          }
        }
        //cout<<"*passed"<<" ";
        sindex+=num;
      }
      else
        return "false";
      
    }

    //else
    //  cout<<"No match"<<endl;

  }

  if(sindex==s.size() && pindex==pattern.size())
    return "true";
  else
    return "false";
}

int main(void) { 
   
  // keep this function call here
  cout << Wildcards(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
