#include<iostream>
using namespace std;

class ham{
	
public:
virtual int getPrice() = 0;
	virtual void setPrice(int) = 0;
};
class i_ham : public ham{
	int price = 0;
public:
	int getPrice(){ return this->price; }
	void setPrice(int price){ this->price = price; }
};
class meat : public ham{
	int category;
	int num;
	ham* h;
public:
	meat(ham* h, int i, int j){ this->h = h; this->category = i; this->num = j; }
	int getPrice(){ return h->getPrice(); }
	void setPrice(int k){
		int temp = k;
		for (int i = 0; i < num; i++){
			if (category == 1){
				temp = temp + 10;
				h->setPrice(temp);
			}

			else if (category == 2){
				temp = temp + 8;
				h->setPrice(temp);
			}
			else
			{
				temp = temp + 7;
				h->setPrice(temp);
			}
		}
	}
};

class vega : public ham{
	int category;
	int num;
	ham* h;
public:
	vega(ham* h, int i, int j){ this->h = h; this->category = i; this->num = j; }
	int getPrice(){ return h->getPrice(); }
	void setPrice(int k){
		int temp = k;
		for (int i = 0; i < num; i++){
			if (category == 1){
				temp = temp + 4;
				h->setPrice(temp);
			}
			else
			{
				temp = temp + 3;
				h->setPrice(temp);
			}
		}
	}
};
int main(){
	ham* h = new i_ham();
	int catemeat, nummeat, catevega, numvega;
	cin >> catemeat >> nummeat >> catevega >> numvega;
	ham* a = new meat(h, catemeat, nummeat);
	ham* b = new vega(a, catevega, numvega);
	b->setPrice(b->getPrice());
	cout << b->getPrice();
//	system("pause");
	return 0;
}