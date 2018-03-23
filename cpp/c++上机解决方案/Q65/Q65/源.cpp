#include <iostream>
#include<vector>
#include<string>

using namespace std;

string toBinary(_int64 num){
	bool neg = false;
	if (num < 0){
		num = -num;
		neg = true;
	}

	int temp = num % 2;
	string result = "";

	while (1){
		temp = num % 2;
		//	if (temp == 10)
		//		result = "A" + result;
		//	else if (temp == 11)
		//		result = "B" + result;
		//	else if (temp == 12)
		//		result = "C" + result;
		//	else
		//		result = to_string(temp) + result;
		num = num / 2;
		//	if (num == 0)

		result = to_string(temp) + result;

		if (num == 0)
			break;
	}
	if (neg)
		result = "-" + result;
	return result;
}
string threeBig(_int64 num){
	string result = toBinary(num);
	result = result.substr(0, 3);
	return result;
}

	_int64 toNum(string s){
		int sum = 0;
		int t;

		for (_int64 i = 0; i < s.size(); i++)
		{
			
				t = s[i] - '0';
		
			sum = sum * 2 + t;
		}

		return sum;
	}

int main(int argc, char* argv[]){
	vector<_int64> vec;
	_int64 t;
	_int64 size;
	cin >> size;
	int i = 0;
	while (i < size){
		//cin.unget();
		cin >> t;
		vec.push_back(t);
		i++;
	}
	int sum = 0;
	for (_int64 i = 0; i < vec.size(); i++){
		sum += toNum(threeBig(vec[i]));
//		vec[i] = threeBig(vec[i]);

	}

	cout << sum << endl;


}