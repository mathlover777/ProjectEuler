#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	long long int sum=1,tsum=1;
	int k=1;
	for(int i=1;i<=(n-1)/2;i++){
		sum=sum+k*2;
		tsum=tsum+sum;
		if(tsum<=0){
			printf("ERROR");
			exit(0);
		}
		printf("\nsum = %llu",sum);
		sum=sum+k*2;
		tsum=tsum+sum;
		if(tsum<=0){
			printf("ERROR");
			exit(0);
		}
		printf("\nTsum = %llu",sum);
		sum=sum+k*2;
		tsum=tsum+sum;
		if(tsum<=0){
			printf("ERROR");
			exit(0);
		}
		printf("\nTsum = %llu",sum);
		sum=sum+k*2;
		tsum=tsum+sum;
		if(tsum<=0){
			printf("ERROR");
			exit(0);
		}
		printf("\nTsum = %llu",sum);
		k++;
	}
	printf("\nsum = %llu ",tsum);
}