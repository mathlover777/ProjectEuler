#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getPrimeHash(int *p,int n,int *a){
	int j,i,sum=0,m;
	for(i=0;i<n;i++){
		p[i]=1;
	}
	p[1]=1;
	p[0]=0;
	for(i=1;i<=n-1;i++){
		if(p[i]==0){
			continue;
		}
		m=i+1;
		a[sum]=(i+1);
		p[i]=sum+1;
		//printf("\n%d>> %d ",sum+1,n);
		sum++;
		for(j=i+m;j<n;j=j+m){
			p[j]=0;
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
int check(int *p,int n,int *a,int x,int size,int *sol){

}

int select(int *p,int n,int *a,int x,int t,int level,int *sol,int size){
	// t is the remaining
	// size is the total size of the solution array
	// sol is the solution array
	// level is the current stage ,,, for initial stage it is 0 and for final stage it is size-1 
	if((size-level)<t){
		//no solution is possible in that case
		return 0;
	}
	int i;
	//solution is still possible
	if((size-level)==t){
		// we have to take all !!!
		// also accounts for the base case if needed 
		for(i=level;i<=size-1;i++){
			sol[i]=1;
		}
		if(check(p,n,a,x,size,sol)==1){
			//we got our solution !!!
			return 1;
		}
	}

	// the recursion
	sol[level]=0;	//case 1 we dont take anything
	if(select(p,n,a,x,t,level+1,sol,size)==1){
		return 1;
	}
	sol[level]=1;	//case 2 we take 1(CHOOSE)
	if(select(p,n,a,x,t-1,level+1,sol,size)==1){
		return 1;
	}
	//we have not found any solution !!!!!
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	int p[n],a[n];
	int c=getPrimeHash(p,n,a);
	// for(i=0;i<c;i++){
	// 	printf("\n%d >> %d",i+1,a[i]);
	// }
	// for(i=0;i<n;i++){
	// 	printf("\n%d >>> p[%d] = %d",i+1,i,p[i]);
	// }
	int s,i;
	scanf("%d",&s);
	while(p[s-1]==0){
		s++;
	}
	//we have taken the prime number just >= s
	while(1){

	}
	return 0;
}