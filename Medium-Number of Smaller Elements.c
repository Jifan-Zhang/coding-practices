#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int a[5]={10,3,2,0,7};
	const int len=(int)sizeof(a)/4;
	int max=0;
	int * p[len];
	int result[len];
	
	// n: find the max number
	for(int i=0; i<(int)sizeof(a)/4; i++){
		if(a[i]>max)
			max=a[i];
	}	
	
	int* boxes = (int*)malloc(max * sizeof(int));
	memset(boxes, 0, sizeof(int) * (max+1));	
	
	// n: fill in box, initialize array of pointers
	for(int i=0; i<len; i++){
		p[i]=boxes+a[i];
		*(p[i])+=1;
	}
	
	// d: number
	int num=0;
	for(int i=0; i<=max; i++){
		if(*(boxes+i)!=0){
			int tmp;
			tmp=num;
			num+=*(boxes+i);
			*(boxes+i)=tmp;
		}
	}

	// n
	for(int i=0;i<len;i++){
		printf("%d\t",*(p[i]));
	}
	
	return 0;

}
