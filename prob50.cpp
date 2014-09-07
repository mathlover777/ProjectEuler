#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getPrimeHash(int *p,int n,int *a){
	int j,i,sum=0,m;
	for(i=0;i<n;i++){
		p[i]=0;
	}
	p[1]=0;
	p[0]=1;
	for(i=1;i<=n-1;i++){
		if(p[i]==1){
			continue;
		}
		m=i+1;
		a[sum]=(i+1);
		//printf("\n%d>> %d ",sum+1,n);
		sum++;
		for(j=i+m;j<n;j=j+m){
			p[j]=1;
		}
	}
	printf("\ntotal pirmes = %d \n",sum);
	return sum;
}
int isPrime(int *p,int n,int *a,int c,int x){
	if(x<=n){
		//x is in moderate range we can directly use hash table
		if(p[x-1]==0){
			return 1;
		}else{
			return 0;
		}
	}
	//x is in out of range we have to use brute force
	int i;
	int m=(int)sqrt(x);
	for(i=0;i<c;i++){
		if(a[i]>m){
			//x is a prime !!!!!!!!!!
			return 1;
		}
		if(x%a[i]==0){
			//x is not prime !!!!!!!
			return 0;
		}
	}
	printf("\nThis was not supposed to happen !!");
	exit(0);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],p[n];
	int c=getPrimeHash(p,n,a);
	int test;
	// while(1){
	// 	scanf("%d",&test);
	// 	printf("\nPrime status : %d\n",isPrime(p,n,a,c,test));
	// }
	int i,j,maxl,l,imax,jmax;
	long long int table[c][c];
	for(i=0;i<c;i++){
		table[i][i]=a[i];//table[i][i] contains the sum from the ith prime to the ith prime
	}
	maxl=0;
	for(i=0;i<c;i++){
		for(j=i+1;j<c;j++){
			table[i][j]=table[i][j-1]+a[j];
			if(isPrime(p,n,a,c,table[i][j])==1){
				//we got a prime
				l=j-i+1;
				if(l>maxl){
					maxl=l;
					imax=i;
					jmax=j;
				}
			}
		}
	}
	printf("\nMAX fo table[%d][%d] = %llu",imax,jmax,table[imax][jmax]);
}