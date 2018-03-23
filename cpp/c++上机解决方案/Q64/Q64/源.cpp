#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//13进制转十进制
_int64 toNum(string s){
	int sum = 0;
	int t;
//	reverse(s.begin(), s.end());

	/*for (_int64 i = s.size()-1; i >= 0; i--){
		switch (s[i]){
		case'A':
			sum += 10 * pow(13, s.size()-1-i);
			break;
		case'B':
			sum += 11 * pow(13, s.size() - 1 - i);
			break;
		case'C':
			sum += 12 * pow(13, s.size() - 1 - i);
			break;
		default:
			sum += (int)(s[i] - '0')*pow(13, s.size() - 1 - i);
			break;
		}
	}
*/
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
			t = s[i] - '0';
		else
			t = s[i] - 'A' + 10;
		sum = sum * 13 + t;
	}

	return sum;
}

//十进制转十三进制
string toString(_int64 num){
	bool neg = false;
	if (num < 0){
		num = -num;
		neg = true;
	}

		int temp = num % 13;
		string result = "";

		while (1){
			temp = num % 13;
			//	if (temp == 10)
			//		result = "A" + result;
			//	else if (temp == 11)
			//		result = "B" + result;
			//	else if (temp == 12)
			//		result = "C" + result;
			//	else
			//		result = to_string(temp) + result;
			num = num / 13;
			//	if (num == 0)
			//		break;
			if (temp <= 9)
				result = to_string(temp) + result;
			else
				result = (char)(temp - 10 + 'A') + result;
			if (num == 0)
				break;
		}
		if (neg)
			result = "-" + result;
		return result;
	}


int main(int argc, char*argv[])
{
	string order;
	string ope_first;
	string ope_second;

	cin >> order >> ope_first >> ope_second;

	int first = toNum(ope_first);
	int second = toNum(ope_second);
	int sum = 0;

	if (order == "add"){
		sum = first + second;
	}
	else if (order == "sub"){
		sum = first - second;
//		sum = second - first;
	}
	else if (order == "mul"){
		sum = first * second;
	}

	string str = toString(sum);
	cout << str << endl;

}