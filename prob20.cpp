#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){
	int i,sum=1,dsum=0;
	for(i=1;i<=100;i++){
		sum=sum+log(i);
	}
	printf("\nTotal number of digits = %d\n",sum);
	int n[330];
	n[0]=1;
	for(i=1;i<=329;i++){
		n[i]=0;
	}
	int x;
	scanf("%d",&x);
	clock_t begin, end;
	begin = clock();
	int carry=0,j,temp,len=1;
	for(i=2;i<=x;i++){
		for(j=0;j<=len-1;j++){
			temp=n[j]*i+carry;
			n[j]=temp%10;
			carry=temp/10;
		}
		if(carry!=0){
			//length of number is not changed
			if(j!=len){
				printf("\nConcept Error !!!");
				exit(0);
			}
			while(carry!=0){
				len++;
				n[j]=carry%10;
				carry=carry/10;
				j++;
			}
		}
		// //printf("\n%d! = ",i);
		// for(j=len-1;j>=0;j--){
		// 	//printf("%d",n[j]);
		// }
	}
	for(i=0;i<=len-1;i++){
		dsum=dsum+n[i];
	}
	end = clock();
	printf("\nANS = %d \n",dsum);
	printf("\nTime spent = %lf\n\n",(double)(end - begin) / CLOCKS_PER_SEC);
}