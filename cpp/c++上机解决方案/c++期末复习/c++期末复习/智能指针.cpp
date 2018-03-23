#include<iostream>
#include<string>
using namespace std;
class A{
public:int a = 0;
};
template <class T>
class auto_ptr_{
public:
	auto_ptr_(T*ptr = 0):p(ptr){  };
	~auto_ptr_(){ delete p; }
	T* operator -> (){ return p; }
	T& operator *(){ return *p; }
private:
	T* p;
};

//void main()
//{
//	A* ptr = new A();
//	auto_ptr_<A> smart = auto_ptr_<A>(ptr);
//	cout<<smart->a;
//	system("pause");
//}