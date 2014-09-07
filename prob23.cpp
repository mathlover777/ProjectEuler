#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getPrimes(int *p,int n){
	//p will hold the prime numbers <= n [must be passed as an array]
	//n is the upper bound
	//size(p)>=n-2
	//primecount is returned by the function
	//currently implemented by naive Sieve of Erat. 
	int a[n-2];
	int j,i,sum=0,m;
	for(i=0;i<n-2;i++){
		a[i]=0;
		p[i]=0;
	}
	for(i=0;i<=n-2;i++){
		if(a[i]==1){
			continue;
		}
		m=i+2;
		//printf("\n%d>> %d ",sum+1,n);
		p[sum]=m;
		sum++;
		for(j=i;j<=n-2;j=j+m){
			a[j]=1;
		}
	}
	printf("\ntotal pirmes = %d \n",sum);
	return sum;
}
int getSumDivisor(int n,int *p){
	//p is the array of all primes ... no bound check is done
	//only sum of proper divisors is given ... if n is prime then 1 is returned
	int temp=1,sump=1,prodp=1,j=0,x;
	x=n;
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
	return prodp-x;
}
int main(){
	int p[30000];
	int n,sum;
	scanf("%d",&n);
	sum=getPrimes(p,n);
	// for(int i=0;i<=sum-1;i++){
	// 	printf("\n%d >> %d",i+1,p[i]);
	// }
	clock_t begin, end;
	begin = clock();
	
	int a[n],acount,i,j;
	acount=0;
	for(i=0;i<=n-1;i++){
		if(getSumDivisor(i+1,p)>i+1){
			//printf("\nd(%d) = %d",i+1,getSumDivisor(i+1,p));
			a[acount]=i+1;
			printf("\n%d >> %d",acount+1,a[acount]);
			acount++;
		}
	}
	printf("\nTotal abundant numbers in that range = %d ",acount);
	//now the p array will be used for sum check//
	for(i=0;i<30000;i++){
		p[i]=0;//0 denotes desired
	}
	for(i=0;i<acount;i++){
		for(j=i;j<acount;j++){
			if((a[i]+a[j])<=n){
				p[a[i]+a[j]-1]=1;
			}
		}
	}
	sum=0;
	for(i=0;i<n;i++){
		if(p[i]==0){
			//(i+1) cant be expressed as the sum of two abundant numbers !!!
			sum=sum+i+1;
		}
	}


	end = clock();
	printf("\nANS = %d \n",sum);
	printf("\nTime spent = %lf\n\n",(double)(end - begin) / CLOCKS_PER_SEC);
}
