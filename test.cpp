#include <stdio.h>
#include <stdlib.h>
int main(){
	int t,m=10,i,x;
	int a[10];
	printf("\n");
	for(i=0;i<=9;i++){
		a[i]=rand()%100+100;
		printf(" %d ",a[i]);
	}
	printf("\n");
	int j;
	scanf("%d",&j);
	j++;
	int n;
	n=j;
	
	//int b=j;
	t=0;
	while(1){
		//printf("\nj = %d t= %d",j,t);
		t=m-j+n-1;
		//printf("\nj = %d t= %d",j,t);
		if(j>t){
			break;
		}
		x=a[j];
		//printf("\nX= %d a[t]=%d",x,a[t]);
		a[j]=a[t];
		//printf("\na[j]= %d",a[j]);
		//printf("\n**j = %d t= %d",b,t);
		a[t]=x;
		//printf("\n*a[t]=%d j = %d t= %d",a[t],j,t);
		j++;
	}
	printf("\n");
	for(i=0;i<=9;i++){
		printf(" %d ",a[i]);
	}
}