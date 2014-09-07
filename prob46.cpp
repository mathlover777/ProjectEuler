#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getPrimeHash(int *p,int n,int *a){
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
int main(){
	int n,i;
	scanf("%d",&n);
	int p[n],a[n];//p is the list of primes and and a is the hash
	int c=getPrimeHash(a,n,p);
	int flag=1;
	int sum,j,s;
	for(i=9;i<=n;i=i+2){
		j=1;
		while(1){
			sum=(i-p[j])/2;
			if(sum<0){
				//we have it !!!!!!!!!!
				printf("\nANS = %d\n",i);
				flag=0;
				break;
			}
			s=sqrt(sum);
			if(s*s==sum){
				printf("\n%d = %d + 2*(%d)^2",i,p[j],s);
				break;
			}
			j++;
		}
		if(flag==0){
			break;
		}
	}
}