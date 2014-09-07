#include <stdio.h>
#include <stdlib.h>
int main(){
	int *n,*x,d;
	n=(int *)malloc(sizeof(int)*2000);
	x=(int *)malloc(sizeof(int)*2000);
	int lenn,lenx;
	n[0]=1;
	x[0]=1;
	lenn=1;
	lenx=1;
	int i;
	for(i=1;i<=1999;i++){
		n[i]=0;
		x[i]=0;
	}
	i=1;
	int carry,max,temp,*t;
	scanf("%d",&d);
	printf("\n1\n1");
	int term=2;
	while(1){
		carry=0;
		for(i=0;i<lenx;i++){
			temp=n[i]+x[i]+carry;
			n[i]=temp%10;
			carry=temp/10;
		}
		lenn=lenx;
		while(carry!=0){
			n[i]=carry%10;
			carry=carry/2;
			lenn++;
		}
		term++;
		if(lenn==d){
			printf("\n%d >> ",term);
			for(i=0;i<lenn;i++){
				printf("%d",n[lenn-i-1]);
			}
			break;
		}
		temp=lenn;
		lenn=lenx;
		lenx=temp;

		t=n;
		n=x;
		x=t;
		
	}
}