#include <stdio.h>
#include <stdlib.h>
int getSolCount(int n){
	int a,b,c;
	int count=0;
	for(int a=1;a<=n/3;a++){
		for(b=a+1;b<=(n-a)/2;b++){
			c=n-a-b;
			if(c<=0){
				continue;
			}
			if(c*c==a*a+b*b){
				printf("\n***a =%d b = %d c = %d",a,b,c);
				count++;
			}
		}
	}
	return count;
}
int main(){
	int n;
	scanf("%d",&n);
	int max=0;
	int temp,maxc=0;
	for(int i=3;i<=n;i++){
		temp=getSolCount(i);
		printf("\n%d >>>\t%d",i,temp);
		if(temp>max){
			max=temp;
			maxc=i;
		}
	}
	printf("\nMax = %d solutions for P = %d",max,maxc);
}