#ifndef INCLUDED_HEAP
#define INCLUDED_HEAP
/*
	An efficient implementation of Binary Max Heap using VECTORS
	Author : Sourav Sarkar
	email:	 souravmathlover@gmail.com
	date:
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>





static int count=0;

using namespace std;

template <typename T>class Heap{
// class T must have < , <= , == , => , > << >> operator ... else this class will not work
protected:
	std::vector<T>* heap;
	bool Remove;
	void heapify(int i){
		//int test=i;
		int left,right,largest,t;
		while(1){
			//printf("\ntrapped");
			largest=i;
			left=2*i+1;
			right=left+1;

			if(left<((*heap)).size()&&((*heap))[left]>((*heap))[largest]){
				largest=left;
			}

			if(right<(*heap).size()&&(*heap)[right]>(*heap)[largest]){
				largest=right;
			}

			if(largest!=i){
				// we need to do more work !!!
				// t=(*heap)[i];
				// (*heap)[i]=(*heap)[largest];
				// (*heap)[largest]=t;
				//printf("\n<heapify>This = %p",this);
				this->swap(i,largest);
				i=largest;// attempting next iteration
				continue;
			}else{
				//printf("\nHeapify done for i=%d\n",test);
				return;
			}
		}
	}
	int decreaseKey(int i,T b){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		if((*heap).size()<(i+1)){
			printf("\nHeap is too smal heap size = %lu asked index = %d !!!",(*heap).size(),i);
			return -1;
		}
		(*heap)[i]=b;
		heapify(i);
	}
	int increaseKey(int i,T b){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		if((*heap).size()<(i+1)){
			printf("\nHeap is too smal heap size = %lu asked index = %d !!!",(*heap).size(),i);
			return -1;
		}
		int p,t;
		p=(i-1)/2;
		(*heap)[i]=b;
		while(i>0){
			p=(i-1)/2;
			if((*heap)[p]<(*heap)[i]){
				// t=(*heap)[p];
				// (*heap)[p]=(*heap)[i];
				// (*heap)[i]=t;
				this->swap(p,i);
				i=p;
				continue;
			}else{
				break;
			}
		}
		return 1;
	}
	virtual void swap(int i,int j){
		//printf("\nThis = %p",this);
		//printf("\nOld swap called !!");
		if(i>=(*heap).size()||j>=(*heap).size()){
			printf("\nERROR : Index out of bound in re-ordering heap !!");
			return;
		}
		T t;
		t=(*heap)[i];
		(*heap)[i]=(*heap)[j];
		(*heap)[j]=t;
		return;
	}
	virtual void eraseLast(){
		(*heap).erase((*heap).begin()+(*heap).size()-1);
	}
public:
	/************The Big 5*************/
	Heap(bool v=true){
		heap=0;
		Remove=v;
	}
	Heap(T *a,int n,bool v=true){
		this->Remove=v;
		heap=new std::vector<T>;
		count++;
		int i;
		for(i=0;i<n;i++){
			(*heap).push_back(a[i]);
		}
		for(i=n-1;i>=0;i--){
			heapify(i);
		}
		// print();
		// printf("\nHeapify completed\n");

	}
	Heap(const Heap& A){
		// the copy Constructor
		heap=new std::vector<T>;
		count++;
		for(int i=0;i<(*(A.heap)).size();i++){
			(*heap).push_back((*(A.heap))[i]);
		}
		this->Remove=true;
	}
	Heap(Heap&& A){
		// The move Constructor
		heap=A.heap;
		this->Remove=true;
		A.heap=0;
		A.Remove=true;

	}
	Heap& operator=(Heap&& A){
		// The move assignment operator
		if(this==&A){
			return *this;
		}
		heap=A.heap;
		A.heap=0;

	}
	Heap& operator=(Heap& A){
		//Copy Assignment operator
		//printf("\n = operator is called\n");
		if(this==&A){
			// A=A type Syntax ... do nothing
			return *this;// via copy constructor
		}
		this->clear();
		this->Remove=A.getStatus();
		this->heap=new std::vector<T>;
		count++;
		for(int i=0;i<A.getSize();i++){
			(*(this->heap)).push_back((*(A.heap))[i]);
		}
		return *this;
	}
	/********************Big 5 ended*****************************************************/
	/*******************Remove functions**************************************************/
	int clear(){
		if(heap!=0){
			(*heap).clear();
			delete heap;
			count--;
			heap=0;
		}
		return 1;
	}
	virtual ~Heap(){
		if(this->Remove){
			clear();
		}
	}
	void init(bool v=true){
		this->clear();
		this->heap=new std::vector<T>;
		count++;
		this->Remove=true;
	}
	/****************************************************************************************/
	/*******************Operators****************************************/
	// Heap& operator*(Heap& B){
	// 	// A=B*C means B and C will be merged into A ... B and C will not be changed

	// }
	/********************************************************************/
	/************************Get Functons***********************************/
	int getSize(){
		if(heap==0){
			return 0;
		}
		return (*heap).size();
	}
	bool getStatus(){
		return this->Remove;
	}
	vector<int>* getHeap(){
		return heap;
	}
	bool isEmpty(){
		if(getSize()==0){
			return true;
		}
		return false;
	}
	/************************************************************************/
	/**********************Normal Functions******************************/
	T key(int i){
		if(heap==0){
			printf("\nHeap is Empty !!!");
			return -1;
		}
		if(i<(*heap).size()){
			return (*heap)[i];
		}else{
			printf("ERROR heap has size = %lu and going to access %d",(*heap).size(),i);
			return -1;
		}
	}
	int push(T a){
		if(heap==0){
			printf("\nHeap is initialised ... please do void HEAP::create()");
			return 0;
		}
		(*heap).push_back(a);
		int i=(*heap).size()-1;
		int p,t;
		while(i>0){
			p=(i-1)/2;
			if((*heap)[i]>(*heap)[p]){
				// t=(*heap)[i];
				// (*heap)[i]=(*heap)[p];
				// (*heap)[p]=t;
				this->swap(p,i);
				i=p;
			}else{
				return 1;
			}
		}
		return 1;
	}
	int pop(){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		if((*heap).size()==0){
			printf("\nHeap is already empty !!! nothing to pop !!!");
			return 0;
		}
		//(*heap)[0]=(*heap)[(*heap).size()-1];
		this->swap(0,(*heap).size()-1);
		this->eraseLast();
		heapify(0);
		return 1;
	}
	int heapSort(T *a){
		Heap<T> h(*this);
		for(int i=0;i<((*heap)).size();i++){
			//h.print();
			a[i]=h.top();
			h.pop();
		}
		return 1;
	}
	virtual int getIndex(T a){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		int i;
		for(i=0;i<((*heap)).size();i++){
			if((*heap)[i]==a){
				return i;
			}
		}
		return -1;
	}
	int changeKey(int i,T b){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		if((*heap).size()<(i+1)){
			printf("\nHeap is too smal heap size = %lu asked index = %d !!!",(*heap).size(),i);
			return -1;
		}
		if((*heap)[i]>b){
			return decreaseKey(i,b);
		}
		if(((*heap))[i]<b){
			return increaseKey(i,b);
		}
		return 0;
	}
	int changeKey(T a,T b,int byvaluedummy){
		if(heap==0){
			printf("\nHeap is not initialised !!!");
			return -1;
		}
		int i=getIndex(a);
		if(i==-1){
			printf("\n %d does not exist in the Heap !!",a);
			return 0;
		}
		printf("\ni=%d",i);
		if(a>b){
			return decreaseKey(i,b);
		}
		if(a<b){
			return increaseKey(i,b);
		}
		return 0;
	}
	T top(){
		if(heap==0){
			printf("\nHeap is not initalised !!!");
			return -1;
		}
		if((*heap).size()==0){
			printf("\nWARNING HEAP is empty ... asking top element");
			return -1;
		}
		return (*heap)[0];
	}
	T getByIndex(int i=0){
		return (*heap)[i];
	}
	void print(){
		printf("\nPrinting Heap \n");
		for(int i=0;i<(*heap).size();i++){
			cout<<" "<<(*heap)[i]<<" ";
		}
		return;
	}
};

