#include <stdio.h>
int target_count=-1;
int original_length;
float findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	getchar();
	if(target_count==-1){
		original_length=nums1Size+nums2Size;
		target_count=(nums1Size+nums2Size-1)/2;} //要干掉target_count个数字
		
	printf("一共要干掉%d个\n",target_count);
	int pos_1_val=*(nums1+target_count/2-1); //val to be compared in a
	int pos_2_val=*(nums2+target_count/2-1); //val to be compared in b
	if(target_count==1)
		{pos_1_val=*nums1;
		pos_2_val=*nums2;}
		
	printf("数组1(%d)检测值：%d; 数组2(%d)检测值：%d\n",nums1Size,pos_1_val,nums2Size,pos_2_val);

	if(pos_1_val<pos_2_val){
		if(nums1Size<=target_count/2 || nums1Size==1){
			printf("数字1清空\n");
			target_count-=nums1Size;
			return original_length%2?(float)*nums2:(float)(*nums2+*(nums2+1))/2;
		}
		nums1+=target_count/2;
		nums1Size-=target_count/2;
		printf("干掉了数组1 小于等于%d 的数据\n",pos_1_val);
	}
	else{
		if(nums2Size<=target_count/2 || nums2Size==1){
			printf("数字2清空\n");
			target_count-=nums2Size;
			return original_length%2?(float)*nums1:(float)(*nums1+*(nums1+1))/2;
		}
		nums2+=nums2Size/2;
		nums2Size-=nums2Size/2;
		printf("干掉了数组2 小于等于%d 的数据\n",pos_2_val);
    }
	target_count-=target_count/2;
	printf("剩余要干掉target_count: %d\n",target_count);
	printf("数组1(%d)开头:%d; 数组2(%d)开头:%d\n",nums1Size,*nums1,nums2Size,*nums2);
	if(target_count>1)
		return findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	
	if((original_length)%2)
		return *nums1>*nums2?*nums1:*nums2;
	else{
		if(*nums1>*nums2)
			return *(nums1+1)>*(nums2+1)?(float)(*(nums2+1)+*nums1)/2:(float)(*nums1+*(nums1+1))/2;
		else
			return *(nums1+1)>*(nums2+1)?(float)(*(nums2+1)+*nums2)/2:(float)(*nums2+*(nums1+1))/2;}
}

int main(){
	int a[] ={1,2,4};
	int b[] ={3,4,5};
	printf("中位数：%f",findMedianSortedArrays(a, sizeof(a)/4, b, sizeof(b)/4));	
	return 0;
}
