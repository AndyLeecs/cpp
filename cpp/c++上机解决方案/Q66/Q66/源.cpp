#include <iostream>
#include <string>
using namespace std;
string toBinary(_int64 num){
	


	int temp = num % 2;
	string result = "";

	while (1){
		temp = num % 2;
		num = num / 2;
		result = to_string(temp) + result;

		if (num == 0)
			break;
	}

	return result;
}
int main(int argc, char* argv[]){
	string ini;
	cin >> ini;

	int n = ini.size();
	int k = 0;
	while (n + k + 1 >= pow(2, k)){
		k++;
	}
	//ע�⺣��У����ı�ŷ�ʽ���Ǵ�1��ʼ��Ŷ����Ǵ�0��ʼ���
	string result = "";

	string temp = ini;

	string count[100];//��¼ÿһλ���ļ���ԭ����λʹ�ù���ʹ��Ϊ1��δʹ��Ϊ0
	string empty = "";
	for (int i = 0; i < n + k + 1; i++)
		empty = empty + "0";

	for (int i = 0; i < k; i++){
		
			count[i] = empty;
	}

	//���
	for (int i = 0; i < n + k; i++){
		//��2����
		string now_bit = "";

		if (!(i&(i + 1)))
			result += '0';
		else{
			result += temp[0];
			temp = temp.substr(1, temp.size() - 1);

			int now = i+1;
			now_bit = toBinary(now);
			//�����λ��1��˵����ʹ�ù������count����
			for (int j = now_bit.size() - 1; j >= 0; j --)
			if (now_bit[j] == '1')
				count[now_bit.size() - 1 - j][i] = '1';
			
			

		}
	}

	//��λ���
	
	for (int i = 0; i < k; i++){
		int nor = 0;
		for (int j = 0; j < n + k ; j++)
		if (count[i][j] == '1')
		if (result[j] == '1')
			nor = nor ^ 1;
		else
			nor = nor ^ 0;
		if (nor != 0)
			result[(int)pow(2, i) - 1] = '1';
		
	}
	cout << result;
	
}
