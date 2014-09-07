#ifndef INTEGER_INCLUDED
#define INTEGER_INCLUDED
#include <iostream>
using namespace std;

class Integer{
	int v;
public:
	Integer(int i=0):v(i){
	}
	Integer(const Integer& i):v(i.v){
	}
	int getVal(){
		return v;
	}
	void setVal(int i){
		v=i;
	}
	Integer& operator=(const int& i){
		v=i;
		return *this;
	}
	Integer& operator=(const Integer& i){
		v=i.v;
		return *this;
	}
	bool operator==(const Integer& i){
		if(v==i.v){
			return true;
		}
		return false;
	}
	bool operator>(const Integer& i){
		if(v>i.v){
			return true;
		}
		return false;
	}
	bool operator>=(const Integer& i){
		if(v>=i.v){
			return true;
		}
		return false;
	}
	bool operator<(const Integer& i){
		if(v<i.v){
			return true;
		}
		return false;
	}
	bool operator<=(const Integer& i){
		if(v<=i.v){
			return true;
		}
		return false;
	}
	friend std::ostream& operator<<(std::ostream& stream,const Integer& x){
		stream<<(x.v);
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream,Integer& x){
		stream>>(x.v);
		return stream;
	}
};
#endif




// int main(){
// 	int a,b,t;
// 	scanf("%d",&t);
// 	while(t>0){
// 		//scanf("%d",&a);
// 		//scanf("%d",&b);

// 		Integer A,B;
// 		cin>>A>>B;
// 		cout<<"\nA = "<<A<<"\nB = "<<B;
// 		if(A==B){
// 			printf("\nA = B\n");
// 		}
// 		if(A>B){
// 			printf("\nA > B\n");
// 		}
// 		if(A<B){
// 			printf("\nA < B\n");
// 		}
// 		if(A>=B){
// 			printf("\nA >= B\n");
// 		}
// 		if(A<=B){
// 			printf("\nA <= B\n");
// 		}
// 	}
// }