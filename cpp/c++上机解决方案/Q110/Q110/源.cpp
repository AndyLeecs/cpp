#include<iostream>
using namespace std;

class Point{
	int x = 0, y = 0, z = 0;
public:
	int getX(){ return x; };
	int getY(){ return y; };
	int getZ(){ return z; };
	Point(int x, int y, int z) :x(x), y(y), z(z){};
	friend Point& operator ++ (Point&p);
	Point& operator + (Point&p);
	friend ostream& operator << (ostream& o, Point&p);

};

Point& operator++(Point&p){
	p.x++;
	p.y++;
	p.z++;
	return p;
}

Point& Point::operator+(Point& p){
	p.x = x + p.x;
	p.y = y + p.y;
	p.z = z + p.z;
	return p;
}

ostream& operator << (ostream& o, Point &p){
	cout << "x:" << p.getX() << ",y:" << p.getY() << ",z:" << p.getZ();
	return o;
}
int main(){
	int x, y, z;
	cin >> x >> y >> z;
	Point a(x, y, z);
	cin >> x >> y >> z;
	Point b(x, y, z);
	cout << (++a)<<endl;
	cout << a + b;
	return 0;
}
