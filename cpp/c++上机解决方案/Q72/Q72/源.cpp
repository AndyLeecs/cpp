#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){


	int sum = 0;

	string rome = "";
	cin >> rome;

	string param = "IVXLCDM";//˳��
//	bool neg = false;//���Ƿ���Ҫ��

	for (int i = 0; i < rome.size(); i++){
		if (rome[i] == 'M')
			sum += 1000;
		else if (rome[i] == 'V')
			sum += 5;
		else if (rome[i] == 'L')
			sum += 50;
		else if (rome[i] == 'D')
			sum += 500;
		else if (i + 1 < rome.size() && param.find(rome[i]) < param.find(rome[i + 1])){//�ڴ�����ǰ��
			if (rome[i] == 'I')
				sum -= 1;
			if (rome[i] == 'X')
				sum -= 10;
			if (rome[i] == 'C')
				sum -= 100;
		}
		else{
			if (rome[i] == 'I')
				sum += 1;
			if (rome[i] == 'X')
				sum += 10;
			if (rome[i] == 'C')
				sum += 100;
		}



	}
	cout << sum;
//	system("pause");
	return 0;
}

