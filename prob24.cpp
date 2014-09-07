#include <stdio.h>
#include <stdlib.h>
int permute(int *n,int m,int level,int *count);
int printPer(int *n,int m,int *count,int level);
int main(){
	int n[10];
	int i,m;
	scanf("%d",&m);
	for(i=0;i<=m-1;i++){
		n[i]=i;
	}
	int count=0;
	permute(n,m,1,&count);
	printf("\n");
}
int printPer(int *n,int m,int *count,int level){
	(*count)++;
	//printf("level = %d %d >> \t{ ",level,*count);
	printf("%d >> \t{ ",*count);
	for(int i=0;i<m;i++){
		printf(" %d ",n[i]);
	}
	printf(" }");
	return 0;
}
int permute(int *n,int m,int level,int *count){
	int xcount=0;
	//printf("\nlevel = %d",level);
	//printf("Count = %d ",*count);
	if(level==m){
		if(*(count)==999999){
			printf("\n");
			// for(int k=0;k<level;k++){
			// 	printf("*");
			// }
			printPer(n,m,count,level);
		}else{
			(*count)++;
		}
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
		permute(n,m,level+1,count);
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