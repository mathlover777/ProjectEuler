#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b,c,d;
	for(int a=1;a<500;a++){
		for(b=a+1;b<1000;b++){
			c=1000-a-b;
			if(c*c==a*a+b*b){
				printf("\nWe are lucky !!! a = %d b= %d c= %d abc = %d \n",a,b,c,a*b*c);
				exit(0);
			}
		}
	}
}