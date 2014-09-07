#include <stdio.h>
#include <stdlib.h>
#include "Queue.cpp"
#include "node.cpp"
#include "Graph.cpp"




int main(){
	int n,i,j,cost,size;
	printf("\nEnter Graph Size : ");
	scanf("%d",&size);

	Graph g(size);
	n=1;
	while(n!=0){
		printf("\nEnter 0 to exit :");
		printf("\nEnter 1 to add :");
		

		printf("\n");
		scanf("%d",&n);

		switch(n){
			case 0:{
				break;
			}
			case 1:{
				printf("\nEnter node 1 : ");
				scanf("%d",&i);
				printf("\nEnter node 2 : ");
				scanf("%d",&j);
				cost=0;
				g.addLink(i,j,cost);
			}
		}

		g.print();

	}
	return 0;
}