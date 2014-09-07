#include <stdio.h>
#include <stdlib.h>
int main(){
	int d1,d2,b1,b2;
	int a,b;
	for(a=10;a<=99;a++){
		for(b=a+1;b<=99;b++){
			//printf("\n************a = %d b= %d ",a,b);
			d1=a%10;
			d2=(a-d1)/10;
			b1=b%10;
			b2=(b-b1)/10;
			if(d1!=0&&b1!=0){
				//removing the trivial cases
				if((a*b1==b*d1&&b2==d2)||(a*b1==b*d2&&b2==d1)||(a*b2==b*d1&&b1==d2)||(a*b2==b*d2&&b1==d1)){
					//we got lucky
					printf("\n%d/%d",a,b);
				}
			}
		}
	}
	return 0;
}