#include<string>
#include<iostream>
using namespace std;

int size;
//�����С
string list[100];
string translist[100];//�ƶ�������飬ע�ⲻ�ܽ�һ�����鸳ֵ����һ�����飨const ָ�룩
//���飬��ͷsize��Ԫ������ֵ�ģ�������ĿҪ���С������100
//���ڲ��漰��ֵ���㣬��Ϊ���ַ������������������
int order_num;//��������
const string order_list[4] = {"replace","move","translate","print"};//����
const string direction[2] = { "head", "tail" };//�ƶ��ķ���

void Input(){
	cin >> size;
	for (int i = 0; i < size; i++){
		cin >> list[i];
		translist[i] = list[i];
	}

	cin >> order_num;
	string temp;
	for (int index = 0; index < order_num; index++){
		for(int i = 0; i < size; i++){
			list[i] = translist[i];
		}
		cin >> temp;
		if (temp == order_list[0]){
			string a;
			string b;
			cin >> a >> b;

			for (int i = 0; i < size; i++){
				if (list[i] == a){
					translist[i] = b;
				}
				else{
					translist[i] = list[i];
				}
			}

		}
		else if (temp == order_list[1]){
			string a;
			string b;
			cin >> a >> b;
			//���뵽β��
			if (a == direction[1]){
				int count = 0;
				int j = 0;
				//��¼���ƶ������ݵ�λ��
				//�����������ݰ�˳�����е���������
				for (int i = 0; i < size; i++){
					if (list[i] == b)
						count++;
					else{
						translist[j] = list[i];
						j++;
					}
				}
				for (int i = 0; i < count; i++){
					translist[j] = b;
					j++;
				}

			}
			else{
				int count = 0;

				//��¼���ƶ������ݵ�λ��
				//�����������ݰ�˳�����е���������
				for (int i = 0; i < size; i++){
					if (list[i] == b)
						count++;
				}
				int j = 0;
				for (int i = 0; i < count; i++){
					translist[j] = b;
					j++;
				}
				for (int i = 0; i < size; i++){
					if (list[i] == b)
						continue;
					else{
						translist[j] = list[i];
						j++;
					}
				}
			}

		}
		else if (temp == order_list[2]){
			string a;
			int b;
			cin >> a >> b;
			//���ƽ��
			if (a == direction[1]){
				int i = 0;
				while ((i + b) < size){
					
					translist[i + b] = list[i];
					i++;
				}
				

				for (int j = 0; j < b; j++){
					translist[j] = list[i];
					i++;


				}
			}
		
		else{
			
			for (int i = 0; i < size - b; i++)
				translist[i] = list[i + b];
			int j = 0;
			for (int i = size - b; i < size; i++){
				translist[i] = list[j];
				j++;
			}

		}
	}
		else if (temp == order_list[3]){
			for (int i = 0; i < size; i++){
				cout << translist[i] << " ";
			}cout << " ";
		}
	}
}
int main(){
	Input();
}