// template <typename T>class SheapElt{
// 	private:
// 		T v;
// 		int address;
// 	public:
// 		SheapElt(T &x,int add=0):
// 		v(x),address(add){
// 		}
// 		void setV(T &x){
// 			v=x;
// 		}
// 		void setAddress(int add){
// 			address=add;
// 		}
// 		T getV(){
// 			return v;
// 		}
// 		int getAddress(){
// 			return address;
// 		}
// 		SheapElt<T>& operator=(const SheapElt& x){
// 			if(this==&x){
// 				return *this;
// 			}
// 			v=x.v;
// 			address=x.address;
// 			return *this;
// 		}
// 		bool operator==(const SheapElt& x){
// 			if(v==x.v){
// 				return true;
// 			}
// 			return false;
// 		}
// 		bool operator>(const SheapElt& x){
// 			if(v>x.v){
// 				return true;
// 			}
// 			return false;
// 		}
// 		bool operator>=(const SheapElt& x){
// 			if(v>=x.v){
// 				return true;
// 			}
// 			return false;
// 		}
// 		bool operator<(const SheapElt& x){
// 			if(v<x.v){
// 				return true;
// 			}
// 			return false;
// 		}
// 		bool operator<=(const SheapElt& x){
// 			if(v<=x.v){
// 				return true;
// 			}
// 			return false;
// 		}
// };

