#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,j;
	unsigned long long int x,sum;
	sum=0;
	for(i=1;i<=1000;i++){
		x=1;
		for(j=1;j<=i;j++){
			x=(x*i)%10000000000;
		}
		sum=(sum+x)%10000000000;
	}
	printf("\nANS  = %llu\n",sum);
}