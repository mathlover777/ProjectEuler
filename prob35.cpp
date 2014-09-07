#include <stdio.h>
#include <stdlib.h>
int getPrimeHash(int *p,int n){
	int j,i,sum=0,m;
	p[0]=1;
	for(i=1;i<n;i++){
		p[i]=0;
	}
	p[1]=0;
	for(i=1;i<=n-1;i++){
		if(p[i]==1){
			continue;
		}
		m=i+1;
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
	int n,i,m;
	scanf("%d",&m);
	int p[m];
	int c=getPrimeHash(p,m);
	// for(i=0;i<n;i++){
	// 	printf("\n%d >> %d",i+1,p[i]);
	// }
	int l,d[6],nnext,t,pflag;
	d[0]=1;
	for(i=1;i<6;i++){
		d[i]=10*d[i-1];
	}
	int count=0;
	for(i=2;i<=m;i++){
		n=i;
		l=0;
		while(n!=0){
			n=n/10;
			l++;
		}
		n=i;
		t=l;
		pflag=1;
		//printf("\nSTARTING check ***************** n = %d ",i);
		while(t>0){
			//printf("\nN = %d",n);
			if(p[n-1]==1){
				pflag=0;
				break;
			}
			nnext=n/10;
			nnext=d[l-1]*(n%10)+nnext;
			n=nnext;
			t--;
		}
		if(pflag==1){
			//we have a circular prime
			printf("\n**** %d ****",i);
			count++;
		}
	}
	printf("\n ANS = %d ",count);
}