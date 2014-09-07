#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
// 	int n;
// 	int a,b,c;
// 	scanf("%d",&n);
// 	for(int i=286;i<=n;i++){
// 		a=i*(i+1);
// 		for(int j=166;j<=n;j++){
// 			b=j*(3*j-1);
// 			if(b<a){
// 				continue;
// 			}
// 			if(b>a){
// 				break;
// 			}
// 			for(int k=144;k<=n;k++){
// 				c=2*k*(2*k-1);
// 				if(c<b){
// 					continue;
// 				}
// 				//printf("\n %d %d %d",i*(i+1)/2,a/2,k*(2*k-1));
// 				if(a==b&&b==c){
// 					printf("\nANS = %d\n",a);
// 					exit(0);
// 				}
// 			}
// 		}
// 	}
// }
int main(){
	int n;

	unsigned long long int a,b,c,temp;
	//scanf("%llu",&a);
	scanf("%d",&n);
	for(long long int i=286;i<=n;i++){
		a=(i*(i+1))/2;
		//printf("\n%llu >>> %llu",i,a);
		temp=1+24*a;
		b=sqrt(temp);
		//printf("\tb=%d",b);
		if(b*b!=temp||(b+1)%6!=0){
			continue;
		}
		//printf("\nUPTO HERE !!!");
		temp=1+8*a;
		c=sqrt(temp);
		if(c*c!=temp||(c+1)%4!=0){
			continue;
		}
		printf("\nANS = %llu \n",a);
		break;
	}
}