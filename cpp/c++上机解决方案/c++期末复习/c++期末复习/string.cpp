#include<string>
#include<iostream>
#include<fstream>

using namespace std;

ifstream f("in.txt");
void main(){
	cin.rdbuf(f.rdbuf());

	int length();
	bool empty();
	string &append(const string &s, int pos, int n);
	string substr(int pos = 0, int npos = n);
	int find(const string &s, int pos = 0) const;
	string &replace(int p0, int n0, const string &s);
	string &insert(int p0, const string &s);
	string &erase(int pos = 0, int n = npos);
	cin.getline();
	getline(cin, str);
	int x = atoi(s.c_str());
	string s = to_string(x);
}



/*
c�̣��û����û����������ҵ���17678����appdata��roaming��cppplugin��tmp��exam���֣����������52��
���Ҫ�ڴ�����include  Windows.hͷ�ļ�
Ȼ����main����������Sleep(���룩
Ȼ������test���Ϳ���ȥ�����ļ��и����ļ���*/
