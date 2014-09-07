#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){
	int a[9999];
	int p[9999];
	int n,j,m,i,sum=0;
	scanf("%d",&m);
	for(i=0;i<9999;i++){
		a[i]=0;
		p[i]=0;
	}
	for(i=0;i<=m-2;i++){
		if(a[i]==1){
			continue;
		}
		n=i+2;
		//printf("\n%d>> %d ",sum+1,n);
		p[sum]=n;
		sum++;
		for(j=i;j<=m-2;j=j+n){
			a[j]=1;
		}
	}
	printf("\ntotal pirmes = %d \n",sum);
	clock_t begin, end;
	begin = clock();
	int d[9999];
	for(i=0;i<9999;i++){
		d[i]=0;
	}
	int sump,prodp=1,temp,dsum=0;
	for(i=2;i<10000;i++){
		j=0;
		n=i;
		prodp=1;
		temp=1;
		sump=1;
		while(n!=0){
			if(n%p[j]==0){
				temp=temp*p[j];
				sump=sump+temp;
				n=n/p[j];
			}else{
				prodp=prodp*sump;
				sump=1;
				temp=1;
				j++;
				if(n==1){
					break;
				}
			}
		}
		d[i-2]=prodp-i;

		//printf("\nd(%d) = %d \n",i,d[i-2]);
		// scanf("%d",&m);
		if(d[i-2]<i){
			if(d[prodp-i-2]==i){
				printf("\nAmicable found !! < %d , %d >\n",prodp-i,i);
				dsum=dsum+prodp;
			}
		}
	}
	end = clock();
	printf("\nANS = %d \n",dsum);
	printf("\nTime spent = %lf\n\n",(double)(end - begin) / CLOCKS_PER_SEC);
}