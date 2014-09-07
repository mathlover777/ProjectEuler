#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mergeSort(int r[],char a[][12],int left,int right,int *temp);
int findCost(char *a);
int main(){
	char a[5163][12];
	int r[5163],temp[5163];
	int i,j;
	FILE *f;
	f=fopen("prob22.txt","r");
	// for(i=0;i<=5162;i++){
	// 	for(j=0;j<=11;j++){
	// 		a[i][j]='\0';
	// 	}
	// }
	for(i=0;i<5163;i++){
		fscanf(f,"%s",&(a[i][0]));
		r[i]=i;
		//printf("\n%s",a[i]);
	}
	fclose(f);
	mergeSort(r,a,0,5162,temp);
	f=fopen("sorted22.txt","w");
	long long int sum=0,x;
	for(i=0;i<5163;i++){
		x=findCost(&(a[r[i]][0]));
		sum=sum+x*(i+1);
		fprintf(f,"%s\t%llu\n",&(a[r[i]][0]),x);
		//printf("\n%s",a[i]);
	}
	fclose(f);
	printf("\nANS = %llu \n",sum);
}
int findCost(char *a){
	int sum=0;
	int i=0;
	while(*a!='\0'){
		//printf("\n i =%d",i);
		i++;
		sum=sum+(int)((*a)-64);
		a++;
	}
	return sum;
}
int mergeSort(int r[],char a[][12],int left,int right,int *temp){
	if(left>=right) return 0;//base case
	int p=(left+right)/2;
	mergeSort(r,a,left,p,temp);
	mergeSort(r,a,p+1,right,temp);
	int i,t,j;
	i=left;
	j=p+1;
	t=0;
	while(i<=p&&j<=right){
		if(strcmp(a[r[i]],a[r[j]])<0){
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
	return 0;
}