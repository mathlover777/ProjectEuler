#include <stdio.h>
#include <stdlib.h>
int get5power(int a){
	return a*a*a*a*a;
}
int main(){
	int digit[10];
	int i;
	for(i=0;i<=9;i++){
		//printf("\ntrapped !!!");
		digit[i]=get5power(i);
	}
	int n,temp;
	long long int sum,xsum=0;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		//printf("\ni = %d]n",i);
		sum=0;
		temp=i;
		while(temp!=0){
			sum=sum+digit[temp%10];
			temp=temp/10;
		}
		if(sum==i){
			printf("\n%d",i);
			xsum=xsum+sum;
			//exit(0);
		}
	}
	printf("\n ANS = %llu\n",xsum);
}