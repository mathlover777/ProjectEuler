#include <stdlib.h>
#include <stdio.h>
#include "Queue.cpp"
#include "Stack.cpp"
#include "HEAP.cpp"
#include "SORT.cpp"

#define INF 9999999
#define STAR printf("\n******************************\n");
using namespace std;
class tree_node{
	public:
	int id;
	int size;
	tree_node *parent;
};
class MFSet{
	public:
	tree_node **header;
	MFSet(int n){
		header=new tree_node*[n];
		for(int i=0;i<n;i++){
			header[i]=new tree_node();
			header[i]->size=1;
			header[i]->parent=header[i];
		}
	}
	tree_node* findSet(int u){
		tree_node *p,*q,*r;
		r=header[u];
		while(r!=r->parent){
			r=r->parent;
		}
		p=header[u];
		while(p->parent!=r){
			q=p->parent;
			p->parent=r;
			p=q;
		}
		return r;
	}
	void mergeSets(tree_node *r1,tree_node *r2){
		tree_node *r;
		if(r1->size<=r2->size){
			r1->parent=r2;
			r=r1->parent;
		}else{
			r2->parent=r1;
			r=r1;
		}
		r->size=r1->size+r2->size;
		return;
	}
};

class Link{
	public:
	double cost;
	int v;
	Link *next;
	int getV(){
		return v;
	}
	double getCost(){
		return cost;
	}
	void setCost(double c){
		cost=c;
	}
};
class Blink{
	double cost;
	int i;
	int j;
	public:
	Blink(int u=0,int v=0,double cost=0){
		this->cost=cost;
		i=u;
		j=v;
	}
	int getU(){
		return i;
	}
	int getV(){
		return j;
	}
	double getCost(){
		return cost;
	}
	void setU(int &u){
		i=u;
	}
	void setV(int &v){
		j=v;
	}
	void setCost(double c){
		cost=c;
	}
		Blink& operator=(const Blink& x){
			if(this==&x){
				return *this;
			}
			i=x.i;
			j=x.j;
			cost=x.cost;
			return *this;
		}
		bool operator==(const Blink& x){
			if(cost==x.cost){
				return true;
			}
			return false;
		}
		bool operator>=(const Blink& x){
			if(cost>=x.cost){
				return true;
			}
			return false;
		}
		bool operator<=(const Blink& x){
			if(cost<=x.cost){
				return true;
			}
			return false;
		}
		bool operator<(const Blink& x){
			if(cost<x.cost){
				return true;
			}
			return false;
		}
		bool operator>(const Blink& x){
			if(cost>x.cost){
				return true;
			}
			return false;
		}
};
class Alist{
	public:
	Link *head;
	Alist(){
		head=0;
	}
};
class PrimElt{
	int vertex;
	int nearnbr;
	double minCost;
	int position;
	public:
	PrimElt(int v=0,int n=0,double c=0,int p=0):vertex(v),nearnbr(n),minCost(c),position(p){
	}
	PrimElt(const PrimElt& i):vertex(i.vertex),nearnbr(i.nearnbr),minCost(i.minCost),position(i.position){
	}
	void setPosition(int p){
		position=p;
	}
	int getPosition(){
		return position;
	}
	int getVal(){
		return position;
	}
	void setVertex(int v){
		vertex=v;
	}
	void setNearnbr(int n){
		nearnbr=n;
	}
	void setMinCost(double cost){
		minCost=cost;
	}
	int getVertex(){
		return vertex;
	}
	int getNearnbr(){
		return nearnbr;
	}
	double getMinCost(){
		return minCost;
	}
	PrimElt& operator=(const PrimElt& i){
		if(this==&i){
			return *this;
		}
		vertex=i.vertex;
		nearnbr=i.nearnbr;
		minCost=i.minCost;
		position=i.position;
		return *this;
	}
	bool operator==(const PrimElt& i){
		if(minCost==i.minCost){
			return true;
		}
		return false;
	}
	bool operator<(const PrimElt& i){
		if(minCost>i.minCost){
			return true;
		}
		return false;
	}
	bool operator<=(const PrimElt& i){
		if(minCost>=i.minCost){
			return true;
		}
		return false;
	}
	bool operator>(const PrimElt& i){
		if(minCost<i.minCost){
			return true;
		}
		return false;
	}
	bool operator>=(const PrimElt& i){
		if(minCost<=i.minCost){
			return true;
		}
		return false;
	}
	friend std::ostream& operator<<(std::ostream& stream,const PrimElt& x){
		stream<<"vertex="<<(x.vertex);
		stream<<"\tnearnbr="<<(x.nearnbr);
		stream<<"\tminCost="<<(x.minCost);
		stream<<"\tposition="<<(x.position);
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream,PrimElt& x){
		stream>>(x.minCost);
		return stream;
	}
};
class AMat{
	bool connected;
	double cost;
public:
	AMat(bool b=false,double c=INF){
		connected=b;
		cost=c;
	}
	bool isConnected(){
		return connected;
	}
	double getCost(){
		if(connected){
			return cost;
		}
		return INF;
	}
	void setConnected(bool b){
		connected=b;
	}
	void setCost(double c){
		cost=c;
	}
};
class DijElt{
	private:
		int v;
		double cost;
		int position;
		int initPosition;
	public:
		DijElt(int v=0,int c=0,int p=0,int ip=0){
			v=v;
			cost=c;
			position=p;
			initPosition=ip;
		}
		DijElt(const DijElt& x){
			v=x.v;
			cost=x.cost;
			position=x.position;
			initPosition=x.initPosition;
		}
		int getV(){
			return v;
		}
		double getCost(){
			return cost;
		}
		void setV(int u){
			v=u;
		}
		void setCost(double c){
			cost=c;
		}
		void setPosition(int p){
			position=p;
		}
		int getPosition(){
			return position;
		}
		int getVal(){
			return position;
		}
		void setInitPosition(int u){
			initPosition=u;
		}
		int getInitPosition(){
			return initPosition;
		}
		DijElt& operator=(const DijElt& x){
			if(this==&x){
				return *this;
			}
			v=x.v;
			cost=x.cost;
			position=x.position;
			return *this;
		}
		bool operator>=(const DijElt& x){
			if(cost<=x.cost){
				return true;
			}
			return false;
		}
		bool operator<=(const DijElt& x){
			if(cost>=x.cost){
				return true;
			}
			return false;
		}
		bool operator<(const DijElt& x){
			if(cost>x.cost){
				return true;
			}
			return false;
		}
		bool operator>(const DijElt& x){
			if(cost<x.cost){
				return true;
			}
			return false;
		}
		bool operator==(const DijElt& x){
			if(cost==x.cost){
				return true;
			}
			return false;
		}
		friend std::ostream& operator<<(std::ostream& stream,const DijElt& x){
			stream<<"vertex="<<(x.v);
			stream<<"\tCost="<<(x.cost);
			stream<<"\tposition="<<(x.position);
			return stream;
		}
		friend std::istream& operator>>(std::istream& stream,DijElt& x){
			stream>>(x.cost);
			return stream;
		}
};
class Graph{
protected:
	Alist *g;
	int size;
	double cost;
	int edgeCount;
	Link* firstNbr(int u){
		return g[u].head;
	}
	Link* nextNbr(Link *x){
		if(x==0){
			return 0;
		}
		return x->next;
	}
	int getNbr(Link *x){
		if(x==0){
			return -1;
		}
		return x->v;
	}
	Link* getNeighbourlist(int i){
		if(i>=size){
			printf("\nVertex %d does not exist in Graph of size = %d",i,size);
			return 0;
		}
		return g[i].head;
	}
public:
	Graph(int n=0){
		size=n;
		cost=0;
		edgeCount=0;
		if(n==0){
			g=0;
		}else{
			g=new Alist[n];
			for(int i=0;i<n;i++){
				g[i].head=0;
			}
		}
	}
	Graph(Graph&& G){
		// move constructor
		this->g=G.g;
		this->size=G.size;
		this->cost=G.cost;
		this->edgeCount=G.edgeCount;
		G.g=0;
		G.size=0;
		G.cost=0;
	}
	Graph& operator=(Graph&& G){
		// move assignment Operator
		if(this==&G){
			return *this;
		}
		this->g=G.g;
		this->size=G.size;
		this->cost=G.cost;
		this->edgeCount=G.edgeCount;
		G.g=0;
		G.size=0;
		G.cost=0;
		return *this;
	}
	int getSize(){
		return size;
	}
	int getEdgeCount(){
		return edgeCount;
	}
	double getCost(){
		return cost;
	}
	void clear(){
		if(g==0){
			// memory already cleared
			size=0;
			return;
		}
		if(g!=0&&size<=0){
			printf("\nError !!! can't delete Graph of negative size!!!");
			return;
		}
		Link *t,*s;
		for(int i=0;i<size;i++){
			if(g[i].head==0){
				continue;
			}
			t=g[i].head;
			while(t!=0){
				s=t->next;
				delete t;
				t=s;
			}
			g[i].head=0;
		}
		delete g;
		size=0;
		cost=0;
		edgeCount=0;
	}
	void addLink(int i,int j,double cost=0){
		if(i>=size){
			printf("\nlink1 = %d does not exist in Graph of size %d",i,size);
			return;
		}
		if(j>=size){
			printf("\nlink2 = %d does not exist in Graph of size %d",j,size);
			return;
		}
		Link *t;
		edgeCount++;

		if(g[i].head==0){
			g[i].head=new Link;
			g[i].head->v=j;
			g[i].head->cost=cost;
			g[i].head->next=0;
		}else{
			t=g[i].head;
			g[i].head=new Link;
			g[i].head->v=j;
			g[i].head->cost=cost;
			g[i].head->next=t;
		}
		this->cost=this->cost+cost;
		if(i==j){
			return;
		}
		if(g[j].head==0){
			g[j].head=new Link;
			g[j].head->v=i;
			g[j].head->cost=cost;
			g[j].head->next=0;
		}else{
			t=g[j].head;
			g[j].head=new Link;
			g[j].head->v=i;
			g[j].head->cost=cost;
			g[j].head->next=t;
		}

		return;
	}
	virtual ~Graph(){
		clear();
	}
	void print(){
		Link *t;
		printf("\nThe Adjacency List");
		for(int i=0;i<size;i++){
			printf("\n[%d] ---: ",i);
			t=g[i].head;
			while(t!=0){
				printf(" {%d,%f} ",t->v,t->cost);
				t=t->next;
			}
		}
		printf("\n");
	}
	void BFT(int u){
	
		if(size==0){
			printf("\nGraph has no node !!! ");
			return;
		}
		if(u>=size){
			printf("\nWarning !! Graph of size %d does not have vertex of size %d..starting from 0",size,u);
			u=0;
		}

		Queue<int> q;
		int i,v;
		printf("here\n");
		bool visited[size];
		for(i=0;i<size;i++){
			visited[i]=false;
		}
		printf("here\n");
		q.push(u);
		Link *head;

		while(!q.isEmpty()){

			v=q.top();
			q.pop();
			if(visited[v]==true){
				continue;
			}
			printf("\nVisited : %d\n",v);
			visited[v]=true;

			head=getNeighbourlist(v);
			while(head!=0){
				if(!visited[head->v]){
					// not visited
					q.push(head->v);
				}
				head=head->next;
			}
		}
		return;
	}
	Graph BFTTree(int u){

		Graph G(size);
		if(size==0){
			printf("\nGraph has no node !!! returning empty tree ");
			return G;
		}
		if(u>=size){
			printf("\nWarning !! Graph of size %d does not have vertex of size %d..starting from 0",size,u);
			u=0;
		}
		Queue<Blink> q;
		int i;
		Blink v;
		bool visited[size];
		for(i=0;i<size;i++){
			visited[i]=false;
		}
		Blink temp(-1,u,0);
		q.push(temp);
		Link *head;
		while(!q.isEmpty()){

			v=q.top();
			q.pop();
			if(visited[v.getV()]==true){
				continue;
			}
			printf("\nVisited : %d\n",v.getV());
			visited[v.getV()]=true;
			if(v.getU()!=-1){
				G.addLink(v.getU(),v.getV(),v.getCost());
			}

			head=getNeighbourlist(v.getV());
			while(head!=0){
				if(!visited[head->getV()]){
					// not visited
					Blink temp(v.getV(),head->getV(),head->getCost());
					q.push(temp);
				}
				head=head->next;
			}
		}
		return G;
	}
	void DFT(int u){
		if(size==0){
			printf("\nSize of Graph is Zero !!!");
			return;
		}
		if(u>=size){
			printf("\nWarning !! Graph of size %d does not have vertex of size %d..starting from 0",size,u);
			u=0;
		}
		Stack<int> S;
		bool visited[size];
		Link *nbr[size];
		int i,v,w;
		for(i=0;i<size;i++){
			visited[i]=false;
			nbr[i]=0;
		}

		S.push(u);
		cout<<"\nVisited : "<<u;
		visited[u]=true;

		nbr[u]=firstNbr(u);

		while(!S.isEmpty()){
			v=S.top();
			w=getNbr(nbr[v]);// if invalid then -1
			if(w==-1){
				S.pop();
			}else{
				if(!visited[w]){
					S.push(w);
					cout<<"\nVisited : "<<w;
					visited[w]=true;
					nbr[w]=firstNbr(w);
				}
				nbr[v]=nextNbr(nbr[v]);
			}
		}
		return;
	}
	Graph DFTTree(int u){
		Graph G(size);

		if(size==0){
			printf("\nSize of Graph is Zero !!!");
			return G;
		}
		if(u>=size){
			printf("\nWarning !! Graph of size %d does not have vertex of size %d..starting from 0",size,u);
			u=0;
		}
		Stack<int> S;
		bool visited[size];
		Link *nbr[size];
		int i,v,w;
		for(i=0;i<size;i++){
			visited[i]=false;
			nbr[i]=0;
		}
		S.push(u);
		cout<<"\nVisited : "<<u;
		visited[u]=true;

		nbr[u]=firstNbr(u);

		while(!S.isEmpty()){
			v=S.top();
			w=getNbr(nbr[v]);// if invalid then -1
			if(w==-1){
				S.pop();
			}else{
				if(!visited[w]){
					//Slink temp(w,nbr[v]->cost);
					S.push(w);
					cout<<"\nVisited : "<<w;
					G.addLink(v,w,nbr[v]->cost);
					visited[w]=true;
					nbr[w]=firstNbr(w);
				}
				nbr[v]=nextNbr(nbr[v]);
			}
		}
		return G;
	}
	Graph getMST_Prim(int root=-1){
		if(root==-1){
			// i.e. no input is provided then randomly select start vertex
			root=rand()%size;
		}
		printf("\nIn Prim !!! root = %d\n",root);
		Graph G(size);
		int i,j,nbr,u,v;
		PrimElt list[size-1];
		Link *p;
		i=j=0;
		for(i=0;i<size;i++){
			if(i!=root){
				list[j].setVertex(i);
				list[j].setNearnbr(root);
				list[j].setMinCost(INF);
				list[j].setPosition(j);
				j++;
			}
		}

		printf("\nInitial List Generated\n");
		
		p=g[root].head;

		while(p!=0){
			nbr=p->v;
			if(nbr<root){
				list[nbr].setMinCost(p->cost);
			}else{
				list[nbr-1].setMinCost(p->cost);
			}
			p=p->next;
		}
		// STAR
		// for(j=0;j<size-1;j++){
		// 	cout<<"\n"<<list[j];
		// }
		// STAR

		printf("\nGoing to create the Queue\n");

		Sheap<PrimElt> Q(list,size-1);

		//Q.print();

		printf("\nQueue Created \n");
		bool added[size];
		for(i=0;i<size;i++){
			added[i]=false;
		}
		added[root]=true;

		for(i=size-1;i>0;i--){
			PrimElt q=Q.top();
			//cout<<Q.top();
			Q.pop();
			//Q.print();
			v=q.getVertex();
			added[v]=true;
			u=q.getNearnbr();
			//printf("\nAdded edge (%d,%d) to the MST cost = %lf",u,v,q.getMinCost());
			G.addLink(u,v,q.getMinCost());
			p=g[v].head;

			while(p!=0){
				nbr=p->v;
				if(added[nbr]){
					//printf("\nWe were Here Too !! nbr = %d",nbr);
					p=p->next;
					continue;
				}
				if(nbr<root){
					j=Q.getIndex(list[nbr]);
				}else{
					j=Q.getIndex(list[nbr-1]);
				}
				if(j>=0){
					PrimElt t(Q.getByIndex(j));
					if(t.getMinCost()>p->cost){
						PrimElt x(t.getVertex(),v,p->cost,t.getPosition());
						Q.changeKey(j,x);
					}
				}else{
					printf("\nWARNING Else Occured j = %d",j);
				}
				p=p->next;
			}
		}
		return G;
	}
	int getEdgeList(Blink *E){
		// E must be sufficiently large !!! no bound check is done
		int i,j,count=0;
		Link *p;
		for(i=0;i<size;i++){
			p=g[i].head;
			while(p!=0){
				j=p->getV();
				if(j>=i){
					E[count].setU(i);
					E[count].setV(j);
					E[count].setCost(p->getCost());
					count++;
				}
				p=p->next;
			}
		}
		return count;
	}
	Graph getMST_Kruskal(){
		Graph G(size);
		Blink E[edgeCount];
		
		int count=getEdgeList(E),ntrees;
		if(count!=edgeCount){
			printf("\nFatal ERROR edge size does not match !!count = %d edgeCount = %d",count,edgeCount);
			exit(0);
		}
		MFSet S(size);
		mergeSort(E,count);
		// STAR
		// for(int i=0;i<count;i++){
		// 	printf(" %lf ",E[i].getCost() );
		// }
		// STAR
		ntrees=size;
		int i=0,u,v;
		tree_node *U,*V;
		while(ntrees>1){
			u=E[i].getU();
			v=E[i].getV();
			U=S.findSet(u);
			V=S.findSet(v);
			if(U!=V){
				//printf("Add (%d,%d) to the MST\n",u,v);

				G.addLink(u,v,E[i].getCost());
				S.mergeSets(U,V);
				ntrees--;
			}
			i++;
		}

		return G;
	}
	bool isConnected(){
		if(size==0){
			printf("\nGraph has no node !!! so implicitly connected !!");
			return true;
		}
		int u=0;

		Queue<int> q;
		int i,v;
		//printf("here\n");
		bool visited[size];
		for(i=0;i<size;i++){
			visited[i]=false;
		}
		//printf("here\n");
		q.push(u);
		Link *head;

		while(!q.isEmpty()){

			v=q.top();
			q.pop();
			if(visited[v]==true){
				continue;
			}
			printf("\nVisited : %d\n",v);
			visited[v]=true;

			head=getNeighbourlist(v);
			while(head!=0){
				if(!visited[head->v]){
					// not visited
					q.push(head->v);
				}
				head=head->next;
			}
		}
		for(i=0;i<size;i++){
			if(!visited[i]){
				return false;
			}
		}
		return true;
	}
	bool isTree(int u=0){
		//connected ness is assumed
		if(size==0){
			printf("\nGraph has no node !!! So implicitly a tree");
			return true;
		}
		if(u>=size){
			printf("\nWarning !! Graph of size %d does not have vertex of size %d..starting from 0",size,u);
			u=0;
		}

		Queue<int> q;
		int i,v;
		printf("here\n");
		bool visited[size];
		for(i=0;i<size;i++){
			visited[i]=false;
		}
		printf("here\n");
		q.push(u);
		Link *head;

		while(!q.isEmpty()){

			v=q.top();
			q.pop();
			if(visited[v]==true){
				return false;
			}
			printf("\nVisited : %d\n",v);
			visited[v]=true;

			head=getNeighbourlist(v);
			while(head!=0){
				if(!visited[head->v]){
					// not visited
					q.push(head->v);
				}
				head=head->next;
			}
		}

		return true;
	}
	vector<int> getRootSet(){
		{

		}
	}

