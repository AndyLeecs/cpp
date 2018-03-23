#include<iostream>
#include<string>
#include<vector>

using namespace std;
class hero{
public:
	string name;
	int hp;
	int atk;
	virtual void power() = 0;
	//·µ»ØÊÇ·ñËÀÍö
	virtual bool attacked(int atk) = 0;
	bool isAlive(){
		return hp > 0;
	}
};
class Warrior :public hero{
public:
	Warrior(){ name = "Warrior", hp = 12; atk = 2; }
	void power(){
		hp++;
	}
	bool attacked(int atk){
		hp -= atk;
		if (hp <= 0)
			return true;//ËÀÍö
		else
			return false;
	}
};
class Magician :public hero{

public:
	Magician(){ name = "Magician", hp = 2; atk = 6; }
	bool first = true;
	void power(){
	}
	bool attacked(int atk){
		if (first == true){
			first = false;
			return false;
		}

		else{
			hp -= atk;
			if (hp <= 0)
				return true;//ËÀÍö
			else
				return false;
		}
	}
};
class Leader :public hero{
public:
	Leader(){ name = "Leader", hp = 6; atk = 6; }
	void power(){
		atk++;
	}
	bool attacked(int atk){
		hp -= atk;
		if (hp <= 0)
			return true;//ËÀÍö
		else
			return false;
	}
};
class heroFactory{
public:
	static hero* createHero(int num){
		switch (num){
		case 1:return new Warrior(); break;
		case 2:return new Magician(); break;
		case 3:return new Leader(); break;
		}
	}
};


void print(vector<hero*> v){
	for (int i = 0; i < v.size(); i++)
	{
		
		cout << v[i]->name << " " << v[i]->atk << " " << v[i]->hp;
		if (i != v.size() - 1)
			cout << endl;
	}
}
int main(){
	int n;
	cin >> n;
	heroFactory f;
	vector<hero*> va;
	vector<hero*> vb;
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		va.push_back(f.createHero(temp));
	}
	for (int i = 0; i < n; i++){
		cin >> temp;
		vb.push_back(f.createHero(temp));
	}
	while (va.size()>0 && vb.size()>0){
		vb[0]->attacked(va[0]->atk);
		va[0]->attacked(vb[0]->atk);
		while (va[0]->isAlive() && vb[0]->isAlive()){
			va[0]->power();
			vb[0]->power();
			vb[0]->attacked(va[0]->atk);
			va[0]->attacked(vb[0]->atk);
		}
		if (!va[0]->isAlive() && vb[0]->isAlive()){
			va.erase(va.begin());
			vb[0]->power();
		}
		else if (!vb[0]->isAlive() && va[0]->isAlive())
		{
			vb.erase(vb.begin());
			va[0]->power();
		}
		else{
			va.erase(va.begin());
			vb.erase(vb.begin());
		}
	}
	
	if (va.size() > 0){
		print(va);
	}
	else if(vb.size()>0){
		print(vb);
	}
	else{
		cout << "All Dead";
	}

///	system("pause");
	return 0;
}