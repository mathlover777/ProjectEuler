#ifndef QUEUE_INCLUDED
#define QUEUE_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> class qnode{
public:
	T v;
	qnode<T> *next;
};


template <typename T> class Queue{  
	qnode<T> *head;
	qnode<T> *tail;
public:
	Queue(){
		head=0;
		tail=0;
	}
	void push(T &v){
		if(head==0){
			// if queue is empty
			head=new qnode<T>;
			head->v=v;
			head->next=0;
			tail=head;
		}else{
			tail->next=new qnode<T>;
			tail=tail->next;
			tail->v=v;
			tail->next=0;
		}
		return;
	}
	void pop(){
		if(head==0){
			printf("\nTrying to Pop from empty stack !!!");
			return;
		}
		if(head==tail){
			delete head;
			head=0;
			tail=0;
			return;
		}
		qnode<T> *t;
		t=head;
		head=head->next;
		delete t;
		return;
	}
	T top(){
		if(head==0){
			printf("\nWarning trying to get top from empty queue !!!");
			return T(0);
		}
		return head->v;
	}
	bool isEmpty(){
		if(head==0){
			return true;
		}
		return false;
	}
	void print(){
		qnode<T> *t;
		t=head;
		cout<<"\n{ ";
		while(t!=0){
			cout<<" "<<t->v<<" ";
			t=t->next;
		}
		cout<<" }\n";
		return;
	}
	void clear(){
		qnode<T> *t;
		tail=0;
		while(head!=0){
			t=head->next;
			delete head;
			head=t;
		}
		return;
	}
	virtual ~Queue(){
		clear();
	}
};

#endif


// int main(){
// 	Queue<int> q;
// 	int i,n;
// 	while(1){
// 		printf("\nEnter 1 to Push");
// 		printf("\nEnter 2 to Pop");
// 		printf("\nEnter 3 to top");
// 		printf("\nEnter 4 to Clear");
// 		printf("\nEnter 0 to exit");


// 		scanf("%d",&i);

// 		switch(i){
// 			case 0:return 0;
// 			case 1:{
// 				scanf("%d",&n);
// 				q.push(n);
// 				break;
// 			}
// 			case 2:{
// 				q.pop();
// 				break;
// 			}
// 			case 3:{
// 				printf("\nTop Element is : %d",q.top());
// 				break;
// 			}
// 			case 4:{
// 				q.clear();
// 				break;
// 			}
// 			default:{
// 			}
// 		}
// 		q.print();
// 	}
// 	return 0;
// }