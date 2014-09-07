#include <stdio.h>
#include <stdlib.h>
int checkProperty(int *n){
	int x;
	x=n[1]*100+n[2]*10+n[3];
	if(x%2!=0){
		return 0;
	}
	x=n[2]*100+n[3]*10+n[4];
	if(x%3!=0){
		return 0;
	}
	x=n[3]*100+n[4]*10+n[5];
	if(x%5!=0){
		return 0;
	}
	x=n[4]*100+n[5]*10+n[6];
	if(x%7!=0){
		return 0;
	}
	x=n[5]*100+n[6]*10+n[7];
	if(x%11!=0){
		return 0;
	}
	x=n[6]*100+n[7]*10+n[8];
	if(x%13!=0){
		return 0;
	}
	x=n[7]*100+n[8]*10+n[9];
	if(x%17!=0){
		return 0;
	}
	return 1;
}
int givePermutation(int *n,int m,int level,long long int *sum){
	int t,i;
	long long int v=0;
	if(checkProperty(n)==1){
		//number satisfies the given property
		for(i=0;i<m;i++){
			v=v*10+n[i];
		}
		printf("{ %llu }\n",v);
		(*sum)=(*sum)+v;
	}
	return 0;
}
int permute(int *n,int m,int level,long long int *sum){
	int xcount=0;
	//printf("\nlevel = %d",level);
	//printf("Count = %d ",*count);
	if(level==m){
		givePermutation(n,m,level,sum);
		return 0;
	}
	int i,j,t,x;
	// for(i=0;i<m-level;i++){
	// 	hold[i]=n[level+i];
	// }
	for(i=0;i<=m-level;i++){
		// for(j=0;j<=m-level-1;j++){
		// 	n[level+j]=hold[j];
		// }
		permute(n,m,level+1,sum);
		if((level+i)>=m){
			break;
		}
		//reverse the rest except the 1st element
		//if(level==1){
			// printf("\nBefore revering");
			// for(int k=0;k<level;k++){
			// 	printf("*");
			// }
			// printPer(n,m,&xcount,level);
		//}
		j=level;
		while(1){
			t=m-j+level-1;
			if(j>t){
				break;
			}
			x=n[j];
			n[j]=n[t];
			n[t]=x;
			j++;
		}
		//if(level==1){
			// printf("\nAfter Reversing");
			// for(int k=0;k<level;k++){
			// 	printf("*");
			// }
			// printPer(n,m,&xcount,level);
		//}
		//after reversing exchange the next 2 elements as described
		//it can be showen that after that all the elements starting from level ... m-1["current" element is at level-1]
		//will be lexicographially smallest ,.. so each time after this we are in a same situation where we need to permute
		//a set of less than size 1 and given in "decreasing to increasing order" ... and as the changes actually does not depend
		//on the values of n[i] so if initially they are in dec to inc then the recursion invariant holds !!!!!!!!!
		//24-01-2013
		t=n[level-1];
		n[level-1]=n[level+i];
		n[level+i]=t;
		
	}
	return 0;
}
int main(){
	int n[10];
	int i;
	for(i=0;i<10;i++){
		n[i]=i;
	}
	long long int sum=0;
	permute(n,10,1,&sum);
	printf("\nANS = %llu\n",sum);
	return 0;
}