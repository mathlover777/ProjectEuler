#include <stdio.h>
#include <stdlib.h>
int getPrimeHash(int *p,int n){
	int j,i,sum=0,m;
	for(i=1;i<n;i++){
		p[i]=0;
	}
	p[0]=1;
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
	int n,i;
	scanf("%d",&n);
	int p[n];
	getPrimeHash(p,n);
	// for(i=0;i<n;i++){
	// 	printf("\n%d >> %d",i+1,p[i]);
	// }
	int count=0,t,l;
	int dlist[10],list[10];
	long long int sum=0,tpow[10],tsum;
	tpow[0]=1;
	for(i=1;i<=9;i++){
		tpow[i]=10*tpow[i-1];
	}
	int k;
	int pflag;
	for(i=11;i<=n;i++){
		t=i;
		l=0;
		while(t!=0){
			list[l]=(t%10);
			dlist[l]=list[l]*tpow[l];
			t=t/10;
			l++;
		}


		pflag=1;

		t=0;
		tsum=0;
		while(t<l){
			tsum=tsum+dlist[t];
			if(p[tsum-1]==1){
				pflag=0;
				break;
			}
			t++;
		}
		if(pflag==0){
			continue;
		}


		t=0;
		tsum=0;
		while(t<l){
			tsum=tsum*10+list[l-t-1];
			if(p[tsum-1]==1){
				pflag=0;
				break;
			}
			t++;
		}
		if(pflag==1){
			printf("\n%d >>> **** %llu ****",count+1,tsum);
			sum=sum+tsum;
			count++;
		}
	}
	printf("\nANS = %llu\n",sum);

}