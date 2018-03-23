#include <iostream>
#include<math.h>
using namespace std;

class GPU{
	int price, hashRate;
public:
	GPU(){ price = 0; hashRate = 0; }
	GPU(int price, int hashRate){ price = price, hashRate = hashRate; }
	int getPrice(){ return price; }
	int getHashRate(){ return hashRate; }
	virtual double calculate() = 0;
	friend istream & operator >> (istream &i, GPU&g);
};

class GPU1 :public GPU{
	double power = 16.2;
public:
	GPU1() :GPU(){}
	GPU1(int price, int hashRate) :GPU(price,hashRate){}
	double calculate()override;
};
class GPU2 :public GPU{
	double power = 28.8;
public:
	GPU2() :GPU(){}
	GPU2(int price, int hashRate) :GPU(price, hashRate){}
	double calculate()override; 
};
class GPU3 :public GPU{
	double power = 19.44;
	public:
	GPU3() :GPU(){}
	GPU3(int price, int hashRate) :GPU(price, hashRate){}
	double calculate()override;
};

double GPU1::calculate(){
	
		int hashRate = getHashRate();
		return hashRate*0.02 - power;
	
}
double GPU2::calculate(){

	int hashRate = getHashRate();
	return hashRate*0.02 - power;

}
double GPU3::calculate(){

	int hashRate = getHashRate();
	return hashRate*0.02 - power;

}
istream & operator >> (istream &i, GPU&g){
	int price, hashRate;
	i >> price >> hashRate;
	g.price = price;
	g.hashRate = hashRate;
	return i;
}

int main(){
	GPU1 g1;
	cin >> g1;
	GPU2 g2;
	cin >> g2;
	GPU3 g3;
	cin >> g3;

	double total = g1.calculate() + g2.calculate() + g3.calculate();
	int price = g1.getPrice() + g2.getPrice() + g3.getPrice();
	if (total <= 0)
		cout<< -1;
	else{
		//cout << total<<endl; 
		//cout << price<<endl;
		int result = ceil(price / total);

		cout << result;
	}
	//system("pause");
	return 0;
}