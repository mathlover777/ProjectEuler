#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	long int a;
	scanf("%ld",&a);
	long int b=(int)sqrt(a);
	long int i;
	for(i=3;i<=b;i++){
		if(a%i==0){
			a=a/i;
			b=sqrt(a);	
		}
	}
	printf("\n%ld\n",a);
}