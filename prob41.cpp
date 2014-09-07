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
int isPrime(int *p,int n,int *a,int c,long long int x){
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
	printf("\nThis was not supposed to happen !!\n");
	exit(0);
}
int givePermutation(int *n,int m,int level,int *p,int x,int *a,int c){
	int i;
	long long int v=0;
	for(i=0;i<m;i++){
		v=v*10+n[i];
	}
	if(isPrime(p,x,a,c,v)==1){
		//we got the largest prime
		printf("\nANS = %llu\n",v);
		exit(0);
	}
	return 0;
}
int permute(int *n,int m,int level,int *p,int x_,int *a,int c){
	int xcount=0;
	//printf("\nlevel = %d",level);
	//printf("Count = %d ",*count);
	if(level==m){
		givePermutation(n,m,level,p,x_,a,c);
		return 0;
	}
	int i,j,t,x;
	// for(i=0;i<m-level;i++){
	// 	hold[i]=n[level+i];
	// }
	for(i=0;i<=m-level;i++){
		// for(j=0;j<=m-level-1;j++){
		// 	n[level+j]=hold[j];
		// }
		permute(n,m,level+1,p,x_,a,c);
		if((level+i)>=m){
			break;
		}
		//reverse the rest except the 1st element
		//if(level==1){
			// printf("\nBefore revering");
			// for(int k=0;k<level;k++){
			// 	printf("*");
			// }
			// printPer(n,m,&xcount,level);
		//}
		j=level;
		while(1){
			t=m-j+level-1;
			if(j>t){
				break;
			}
			x=n[j];
			n[j]=n[t];
			n[t]=x;
			j++;
		}
		//if(level==1){
			// printf("\nAfter Reversing");
			// for(int k=0;k<level;k++){
			// 	printf("*");
			// }
			// printPer(n,m,&xcount,level);
		//}
		//after reversing exchange the next 2 elements as described
		//it can be showen that after that all the elements starting from level ... m-1["current" element is at level-1]
		//will be lexicographially smallest ,.. so each time after this we are in a same situation where we need to permute
		//a set of less than size 1 and given in "decreasing to increasing order" ... and as the changes actually does not depend
		//on the values of n[i] so if initially they are in dec to inc then the recursion invariant holds !!!!!!!!!
		//24-01-2013
		t=n[level-1];
		n[level-1]=n[level+i];
		n[level+i]=t;
		
	}
	return 0;
}
int main(){
	int l=9,x,c,i;
	scanf("%d",&x);//is the upper limit for prime hashing
	int p[x],a[x];
	c=getPrimeHash(p,x,a);
	while(1){
		int n[l];
		for(i=0;i<l;i++){
			n[l-i-1]=i+1;
		}
		permute(n,l,1,p,x,a,c);
		l--;
	}
}