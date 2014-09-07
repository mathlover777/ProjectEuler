#include <stdio.h>
#include <stdlib.h>
int main(){
	int d;
	scanf("%d",&d);
	int a[d-1];
	int maxL=0,i,j,n,x,t,len,maxN;
	for(i=1;i<=d-2;i++){
		//1,2,3...998 -- > 2,3,4,....,999
		n=i+1;
		for(j=0;j<d-1;j++){
			a[j]=0;
		}
		x=10;
		t=1;
		a[0]=1;
		//printf("\n1/%d = \t0.",n);
		while(1){
			while(x<n){
				x=x*10;
				//a[x-1]=t;
				t++;
				//printf("0");
			}
			t++;
			//printf("%d",x/n);
			x=x%n;
			if(x==0){
				//finite decimal :{}
				len=t;
				//printf("\nsize = \t%d",t);
				break;
			}
			if(a[x-1]!=0){
				//reccurence found !!!//
				len=t-a[x-1];
				//printf("\nsize = \t%d",len);
				break;
			}
			else{
				a[x-1]=t;
			}
			x=x*10;
		}
		if(maxL<len){
			maxL=len;
			maxN=n;
		}
	}
	printf("\nmaxSize = %d ANS = %d \n",maxL,maxN);
	printf("\n");
}