#include <iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){
	_int64 order_num;
	cin >> order_num;
	string order;
	string temp;
	string temp_second;
	string s = "";
	for (int i = 0; i < order_num; i++){
		cin >> order;
		if (order == "append"){
			cin >> temp;
			s = s + temp;
		}
		else if (order == "replace"){
			cin >> temp >> temp_second;
			int i = s.find(temp);
			if (i >= 0)
				s.replace(i, temp.size(), temp_second);
		}
		else if (order == "reverse"){
			string rev = "";
			for (int i = 0; i < s.size(); i++)
				rev += s[s.size() - 1 - i];
			s = rev;
		}
		else if (order == "changecase"){
			cin >> temp;
			if (temp == "low"){
				for (int i = 0; i < s.size(); i++)
				if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = (char)(s[i] + 32);
			}
			else
			for (int i = 0; i < s.size(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = (char)(s[i] - 32);
		}

		else if (order == "length"){
			cout << s.size() << endl;
		}
		else if (order == "print"){
			cout << s << endl;
		}
	}
}