#include <stdio.h>
#include <stdlib.h>
int main(){
	int a=1,b=2,temp;
	int sum=0;
	while(b<=4000000){
		sum=sum+b;
		temp=2*a+3*b;
		a=a+2*b;
		b=temp;
	}
	printf("\n%d\n",sum);
}