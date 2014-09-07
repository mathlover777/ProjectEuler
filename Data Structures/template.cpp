#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


template <typename T> class A
{
public:
	T t;

	/* data */
};

int main(){
	A<int> b;
	b.t=1;
	cout<<b.t;
}