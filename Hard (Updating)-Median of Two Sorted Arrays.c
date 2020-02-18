//Remember the Median number
#include <stdio.h>
int med_pos; //Left node or middle node
float med_val;
void get_median(int *n, int size){
	if(size%2){
		med_pos=(size-1)/2;
		med_val=(float)*(n+med_pos);}
	else{
		med_pos=size/2-1;
		med_val=(float)(*(n+med_pos)+*(n+med_pos+1))/2;}
	//printf("%d\n",med_pos);printf("%f\n",med_val);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	//printf("%d,%d",nums1Size,nums2Size);
	get_median(nums1,nums1Size); int pos_a=med_pos; float med_a_val=med_val;
	get_median(nums2,nums2Size); int pos_b=med_pos; float med_b_val=med_val;
	return 0.0;
}

		


int main(){
	int a[] ={1,2,3,4,5,6,7,8,9,10};
	int b[] ={3,4,5,6,7,8};
	findMedianSortedArrays(a, sizeof(a)/4, b, sizeof(b)/4);	
}
