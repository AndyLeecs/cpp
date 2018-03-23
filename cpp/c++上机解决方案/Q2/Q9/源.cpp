#include <iostream>
using namespace std;
bool prime(long long x){
	if (x == 1)
		return false;
	long long y = x / 2;
	while (y > 1){
		if (x%y == 0)
			return false;
		y--;
	}
	return true;
}
int main(int argc, char* argv[]){
	long long x;
	long long y;
	long long result = 0;

	cin >> x;
	cin >> y;
	for (long long i = x; i <= y; i++){
		if (prime(i)){
			result += i;
		}
	}

	cout << result;
}


