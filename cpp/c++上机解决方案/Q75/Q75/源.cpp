#include<fstream>
#include<iostream>

using namespace std;

int main(){
	const int MAX = 500;
	//接入输入流
	ofstream filestream;
	filestream.open("d:\\c++\\75.txt", ios::out | ios::app);//app表示追加形式
	//计算输入流长度
	for (int i = 0; i < MAX; i++){
		char x[MAX];
		cin.getline(x, MAX);

		//用filestream而不是cin输出
		filestream << x << "\n";
	}
	//关闭输入流
	filestream.close();
}



