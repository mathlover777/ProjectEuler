#include <stdio.h>
#include <stdlib.h>
int isPandigital(long long int n,int size){
	int d[size],i,t;
	for(i=0;i<size;i++){
		d[i]=0;
	}
	i=0;
	while(n!=0){
		t=n%10;
		if(t==0){
			return 0;
		}
		if(t>size){
			//number is not pandigital of size "size"
			return 0;
		}
		if(d[t-1]==1){
			return 0;
		}else{
			d[t-1]=1;
		}
		n=n/10;
	}
	return 1;
}
int getSize(long long int n){
	int t=0;
	while(n!=0){
		n=n/10;
		t++;
	}
	return t;
}
unsigned long long int giveNum(int i,int j,int p){
	unsigned long long int n=0;
	n=i;
	int t;
	t=getSize(j);
	while(t!=0){
		t--;
		n=n*10;
	}
	n=n+j;
	t=getSize(p);
	while(t!=0){
		t--;
		n=n*10;
	}
	n=n+p;
	return n;
}
int main(){
	int i,j,p;
	int hash[10000];
	for(i=0;i<10000;i++){
		hash[i]=0;
	}
	unsigned long long int x,sum=0;
	for(i=1;i<=9;i++){
		for(j=1;j<=9999;j++){
			p=i*j;
			x=giveNum(i,j,p);
			if(getSize(x)!=9){
				continue;
			}
			if(isPandigital(x,getSize(x))){
				printf("\n%d * %d = %d",i,j,p);
				if(p>10000){
					printf("\nneed more hashing ,,, upto %d\n",p);
					exit(0);
				}
				if(hash[p-1]==0){
					sum=sum+p;
					hash[p-1]=1;
				}
			}
		}
	}
	for(i=10;i<=99;i++){
		for(j=1;j<=999;j++){
			p=i*j;
			x=giveNum(i,j,p);
			if(getSize(x)!=9){
				continue;
			}
			if(isPandigital(x,getSize(x))==1){
				printf("\n%d * %d = %d",i,j,p);
				if(p>10000){
					printf("\nneed more hashing ,,, upto %d\n",p);
					exit(0);
				}
				if(hash[p-1]==0){
					sum=sum+p;
					hash[p-1]=1;
				}
			}
		}
	}
	printf("\nANS = %llu\n",sum);
}