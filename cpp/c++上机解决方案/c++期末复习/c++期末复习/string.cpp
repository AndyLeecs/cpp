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
c盘，用户，用户名（比如我的是17678），appdata，roaming，cppplugin，tmp，exam名字（比如这次是52）
因此要在代码里include  Windows.h头文件
然后在main函数最后加上Sleep(毫秒）
然后你点击test，就可以去上述文件夹复制文件了*/
