#include <stdio.h>
int target_count=-1;
int findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	if(target_count==-1)
		target_count=(nums1Size+nums2Size-1)/2; //要干掉target_count个数字
	int pos_1_val=*(nums1+target_count/2-1); //val to be compared in a
	int pos_2_val=*(nums2+target_count/2-1); //val to be compared in b
	printf("数组1检测：%d; 数组2检测：%d\n",pos_1_val,pos_2_val);

	if(pos_1_val<pos_2_val){
		nums1+=target_count/2;
		nums1Size-=target_count/2;
		printf("干掉了数组1 小于%d 的数据\n",pos_1_val);
	}
	else{
		nums2+=nums2Size/2;
		nums2Size-=nums2Size/2;
		printf("干掉了数组2 小于%d 的数据\n",pos_2_val);
    }
	target_count-=target_count/2;
	printf("剩余size：%d\n",target_count);
	if(target_count>1)
		findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	//result=((*nums1)-(*nums2))>0 ? (*nums1),(*nums2);
	printf("数组1开头：%d\n数组2开头：%d\n",*nums1,*nums2);
	return 0;
}




int main(){
	int a[] ={1,2,3};
	int b[] ={3,4};
	findMedianSortedArrays(a, sizeof(a)/4, b, sizeof(b)/4);	
}
