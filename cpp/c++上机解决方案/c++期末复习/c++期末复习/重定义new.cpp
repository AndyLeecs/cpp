#include<iostream>
#include<string>
#include<vector>
using namespace std;
class A{
public:
	static new_handler set_new_handler(new_handler h);
	static void* operator new (size_t size);
	static void operator delete(void* rawmemory, size_t size);
	
private:
	static new_handler currentHandler;
};
new_handler A::currentHandler;
new_handler A::set_new_handler(new_handler h){
	new_handler oldHandler = currentHandler;
	currentHandler = h;
	return oldHandler;
}
void* A::operator new (size_t size){
	if (size == 0)
	size = 1;

	new_handler globalHandler = std::set_new_handler(currentHandler);

	void*memory;

	while (1){
		try{
			memory = ::operator new(size);
			break;
		}
		catch (bad_alloc&){
			std::set_new_handler(globalHandler);
			throw;
		}
		}
	
	std::set_new_handler(globalHandler);
	return memory;
}

void A::operator delete(void* rawmemory, size_t size){
	if (rawmemory == 0)return;
	if (size != sizeof(A)){
		::operator delete(rawmemory);

		return;
	}

	return;
}
//void main()
//{
//	A a;
//	
//	A* b = new A();
//	int i = sizeof *b;
//	cout << i;
//	system("pause");
//}