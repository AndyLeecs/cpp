#include<fstream>
#include<iostream>

using namespace std;

int main(){
	const int MAX = 500;
	//����������
	ofstream filestream;
	filestream.open("d:\\c++\\75.txt", ios::out | ios::app);//app��ʾ׷����ʽ
	//��������������
	for (int i = 0; i < MAX; i++){
		char x[MAX];
		cin.getline(x, MAX);

		//��filestream������cin���
		filestream << x << "\n";
	}
	//�ر�������
	filestream.close();
}



