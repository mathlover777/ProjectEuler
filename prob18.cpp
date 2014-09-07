#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int n=15,d;
	d=(n*(n+1))/2;
	int a[d];
	int b[d],i,j,l,r;
	/*****************Getting the input data**********************/
	FILE *f;
	f=fopen("prob18.txt","r");
	for(i=0;i<=d-1;i++){
		fscanf(f,"%d",&(a[i]));
		printf(" %d ",a[i]);
	}
	fclose(f);
	// printf("\n\n");
	// for(i=0;i<=d-1;i++){
	// 	printf(" %d ",a[i]);
	// }
	// int k=0;
	// f=fopen("help18.txt","w");
	// for(i=1;i<=15;i++){
	// 	for(int j=0;j<=i-1;j++){
	// 		fprintf(f,"%d ",k);
	// 		k++;
	// 	}
	// 	fprintf(f,"\n");
	// }
	// fclose(f);
	printf("\ninput taken !! \n");
	/************************************************************/
	clock_t begin, end;
	begin = clock();
	for(i=d-1;i>=d-n;i--){
		b[i]=a[i];//initialisation
	}
	for(i=n-1;i>=0;i--){
		for(j=0;j<=i-1;j++){
			l=b[(i*(i+1))/2+j];
			r=b[(i*(i+1))/2+j+1];
			if(l>r){
				b[((i-1)*i)/2+j]=a[((i-1)*i)/2+j]+l;
			}else{
				b[((i-1)*i)/2+j]=a[((i-1)*i)/2+j]+r;
			}
			//printf("\n%d >> l = %d r = %d",((i-1)*i)/2+j,(i*(i+1))/2+j,(i*(i+1))/2+j+1);
		}
	}
	end = clock();
	printf("\nANS = %d \n",b[0]);
	printf("\nTime spent = %lf\n\n",(double)(end - begin) / CLOCKS_PER_SEC);
}