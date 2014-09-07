#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isTriangle(int n){
	int d,s;
	s=1+8*n;
	d=sqrt(s);
	if(d*d!=s){
		return 0;
	}
	if((d-1)%2==0){
		return (d-1)/2;
	}
}
int val(char *w){
	int sum=0;
	while(*w!='\0'){
		sum=sum+(*w)-64;
		w++;
	}
	return sum;
}
int main(){
	int n,i,count=0;
	char word[20];
	FILE *f=fopen("in42.txt","r");
	for(i=1;i<=1786;i++){
		fscanf(f,"%s",word);
		printf("\n%s",word);
		if(isTriangle(val(word))!=0){
			count++;
		}
	}
	printf("\nANS = %d\n",count);
}