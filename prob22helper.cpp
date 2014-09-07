#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *f,*a;
	f=fopen("names.txt","r");
	a=fopen("prob22.txt","w");
	char c;
	int sum=0,maxsize=0,size;
	size=0;
	while(!feof(f)){
		fscanf(f,"%c",&c);
		if(c=='"'||c=='\n'){
			continue;
		}
		if(c==','){
			sum++;
			fprintf(a,"\n");
			if(maxsize<size){
				maxsize=size;
			}
			size=0;
			continue;
		}
		size++;
		fprintf(a,"%c",c);
	}
	sum++;
	printf("\nTotal names = %d maxLength = %d\n",sum,maxsize);
	fclose(f);
	fclose(a);
}