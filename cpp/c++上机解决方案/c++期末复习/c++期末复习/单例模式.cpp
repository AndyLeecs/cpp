#include<iostream>
#include<string>

using namespace std;
class Singleton{
protected:
	Singleton(){};
	Singleton(const Singleton&){};
public:
	static Singleton* getInstance(){
		if (ptr == NULL) {
			ptr = new Singleton();
			return ptr;
		}
		else
			return ptr;
	};
	static void destroy(){
		delete ptr;
		ptr = NULL;
	}
private:
	static Singleton* ptr;
};