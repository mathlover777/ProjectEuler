#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class A{
	int a;
public:
	A(int i=0):
	a(i)
	{
		printf("\nIn normal construcor");
	}
	A(const A& a){
		printf("\nIn Copy constructor with const parameter");
		this->a=a.a;
	}
	A(A& a){
		printf("\nIn Copy constructor without const parameter");
		this->a=a.a;
	}
	int geta(){
		return a;
	}
	void seta(int i){
		a=i;
	}
	virtual ~A(){
		printf("\nIn destructor !!");
	}
};

A get(){
	A a(1);
	printf("\nReturning from get");
	return a; 
}

int main(){
	A a(1);
	A b(a);

	printf("\nGoing to Create C");
	A c=get();
	printf("\nC created !!!");
}