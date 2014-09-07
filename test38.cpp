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
// int isPandigital(int *n,int *size,int j){
// 	int d[size],i,t;
// 	for(i=0;i<size;i++){
// 		d[i]=0;
// 	}
// 	i=0;
// 	while(n!=0){
// 		t=n%10;
// 		if(t>size){
// 			//number is not pandigital of size "size"
// 			return 0;
// 		}
// 		if(d[t-1]==1){
// 			return 0;
// 		}else{
// 			d[t-1]=1;
// 		}
// 		n=n/10;
// 	}
// 	return 1;
// }
int getSize(long long int n){
	int t=0;
	while(n!=0){
		n=n/10;
		t++;
	}
	return t;
}
long long int giveNum(int *n,int *size,int k){
	int i;
	long long int x=0;
	printf("\nK= %d",k);
	for(i=0;i<k-1;i++){
		while(size[i]!=0){
			size[i]--;
			x=x*10;
		}
		printf("\nn[i]=%d",n[i]);
		x=x+n[i];
	}
	return x;
}
int main(){
	long long int x;
	scanf("%llu",&x);
	printf("\nSize = %d",getSize(x));
	printf("\nPan digital status = %d\n",isPandigital(x,getSize(x)));
	return 0;
}