template <typename T> class Sheap:public Heap<T>{
// in addition to operators mentioned in Heap we need a getVal() function in class T ... 
// in this heap all the elements must map to a unique natural number... getval should return that... that will be the initial indexing
// before heapify and that will be properly maintained !!!
protected:
	std::vector<int>* hindex;
	virtual void swap(int i,int j){
		//printf("\nThis = %p",this);
		//printf("\nWe are Here !!");
		if(i>=(*(this->heap)).size()||j>=(*(this->heap)).size()){
			printf("\nERROR : Index out of bound in re-ordering heap !!");
			return;
		}
		int m,n;
		m=(*(this->heap))[i].getVal();
		n=(*(this->heap))[j].getVal();
		(*hindex)[m]=j;
		(*hindex)[n]=i;
		T t;
		t=(*(this->heap))[i];
		(*(this->heap))[i]=(*(this->heap))[j];
		(*(this->heap))[j]=t;
		return;
	}
	virtual void eraseLast(){
		T I=(*(this->heap))[(*this->heap).size()-1];
		int i=I.getVal();
		(*hindex)[i]=-1;
		(*(this->heap)).erase((*(this->heap)).begin()+(*(this->heap)).size()-1);
	}
public:
	/************The Big 5*************/
	Sheap(bool v=true){
		this->heap=0;
		this->Remove=v;
		hindex=0;
	}
	Sheap(T *a,int n,bool v=true){
		//printf("\n<cons>This = %p",this);
		this->Remove=v;
		this->heap=new std::vector<T>;
		hindex=new std::vector<int>;

		count++;
		int i;
		for(i=0;i<n;i++){
			(*this->heap).push_back(a[i]);
			(*hindex).push_back(0);
		}
		for(i=0;i<n;i++){
			(*hindex)[a[i].getVal()]=i;
		}
		for(i=n-1;i>=0;i--){
			this->heapify(i);
		}
		// print();
		// printf("\nHeapify completed\n");

	}
	Sheap(const Sheap& A){
		// the copy Constructor
		printf("\nIn copy Cons");
		this->heap=new std::vector<T>;
		hindex=new std::vector<int>;
		count++;
		for(int i=0;i<(*(A.heap)).size();i++){
			(*this->heap).push_back((*(A.heap))[i]);
			(*hindex).push_back((*(A.hindex))[i]);
		}
		this->Remove=true;
	}
	Sheap(Sheap&& A){
		// The move Constructor
		this->heap=A.heap;
		hindex=A.hindex;
		this->Remove=true;
		A.heap=0;
		A.Remove=true;
		A.hindex=0;
	}
	Sheap& operator=(Sheap&& A){
		// The move assignment operator
		if(this==&A){
			return *this;
		}
		this->heap=A.heap;
		this->Remove=A.Remove;
		hindex=A.hindex;
		A.Remove=true;
		A.hindex=0;
		A.heap=0;

	}
	Sheap& operator=(Sheap& A){
		//Copy Assignment operator
		//printf("\n = operator is called\n");
		if(this==&A){
			// A=A type Syntax ... do nothing
			return *this;// via copy constructor
		}
		this->clear();
		this->Remove=A.getStatus();
		this->heap=new std::vector<int>;
		this->hindex=new std::vector<int>;
		count++;
		for(int i=0;i<A.getSize();i++){
			(*(this->heap)).push_back((*(A.heap))[i]);
			(*(this->hindex)).push_back((*(A.hindex))[i]);
		}
		return *this;
	}
	/********************Big 5 ended*****************************************************/

	/*******************Remove functions**************************************************/
	int clear(){
		if(this->heap!=0){
			(*this->heap).clear();
			delete this->heap;
			count--;
			this->heap=0;
		}
		if(hindex!=0){
			(*hindex).clear();
			delete hindex;
			hindex=0;
		}
		return 1;
	}
	virtual ~Sheap(){
		if(this->Remove){
			clear();
		}
	}
	int heapSort(T *a){
		Sheap<T> h(*this);
		for(int i=0;i<((*this->heap)).size();i++){
			//h.print();
			a[i]=h.top();
			h.pop();
		}
		return 1;
	}
	void init(bool v=true){
		this->clear();
		this->heap=new std::vector<int>;
		this->hindex=new std::vector<int>;
		count++;
		this->Remove=true;
	}
	int getIndex(T a){
		int r;
		int v=a.getVal();
		if(v>=(*this->hindex).size()){
			printf("\nWARNING %d does not exist is Sheap !!",v);
			return -1;
		}
		r=(*hindex)[v];
		if(r==-1){
			printf("\nUNKNOWN %d does not exist is Sheap !!",v);
		}

		return r;
	}
	void print(){
		printf("\nPrinting Heap \n");
		for(int i=0;i<(*this->heap).size();i++){
			cout<<" "<<(*this->heap)[i]<<" ";
		}
		for(int i=0;i<(*hindex).size();i++){
			cout<<"\nAddress["<<i<<"] = "<<(*hindex)[i];
		}
		return;
	}
	/****************************************************************************************/

};
#endif

