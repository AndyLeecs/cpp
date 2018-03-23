#include<iostream>
#include<string>
//#include<vector>
using namespace std;

int main(int argc, char* argv[]){
//	vector<string> vec;
	string temp;
//	char temp[20];
//	while (cin.get()!='\n'){
//		cin.unget();
//		cin >> temp;
////		vec.push_back(temp);

	getline(cin, temp);

//_int64 n = vec.size();
//	string result = vec[n - 1];
//	n = result.size();
	int n = temp.find_last_of(' ');
	string result = temp.substr(n + 1);
	cout << result.size() << endl;
}