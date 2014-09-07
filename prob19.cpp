#include <stdio.h>
#include <stdlib.h>
int main(){
	//N = 1 + 2*13 + (int)(3(13+1)/5) + y + (int)(y/4) - (int)(y/100) + (int)(y/400) + 2
	int n,y,sum=0,y1,y2,i;
	scanf("%d",&y1);
	scanf("%d",&y2);
	for(y=y1;y<=y2;y++){
		n=1 + 2*13 + ((int)(3*(13+1)/5)) + y-1 + (int)((y-1)/4) - (int)((y-1)/100) + (int)((y-1)/400) + 2;
		if(n%7==1) sum++;
		n=1 + 2*14 + (int)(3*(14+1)/5) + y-1 + (int)((y-1)/4) - (int)((y-1)/100) + (int)((y-1)/400) + 2;
		if(n%7==1) sum++;
		for(i=3;i<=12;i++){
			n=1 + 2*i + (int)(3*(i+1)/5) + y+ (int)((y)/4) - (int)((y)/100) + (int)((y)/400) + 2;
			if(n%7==1) sum++;
		}
	}

	printf("\nANS = %d \n",sum);
}