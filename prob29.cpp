#include <stdio.h>
#include <stdlib.h>
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
int getDivisors(int n,int *p,int *a){
	//p is the list of primes
	//no bound check is ever made
	//a must be set to 0
	int i=0,r;
	while(n!=1){
		//printf("\nTrapped !!! n = %d p =%d ",n,p[i]);
		r=n%p[i];
		if(r==0){
			n=n/p[i];
			a[i]++;
		}else{
			i++;
		}
	}
	return 0;
}

int main(){
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	int p[a-1],x[a-1];
	c=getPrimeHash(p,a,x);
	int i,j;
	for(i=0;i<=c-1;i++){
		printf("\n%d",x[i]);
	}

	// for(i=0;i<c;i++){
	// 	d[i]=0;
	// }
	// getDivisors(49000,x,d);
	// for(i=0;i<c;i++){
	// 	printf("\n%d >>> %d",i+1,d[i]);
	// }
	int list[(a-1)*(b-1)][c],d[c];
	for(i=0;i<(a-1)*(b-1);i++){
		for(j=0;j<c;j++){
			list[i][j]=0;
		}
	}
	int count=0,acount=0,l,k,newflag,flag;
	for(i=2;i<=a;i++){
		for(l=0;l<c;l++){
			d[l]=0;
		}
		getDivisors(i,x,d);
		for(j=2;j<=b;j++){
			//printf("\n********* a = %d b = %d ********",i,j);
			for(l=0;l<c;l++){
				//printf("\n%d >>> %d",x[l],d[l]*j);
				list[count][l]=d[l]*j;
			}
			flag=0;
			for(l=0;l<count;l++){
				newflag=0;
				for(k=0;k<c;k++){
					if(list[l][k]!=list[count][k]){
						newflag=1;
						break;
					}
				}
				if(newflag==0){
					//old number!!!
					flag=1;
					break; 
				}
			}
			if(flag==0){
				acount++;
			}
			count++;
		}
	}
	printf("\n ANS = %d \n",acount);
}