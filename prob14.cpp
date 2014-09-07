#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int findColz(int i,int *a);
int directFind(long long int n,int *a);
int main(){
	int m;
	scanf("%d",&m);
	clock_t begin, end;
	begin = clock();
	int a[1000000],i;
	a[0]=1;
	int max=0,mid=0;
	for(i=1;i<999999;i++){
		a[i]=0;
	}
	for(i=1;i<=m-2;i++){
		if(a[i]==0){
			a[i]=findColz(i+1,a);
		}
		if(max<a[i]){
			max=a[i];
			mid=i+1;
		}
	//	printf("\na[%d] = %d\n",i+1,a[i]);
	}
	end = clock();
	printf("\n ANS = %d --- length = %d \n",mid,a[mid-1]);
	printf("\nTime spent = %lf\n\n",(double)(end - begin) / CLOCKS_PER_SEC);
}
int findColz(int n,int *a){
	//printf("\n n =%d\n",n);
	if(a[n-1]==0){
		if(n%2==0){
			return findColz(n/2,a)+1;
		}else{
			if(3*n+1<1000000){
				return findColz(3*n+1,a)+1;
			}else{
				return directFind(3*n+1,a)+1;
			}
		}
	}
	return a[n-1];
}
int directFind(long long int n,int *a){
	//printf("\n** n =%llud\n",n);
	if(n%2==0&&n/2<1000000){
		return findColz((int)(n/2),a)+1;
	}
	if(n%2==0&&n/2>=1000000){
		return directFind(n/2,a)+1;
	}
	return directFind(3*n+1,a)+1;
}