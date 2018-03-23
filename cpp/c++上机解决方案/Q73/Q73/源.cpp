#include<iostream>
#include<string>
using namespace std;
const	string array[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
void print(string before, string s){
	int index = (int)(s[0] - '0');
	
	for (int i = 0; i < array[index].size(); i++){
		string reserve = before + array[index][i];
		if (s.size()>1){
			string temp  = s.substr(1);
			print(reserve,temp);
		}
else
		cout << reserve<<endl;
	}
}
int main(int argc, char*argv[]){

	string s;
	cin >> s;
	print("",s);

//	system("pause");
	return 0;
}