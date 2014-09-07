//checking upto 7 digit numbers suffies
#include <stdlib.h>
#include <stdio.h>
int main(){
	int f[10];
	int i;
	f[0]=1;
	for(i=1;i<=9;i++){
		f[i]=i*f[i-1];
		printf("\n%d! = %d",i,f[i]);
	}
	long long sum=0,tempsum,n;
	for(i=3;i<=9999999;i++){
		tempsum=0;
		n=i;
		while(n!=0){
			tempsum=tempsum+f[n%10];
			n=n/10;
		}
		if(tempsum==i){
			printf("\n ***** %d *****",i);
			sum=sum+tempsum;
		}
	}	
	printf("\nANS  = %llu \n",sum);
}