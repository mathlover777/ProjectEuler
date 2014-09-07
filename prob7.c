#include <stdio.h>
#include <stdlib.h>
int main(){
	int a[1000000];
	int sum=0,n,j,m,i;
	scanf("%d",&m);
	for(i=0;i<999999;i++){
		a[i]=0;
	}
	for(i=0;i<=999999;i++){
		if(a[i]==1){
			continue;
		}
		n=i+2;
		sum++;
		if(sum==m){
			printf("\nWe got lucky !!! = %d \n",n);
			break;
		}
		for(j=i;j<=999999;j=j+n){
			a[j]=1;
		}
	}
}