/**********************Testing Functions*************************/
// int isSorted(int a[],int n){
// 	for(int i=0;i<=n-2;i++){
// 		if(a[i]>a[i+1]){
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
// int isSortedReversed(int a[],int n){
// 	for(int i=0;i<=n-2;i++){
// 		if(a[i]<a[i+1]){
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
// int isSame(int *a,int *b,int size,int size2){
// 	if(size!=size2){
// 		printf("\nsizea = %d\tsizeb = %d",size,size2);
// 		return 0;
// 	}
// 	for(int i=0;i<size;i++){
// 		if(a[i]!=b[i]){
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
// int randomize(int *a,int n){
// 	int i=0,t,x;
// 	int b[n];
// 	for(i=0;i<n;i++){
// 		t=rand()%(n-i)+i;
// 		b[i]=a[t];
// 		x=a[i];
// 		a[i]=a[t];
// 		a[t]=x;
// 	}
// 	printf("\n***\n");
// 	for(i=0;i<n;i++){
// 		a[i]=b[i];
// 		printf(" %d ",a[i]);
// 	}
// 	printf("\n***\n");
// 	return 1;
// }
// void print(int *a,int n){
// 	printf("\n");
// 	for(int i=0;i<n;i++){
// 		printf(" %d ",a[i]);
// 	}
// 	printf("\n");
// 	return;
// }
/***************************************************************/

// int main(){
// 	srand ( (unsigned)time ( NULL ) );
// 	int n,t,i,size,r,s,p;
// 	scanf("%d",&n);
// 	int a[n],b[n];
// 	Integer A[n];
// 	Integer B[n];
// 	scanf("%d",&t);
// 	while(t>0){
// 		size=n;
// 		for(i=0;i<size;i++){
// 			//a[i]=rand()%(10*size);
// 			a[i]=i;
// 		}
// 		randomize(a,size);
// 		print(a,size);
// 		for(i=0;i<size;i++){
// 			A[i].setVal(a[i]);
// 		}
// 		Sheap<Integer> h(A,size);
// 		h.print();
// 		h.heapSort(B);
// 		for(i=0;i<size;i++){
// 			b[i]=B[i].getVal();
// 		}
// 		print(b,size);
// 		if(isSortedReversed(b,size)){
// 			printf("\nSuccesss !!!");
// 		}else{
// 			printf("\nfailed !!");
// 			exit(0);
// 		}
// 		while(!h.isEmpty()){
// 			h.pop();
// 			h.print();
// 		}
// 		t--;
// 	}
// 	return 0;
// }

// int main(){
// 	srand ( (unsigned)time ( NULL ) );
// 	int n,t,i,size,r,s;
// 	scanf("%d",&n);
// 	int a[n],b[n];
// 	scanf("%d",&t);
// 	while(t>0){
// 		// size=(rand()%n)+1;
// 		size=n;
// 		for(i=0;i<size;i++){
// 			a[i]=rand()%(10*size);
// 			//a[i]=(i+1);
// 		}
// 		//randomize(a,size);
// 		// Heap h(a,size);
// 		Heap<int> h;
// 		h.init();
// 		for(i=0;i<size;i++){
// 			h.push(a[i]);
// 		}
// 		//h.print();
// 		// while(1){
// 		// 	scanf("%d",&r);
// 		// 	if(r==-1){
// 		// 		break;
// 		// 	}
// 		// 	scanf("%d",&s);
// 		// 	h.changeKey(r,s,0);
// 		// }
// 		h.heapSort(b);
// 		//print(b,size);
// 		if(isSortedReversed(b,size)){
// 			printf("\nSuccesss !!!");
// 		}else{
// 			printf("\nfailed !!");
// 			exit(0);
// 		}
// 		t--;
// 		Heap<int> x;
// 		x=h;
// 	}


// 	printf("\ncount = %d\n",count);
// 	return 0;
// }
