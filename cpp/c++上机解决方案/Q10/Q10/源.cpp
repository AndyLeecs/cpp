#include <iostream>
using namespace std;

long long f(long n){

	__int64 result;
	__int64 temp1 = 0;
	__int64 temp2= 1;

	if ((int)n == 0)
		return 0;
	if ((int)n == 1)
		return 1;


	for (long i = 2; i <= n; i++){
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
	}
	return result;
}
int main(int argc, char*argv[]){
	long n;
	cin >> n;
	cout << f(n);
}