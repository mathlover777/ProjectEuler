#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	unsigned long long int n,d,s,x,y,l,m,t,r,i,j;
	scanf("%llu",&n);
	int found=0;
	for(i=1;i<=n;i++){
		x=(i*(3*i-1))/2;
		for(j=i-1;j>=1;j--){
			y=(j*(3*j-1))/2;
			// if((i+j)%600==0){
			// 	printf("\nx = %llu_%llu\ty=%llu_%llu",x,i,y,j);
			// }
			
			/*******************Checking for difference**********************/
			d=x-y;
			r=(unsigned long long int)sqrt(1+24*d);
			if((r*r)!=(1+24*d)){
				found=0;
				continue;
			}
			//printf("\n%llu = %llu",r*r,1+24*d);
			//printf("\nx = %llu_%llu\ty=%llu_%llu",x,i,y,j);
			if((r+1)%6==0){
				m=(r+1)/6;
			}else{
				found=0;
				continue;
			}

			/***************Checking for sum*******************************/
			s=x+y;
			t=(unsigned long long int)sqrt(1+24*s);
			if((t*t)!=(1+24*s)){
				found=0;
				continue;
			}
			//printf("\n%llu = %llu",t*t,1+24*s);
			if((t+1)%6==0){
				l=(t+1)/6;
			}else{
				found=0;
				continue;
			}

			/*******************Sum and difference are both triangular***********/
			printf("\nWe found it actiually !!");
			found=1;
			break;
		}
		if(found==1){
			printf("\n*************p(%llu) = %llu\tp(%llu) = %llu",i,x,j,y);
			printf("\nx-y = %llu = p(%llu)\tx+y = %llu = p(%llu)\n",d,m,s,l);
			printf("\n1+24*s = %llu t*t = %llu t = %llu",1+24*s,t*t,t);
			printf("\n1+24*d = %llu r*r = %llu r = %llu",1+24*d,r*r,r);
			printf("\n");
			break;
		}
	}

}
