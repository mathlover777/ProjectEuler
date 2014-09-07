#include <stdio.h>
#include <stdlib.h>
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
int givePrimeDivisor(int *p,int n,int *a,int c,int x,int *d){
	//the prime divisors are stored in the array d...no bound check is done
	int i=0,count=0;
	while(x!=1){
		if(i==c){
			printf("\nWe have ran out of primes !!!\n");
			exit(0);
		}
		if(x%a[i]==0){
			//we have got a prime divisor
			d[count]=a[i];
			count++;
			while(x%a[i]==0){
				x=x/a[i];
			}
		}
		i++;
	}
	return count;
}
int main(){
	int n;
	scanf("%d",&n);
	int p[n],a[n],d[n];
	int c,count;
	c=getPrimeHash(p,n,a);
	// int test;
	// while(1){
	// 	scanf("%d",&test);
	// 	printf("\nDivisor Count = %d ",givePrimeDivisor(p,n,a,c,test,d));
	// }
	int q,w,e,r,i;
	q=1;//initialization for 2,3,4,5
	w=1;
	e=1;
	r=1;
	i=2;
	while(q!=4||w!=4||e!=4||r!=4){
		//our condition is not satisfied !!!
		q=w;
		w=e;
		e=r;
		r=givePrimeDivisor(p,n,a,c,i+4,d);
		i++;
	}
	printf("\nANS = %d\n",i);
}