	void Dijkstra(int u,double *d,int *prev){
		// dist and prev must be of size "size"
		int v,w,i,j;
		double c;
		bool processed[this->size];
		for(i=0;i<size;i++){
			d[i]=INF;
			prev[i]=u;
			processed[i]=false;
		}
		Link *p=g[u].head;
		while(p!=0){
			v=p->getV();
			c=p->getCost();
			if(c<d[v]){
				d[v]=c;
			}
			p=p->next;
		}
		processed[u]=true;
		d[u]=0;
		prev[u]=-1;
		DijElt q[size-1];
		DijElt n,x,y;
		j=0;
		for(i=0;i<size;i++){
			if(i!=u){
				q[j].setV(i);
				q[j].setCost(d[i]);
				q[j].setPosition(j);
				q[j].setInitPosition(j);
				j++;
			}
		}
		Sheap<DijElt> Q(q,size-1);

		while(!Q.isEmpty()){
			//printf("\nQueue Filled for eternity !!\n");
			n=Q.top();
			v=n.getV();
			p=g[v].head;
			Q.pop();
			while(p!=0){
				w=p->getV();
				c=p->getCost();
				if(!processed[w]){
					if(d[v]+c<d[w]){
						// we need to update

						d[w]=d[v]+c;
						prev[w]=v;

						/****************Code to modify Queue********************/
						if(w<u){
							i=Q.getIndex(q[w]);
						}
						if(w>u){
							i=Q.getIndex(q[w-1]);
						}
						y=Q.getByIndex(i);
						x.setV(w);
						x.setPosition(y.getPosition());
						x.setInitPosition(y.getInitPosition());
						x.setCost(d[v]+c);
						Q.changeKey(i,x);
						/*********************************************************/
					}
				}
				p=p->next;
			}
			processed[v]=true;
		}
	}
	void listToMinMat(AMat *d){
		Link *p;
		int i,j;
		double cost;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				d[i*size+j].setConnected(false);
				d[i*size+j].setCost(INF);
			}
		}
		for(i=0;i<size;i++){
			d[i*size+i].setConnected(true);
			d[i*size+i].setCost(0);
		}
		for(i=0;i<size;i++){
			p=g[i].head;
			while(p!=0){
				j=p->getV();
				cost=p->getCost();
				if(d[i*size+j].isConnected()){
					if(d[i*size+j].getCost()>cost){
						d[i*size+j].setCost(cost);
					}
				}else{
					d[i*size+j].setConnected(true);
					d[i*size+j].setCost(cost);
				}
				p=p->next;
			}
			
		}
	}
	void FloydWarshal(double **d=0,int **N=0){
		// no bound check on the matrices are done
		if(d==0){
			d=new double*[size];
			for(int i=0;i<size;i++){
				d[i]=new double[size];
			}
		}
		if(N==0){
			N=new int*[size];
			for(int i=0;i<size;i++){
				N[i]=new int[size];
			}
		}
		AMat list[size][size];
		AMat *tempList=new AMat[size*size];
		cout<<"\nhere\n";
		listToMinMat(tempList);
		cout<<"\n0\n";
		int i,j,k;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				list[i][j].setConnected(tempList[i*size+j].isConnected());
				list[i][j].setCost(tempList[i*size+j].getCost());
			}
		}
		delete tempList;
		cout<<"1\n";
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(list[i][j].isConnected()){
					d[i][j]=list[i][j].getCost();
					N[i][j]=j;
				}else{
					d[i][j]=INF;
					N[i][j]=-1;
				}
			}
		}
		cout<<"2\n";
		double x;
		for(k=0;k<size;k++){
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					x=d[i][k]+d[k][j];
					if(x<d[i][j]){
						d[i][j]=x;
						N[i][j]=N[i][k];
					}
				}
			}
		}

		for(i=0;i<size;i++){
			printf("\n");
			for(j=0;j<size;j++){
				printf("\t%lf",d[i][j]);
			}
		}
		printf("\n");
		return;
	}

};

