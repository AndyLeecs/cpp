#include<iostream>
using namespace std;
class food{
	//碳水化合物，蛋白质，膳食纤维，脂肪
	
public:
	double c, p, d, f;
	food(){};
	food(double c, double p, double d, double f){ this->c = c; this->p = p; this->d = d; this->f = f; };
};
class a :public food{
public:
	a() :food(16.2, 3.7, 0, 0){};
};

class b : public food{
public:
	b() :food(1.8,17.5,0,7.2){};
};

class c : public food{
public:
	c() :food( 0.2, 0.4, 3.6, 0 ){};
}; 

class d : public food{
public:
	d() :food(12.3,5.7,7.3,3){};
};

class e :public food{
public :
	e() :food(6.9, 9, 0, 9.3){};
};

class f :public food{
public:
	f() :food(2.1, 0.8, 4.3, 0){};
};

const food* sort[6];
class diet{
	food list[3];
	int index = 0;
public:
	void operator+=(food e){
		list[index] = e;
		index++;
	}
	void if_healthy(){
		if (list[0].c + list[1].c + list[2].c >= 13.3)
		if (list[0].p + list[1].p + list[2].p >= 13.5)
		if (list[0].d + list[1].d + list[2].d >= 3.3)
		if (list[0].f + list[1].f + list[2].f <= 10.3){
			cout << "healthy" << endl;
			return;
		}

		cout << "unhealthy" << endl;
		
	}
};
int main(){
	sort[0] = new a();
	sort[1] = new b();
	sort[2] = new c();
	sort[3] = new d();
	sort[4] = new e();
	sort[5] = new f();
	int x, y, z;
	cin >> x >> y >> z;
	if (x > 6 || y > 6 || z > 6)
	{
		cout << "-1" << endl;
		return 0;
	}
	diet* it = new diet();
	*it += *sort[x - 1];
	*it += *sort[y - 1];
	*it += *sort[z - 1];
	it->if_healthy();
//	system("pause");
 	return 0;
}