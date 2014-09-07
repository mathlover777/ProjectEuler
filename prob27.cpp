#include <stdio.h>
#include <stdlib.h>
int getPrimeHash(int *p,int n){
	int j,i,sum=0,m;
	for(i=0;i<n;i++){
		p[i]=0;
	}
	p[1]=0;
	for(i=1;i<=n-1;i++){
		if(p[i]==1){
			continue;
		}
		m=i+1;
		//printf("\n%d>> %d ",sum+1,n);
		sum++;
		for(j=i+m;j<n;j=j+m){
			p[j]=1;
		}
	}
	printf("\ntotal pirmes = %d \n",sum);
	return sum;
}
int main(){
	int a;
	int b,i,j,k;
	int p[999999];
	int hash;
	//scanf("%d",&hash);
	getPrimeHash(p,1000000);
	// for(i=0;i<hash;i++){
	// 	printf("\n %d >> n= %d hash = %d ",i,i+1,p[i]);
	// }
	scanf("%d",&a);
	scanf("%d",&b);
	int s[1000];
	for(i=0;i<=999;i++){
		s[i]=(i+1)*(i+1);
	}
	int sum,pcount;
	int maxP=0,maxab,A=0,B=0;
	for(i=-a;i<=a;i++){
		for(j=-b;j<=b;j++){
			//printf("\na = %d\t b = %d {",i,j);
			pcount=0;
			for(k=0;k<j;k++){
				if(k!=0){
					sum=s[k-1]+k*i+j;
				}else{
					sum=j;
				}
				//printf("\nsum = %d ",sum);
				if(sum==0){
					break;
				}
				if(sum<0){
					sum=sum*(-1);
				}
				if(p[sum-1]==0){
					//printf(" %d ",sum);
					//we got a prime number !!!!
					pcount++;
				}
				else{
					break;
				}
			}
			//printf("} pcount = %d ",pcount);
			if(maxP<pcount){
				//printf("\nMaxp = %d ",maxP);
				maxP=pcount;
				A=i;
				B=j;
				//printf("A = %d B =%d",A,B);
				maxab=A*B;
			}
		}
	}
	printf("\nmaxP = %d A = %d B = %d AB = %d\n",maxP,A,B,maxab);
}