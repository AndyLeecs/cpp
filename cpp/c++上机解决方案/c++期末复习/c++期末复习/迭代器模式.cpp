#include<iostream>
#include<string>
#include<fstream>
#include<list>
using namespace std;
//���������ļ�
ofstream out("trial.txt");
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void update() {}
};

void main(){
	list<Observer*> l;
	list<Observer*>::iterator it = l.begin();
	for (; it != l.end(); it++){
		(*it)->update();
		
	}
	out << 0;
}