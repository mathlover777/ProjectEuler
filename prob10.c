#include <stdio.h>
#include <stdlib.h>
int main(){
	long int sum=0;
	int n,j,m,i,k=0;
	scanf("%d",&m);
	int *a=(int *)malloc(sizeof(int)*(m-1));
	for(i=0;i<m-2;i++){
		a[i]=0;
	}
	for(i=0;i<=m-2;i++){
		if(a[i]==1){
			continue;
		}
		n=i+2;
		if(n>=m){
			break;
		}
		printf("\n%d>>> %d <<<",k+1,n);
		k++;
		sum=sum+n;
		for(j=i;j<=m-2;j=j+n){
			a[j]=1;
		}
	}
	printf("\nANS = %ld\n",sum);
}