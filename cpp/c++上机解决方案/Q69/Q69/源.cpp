#include<iostream>
#include<string>
#include<vector>
using namespace std;
//û�б�Ҫ�����ѭ������һ��ѭ��֮�ھͿ��Խ��������
//������������������ż����
//û�б�Ҫ��vector���һ�ѳ�����ȡ���ֱ�Ӵ���
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
