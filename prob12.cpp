#include <stdio.h>
#include <stdlib.h>
int finddiv(int n){
	int i,p,s,d;
	p=1;
	for(i=2;i<=n;i++){
		s=0;
		if(n%i==0){
			d=i;
			while(n%d==0){
				s++;
				n=n/d;
			}
			p=p*(s+1);
		}
	}
	return p;
}
int main(){
	int n;
	//scanf("%d",&n);
	while(1){
		if(finddiv((n*(n+1))/2)>500){
			break;
		}
		n++;
	}
	printf("\nn= %d ans = %d",n,n*(n+1)/2);
}