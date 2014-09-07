//even ones 9*10*10+9*10+9
//ood ones 9+9*10+9*10*10
#include <stdio.h>
#include <stdlib.h>

int isBinPal(int n,int *temp){
	int len=0;
	while(n!=0){
		if(n%2==0){
			temp[len]=0;
		}else{
			temp[len]=1;
		}
		n=n/2;
		len++;
	}
	int i,pflag=1;
	for(i=0;i<len/2;i++){
		if(temp[i]!=temp[len-i-1]){
			pflag=0;
			break;
		}
	}
	if(pflag==1) return 1;
	else return 0;
}



int main(){
	int i,j,k;
	//for even palindromes in decimal

	int temp[20];//as 19<log(1000000)/log(2)<19.96

	//5-6 length
	int n;
	long long int sum=0;
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			for(k=0;k<=9;k++){
				//for odd case
				n=i*10000+j*1000+k*100+j*10+i;
				if(isBinPal(n,temp)){
					sum=sum+n;
				}
				//for even case
				n=i*100000+j*10000+k*1000+k*100+j*10+i;
				if(isBinPal(n,temp)){
					sum=sum+n;
				}

			}
		}
	}


	//3-4 lenght
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			//for odd case
			n=i*100+j*10+i;
			if(isBinPal(n,temp)){
				sum=sum+n;
			}

			//for even case
			n=i*1000+j*100+j*10+i;
			if(isBinPal(n,temp)){
				sum=sum+n;
			}

		}
	}


	//for 1-2 length
	for(i=1;i<=9;i++){
		n=i;
		if(isBinPal(n,temp)){
			sum=sum+n;
		}

		//for even case
		n=i*10+i;
		if(isBinPal(n,temp)){
			sum=sum+n;
		}
	}
	printf("\nANS = %llu\n",sum);
}