int main(){
	//system("reset");
	srand ( (unsigned)time ( NULL ) );
	int n,i,j,cost,size;
	int maxCost=rand()%1000;
	printf("\nEnter Graph Size : ");
	scanf("%d",&size);

	Graph g(size);
	// n=1;
	// int flag=0;
	// while(n!=0){
	// 	printf("\nEnter 0 to exit :");
	// 	printf("\nEnter 1 to add :");
		

	// 	printf("\n");
	// 	scanf("%d",&n);

	// 	switch(n){
	// 		case 0:{
	// 			flag=1;
	// 			break;
	// 		}
	// 		case 1:{
	// 			printf("\nEnter node 1 : ");
	// 			scanf("%d",&i);
	// 			printf("\nEnter node 2 : ");
	// 			scanf("%d",&j);
	// 			cost=0;
	// 			g.addLink(i,j,cost);
	// 		}
	// 	}

	// 	g.print();

	// 	if(flag==1){
	// 		break;
	// 	}

	// }
	/******************Code to generate Random Graph*********************/
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			//if(rand()%2==1){
				g.addLink(i,j,rand()%maxCost+1);
			//}
		}
	}
	int c;
	printf("\nThe Graph --->>>\n");
	//g.print();
	// printf("\nGraph Generated  Press any key to find MST : \n");
	// if(g.isConnected()){
	// 	printf("\ng is connected !!");
	// }
	// if(g.isTree()){
	// 	printf("\ng is a tree !!");
	// }
	// Graph pmst(g.getMST_Prim());
	// //pmst.print();
	// printf("\nCOST = %lf",pmst.getCost());
	// if(pmst.isConnected()){
	// 	printf("\npmst is connected !!");
	// }
	// if(pmst.isTree()){
	// 	printf("\npmst is a tree !!");
	// }

	// Graph kmst(g.getMST_Kruskal());
	// //kmst.print();
	// printf("\nCOST = %lf",kmst.getCost());
	// if(kmst.isConnected()){
	// 	printf("\nkmst is connected !!");
	// }
	// if(kmst.isTree()){
	// 	printf("\nkmst is a tree !!");
	// }
	// //g.DFT(0);

	// //Graph tree(g.DFTTree(0));

	// //tree.print();


	double distance[size];
	int prev[size];


	printf("\nCalling Dijstra!!\n");
	g.Dijkstra(0,distance,prev);
	printf("\nDijstra ended!!\n");
	for(i=0;i<size;i++){
		printf("\nd[%d]=%lf\tprev[%d]=%d",i,distance[i],i,prev[i]);
	}

	g.FloydWarshal();

	return 0;
}