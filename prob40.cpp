#include <stdio.h>
#include <stdlib.h>
int getDigit(int n,int l){
	// -1 is returned if number is not sufficiently large
	// the right most digit is taken as the 1st digit --- for l = 1
	int i=1;
	while(n!=0){
		if(i==l){
			return n%10;
		}
		i++;
		n=n/10;
	}
}
int main(){
	int d;
	int i,n,m,l,len;
	scanf("%d",&d);
	m=10;//initial number just above the current digit length
	i=1;//the initial number
	l=1;//initial limit
	len=0;
	while(1){
		if(i>=m){
			//limits will be changed now
			m=m*10;
			l++;
		}
		if((len+l)>=d){
			//our range is found !!!
			printf("\nANS  = %d\n",getDigit(i,len+l-d+1));
			break;
		}
		len=len+l;
		i++;
	}
	return 0;
}