#include <iostream>

using namespace std;

class A{
protected:
	int a;
public:
	A(int b=0):a(b){}
	void print(){
		cout<<"\n a = "<<a;
		return;
	}
};

class B:public A{
private:
	int b;
public:
	B(int x=0,int y=0){
		a=x;
		b=y;
	}
	void print(){
		cout<<"\n a = "<<a<<" b = "<<b;
		return;
	}
};

int main(){
	int i,j;
	i=0;
	
}

