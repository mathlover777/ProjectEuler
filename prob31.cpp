#include <stdio.h>
#include <stdlib.h>
int findAns(int *a,int sum,int *count,int index){
	if(index==7){
		if(sum>=0){
			(*count)++;
		}
		return 0;
	}
	while(sum>=0){
		findAns(a,sum,count,index+1);
		sum=sum-a[index];
	}
}
int main(){
	int a[8];
	a[7]=1;
	a[6]=2;
	a[5]=5;
	a[4]=10;
	a[3]=20;
	a[2]=50;
	a[1]=100;
	a[0]=200;
	int count=0;
	findAns(a,200,&count,0);
	printf("\n ANS = %d \n",count);
}