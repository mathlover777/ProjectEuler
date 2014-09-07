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
int isPermutation(int a,int b){
	int d[10],x[10];
	int i;
	for(i=0;i<10;i++){
		d[i]=0;
		x[i]=0;
	}
	while(a!=0){
		d[a%10-1]++;
		a=a/10;
	}
	while(b!=0){
		x[b%10-1]++;
		b=b/10;
	}
	for(i=0;i<10;i++){
		if(d[i]!=x[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int p[10000],a[10000];
	int c=getPrimeHash(p,10000,a);
	int i=0;
	while(1){
		//printf("\na[%d] = %d",i,a[i]);
		if(a[i]>1000){
			break;
		}
		i++;
	}
	//printf("\na[i] = %d \n",a[i]);
	int j,x,y;
	while(i<c){
		//printf("\ni = %d\n",i);
		j=2;
		while((a[i]+2*j)<10000){
			x=a[i]+j;
			y=a[i]+2*j;
			if(isPermutation(a[i],x)==1&&isPermutation(a[i],y)==1){
				if((p[x-1]==0)&&(p[y-1]==0)){
					printf("\n%d %d %d ANS = %d%d%d",a[i],x,y,a[i],x,y);
				}
			}
			j=j+2;
		}
		i++;
	}
}