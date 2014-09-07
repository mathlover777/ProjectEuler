#include <stdio.h>
#include <stdlib.h>
int isPandigital(long long int n,int size){
	int d[size],i,t;
	for(i=0;i<size;i++){
		d[i]=0;
	}
	i=0;
	while(n!=0){
		t=n%10;
		if(t==0){
			return 0;
		}
		if(t>size){
			//number is not pandigital of size "size"
			return 0;
		}
		if(d[t-1]==1){
			return 0;
		}else{
			d[t-1]=1;
		}
		n=n/10;
	}
	return 1;
}
// int isPandigital(int *n,int *size,int j){
// 	int d[size],i,t;
// 	for(i=0;i<size;i++){
// 		d[i]=0;
// 	}
// 	i=0;
// 	while(n!=0){
// 		t=n%10;
// 		if(t>size){
// 			//number is not pandigital of size "size"
// 			return 0;
// 		}
// 		if(d[t-1]==1){
// 			return 0;
// 		}else{
// 			d[t-1]=1;
// 		}
// 		n=n/10;
// 	}
// 	return 1;
// }
int getSize(long long int n){
	int t=0;
	while(n!=0){
		n=n/10;
		t++;
	}
	return t;
}
long long int giveNum(int *n,int *size,int k){
	int i;
	long long int x=0;
	//printf("\nK= %d",k);
	for(i=0;i<k;i++){
		while(size[i]!=0){
			size[i]--;
			x=x*10;
		}
		//printf("\nn[i]=%d",n[i]);
		x=x+n[i];
	}
	return x;
}
int main(){
	int i,j,tsize,t,found;
	int n[9];
	long long int x,max=0;
	int size[9];
	for(i=1;i<=99999;i++){
		tsize=getSize(i);
		size[0]=tsize;
		n[0]=i;
		j=1;
		found=0;
		while(1){
			n[j]=i*(j+1);
			t=getSize(n[j]);
			size[j]=t;
			if((t+tsize)>9){
				//number out of range!!!
				break;
			}
			if((t+tsize)==9){
				//we got a 9 digit number !!!
				found=1;
				j++;
				break;
			}
			tsize=tsize+t;
			j++;
		}
		if(found==1){
			//we have got a 9 digit number and j denotes its number of components
			x=giveNum(n,size,j);
			//printf("\n%llu",x);
			if(isPandigital(x,9)==1){
				printf("\n%d >>> %d >>> %llu",i,j,x);
				if(max<x){
					//we got a new pandigital maxima
					max=x;
					//printf("\n*** max = %llu",max);
				}
			}
		}
	}
	printf("\nANS = %llu \n",max);
}