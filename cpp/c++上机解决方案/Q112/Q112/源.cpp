#include<iostream>
using namespace std;
class Operation{
	double a, b;
public:
	double getA();
	double getB();
	double setA();
	double setB();
	virtual double getResult(double a, double b) = 0;
};
class OperationFactory{
public:
	static Operation* createOperation(char c);
};

class OperationAdd:public Operation{
	double getResult(double a, double b);
};
class OperationSub :public Operation{
	double getResult(double a, double b);
};
class OperationMul :public Operation{
	double getResult(double a, double b);
};
class OperationDiv :public Operation{
	double getResult(double a, double b);
};

double OperationAdd::getResult(double a, double b){
	return a + b;
}

double OperationSub::getResult(double a, double b){
	return a - b;
}

double OperationMul::getResult(double a, double b){
	return a * b;
}

double OperationDiv::getResult(double a, double b){
	if (b == 0)
		return -1;
	return a / b;
}

Operation* OperationFactory::createOperation(char c){
	switch (c)
	{
	case '+':
		return new OperationAdd();
		break;
	case '-':
		return new OperationSub();
		break;
	case '*':
		return new OperationMul();
		break;
	case '/':
		return new OperationDiv();
		break;
	default:
		return NULL;
	}
}
int main(){
	char c;
	double a, b;
	cin >> c >> a >> b;
	OperationFactory f;
	Operation* o = f.createOperation(c);
	cout << o->getResult(a, b);
	return 0;
}