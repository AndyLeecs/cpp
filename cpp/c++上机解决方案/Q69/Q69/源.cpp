#include<iostream>
#include<string>
#include<vector>
using namespace std;
//没有必要做多次循环，在一次循环之内就可以解决的问题
//先是奇数个，后面是偶数个
//没有必要在vector里存一堆长度再取最大，直接处理
int main(int argc, char* argv[]){
	int n = 0; 
	string s = "";
	cin >> n >> s;

	vector<int> record;
	
	
	
	for (int i = 0; i < s.length(); i++){
		int len = 1;
		int j = 1;
		while (((i - j) >= 0) && ((i + j) < s.length())){
			if (s[i - j] == s[i + j]){
				len++;
				len++;
				j++;
			}
			else
				break;

		}
		record.push_back(len);
	}
	for (int i = 0; i < s.length(); i++){
		int len = 0;
		int j = 1;
		int k = 0;
		while (((i - j) >= 0) && ((i+k) < s.length())){
			if (s[i - j] == s[i+k]){
				len++;
				len++;
				j++;
				k++;
			}
			else
				break;

		}
		record.push_back(len);
	}
	for (int i = 0; i < s.length(); i++){
		int len = 0;
		int j = 1;
		int k = 0;
		while (((i +j) >= 0) && ((i - k) < s.length())){
			if (s[i + j] == s[i - k]){
				len++;
				len++;
				j++;
				k++;
			}
			else
				break;

		}
		record.push_back(len);
	}

	int max = 0;
	for (int i = 0; i < record.size(); i++)
	if (max < record[i])
		max = record[i];

	cout << max;

}
