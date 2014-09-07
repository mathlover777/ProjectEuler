#include <stdio.h>
#include <stdlib.h>

class A{
	int *a;

	/************* The Big 5 *********************/
public:
	A(const int n){
		// uninary constructor
		a=new int(n);
		printf("\nUninary Constructor Called\n");
	}
	A(const A& b){
		printf("\nCopy constructor executed\n");
		a=new int(*(b.a));
	}
	A& operator=(const A& b){
		if(this==&b){
			return *this;
		}
		if(a!=0){
			delete a;
			a=0;
		}
		a=new int(*(b.a));
		printf("\nIn Copy assignment operator\n");
	}


	A(A&& b){
		printf("\nIn Move constructor\n");
		a=b.a;
		b.a=0;
	}
	A& operator=(A&& b){
		if(a!=0){
			delete a;
			a=0;
		}
		a=b.a;
		b.a=0;
		printf("\nIn Move assignment operator\n");
	}	
	

	/*********************************************/
	// A& operator+(const A& b){
	// 	printf("\nIn operator +");
	// 	int k=(*a)+(*(b.a));
	// 	printf("\nK=%d",k);
	// 	A c(k);
	// 	printf("\nc created\n");
	// 	return c;
	// }

	virtual ~A(){
		printf("\nIn the destructor!!!");
		if(a!=0){
			delete a;
		}else{
			printf("\nNothing to delete !!");
		}
	}
	int get() const {
    	return a ? *a : 0;
    }

    A operator+(const A& b){
    	printf("\nin +operator = %d",(*a)+(*(b.a)));
    	return A((*a)+(*(b.a)));
    }
};

A square(const A& r) {
    const int i = r.get();
    A c(i * i);
    //printf("\nhere\n");
    return c;
}

int main(){
	A a(3),b(5);
	printf("\nPart 1");
	A c=square(a);
	printf("\nPart 2");
	A d(2);

	d=a+b;
	printf("\nPart 3");
}