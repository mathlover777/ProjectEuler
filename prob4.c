#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int a,b,c,n,d,i;
	for(a=9;a>=1;a--){
		for(b=9;b>=0;b--){
			for(c=9;c>=0;c--){
				n=100000*a+10000*b+1000*c+100*c+10*b+a;
				for(i=100;i<1000;i++){
					if(n%i==0){
						if(n/i<1000){
							printf("\nLucky !!! %d*%d=%d\n",i,n/i,n);
							exit(0);
						}
					}
				}
			}
		}
	}
}