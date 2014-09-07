#ifndef SORT_INCLUDED
#define SORT_INCLUDED
#include <stdio.h>
#include <stdlib.h>
template <typename T>void mergeSortCode(T r[],int left,int right,T *temp){
	if(left>=right) return;//base case
	int p=(left+right)/2;
	mergeSortCode(r,left,p,temp);
	mergeSortCode(r,p+1,right,temp);
	int i,t,j;
	i=left;
	j=p+1;
	t=0;
	while((i<=p)&&(j<=right)){
		if(r[i]<r[j]){
			temp[t]=r[i];
			t++;
			i++;
		}else{
			temp[t]=r[j];
			t++;
			j++;
		}
	}
	while(i<=p){
		temp[t]=r[i];
		i++;
		t++;
	}
	while(j<=right){
		temp[t]=r[j];
		j++;
		t++;
	}
	for(i=0;i<t;i++){
		r[left+i]=temp[i];
	}
	return;
}
template <typename T>void mergeSort(T a[],int size){
	printf("\nGoing to Allocate Memory for Mergesort");
	T *temp=new T[size];
	printf("Memory allocated\n");
	mergeSortCode(a,0,size-1,temp);
	return;
}
// int main(){
// 	int r[10];
// 	printf("\n{");
// 	for(int i=0;i<=9;i++){
// 		r[i]=rand()%100;
// 		printf(" %d ",r[i]);
// 	}
// 	printf("}\n");
	
// 	mergeSort(r,10);
// 	printf("\n{");
// 	for(int i=0;i<=9;i++){
// 		printf(" %d ",r[i]);
// 	}
// 	printf("}\n");
// }
#endif