#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	long long x;
	long long y;
	long long pow = 1;
	cin >> x >> y;

	if (x == 0){
		cout << 0;
	}
	else if (y == 0 && x != 0)
		cout << 1;
	else if (y == 1)
		cout << 1;
	else if (y == -1)
		cout << -1;
	else if (y > 0)
	{
		for (int i = 0; i < y; i++){
			pow *= x;
		}
		cout << pow;

	}
	else
	{
		double xplus = 1 / x;
		y = -y;
		for (int i = 0; i < y; i++){
			pow *= xplus;
		}
		cout << pow;
	}

}