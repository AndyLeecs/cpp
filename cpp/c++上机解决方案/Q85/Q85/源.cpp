#include<string>
#include<iostream>
using namespace std;

int size;
//数组大小
string list[100];
string translist[100];//移动后的数组，注意不能将一个数组赋值给另一个数组（const 指针）
//数组，开头size个元素是有值的，根据题目要求大小不超过100
//由于不涉及数值计算，认为是字符串数组而非数字数组
int order_num;//命令数量
const string order_list[4] = {"replace","move","translate","print"};//命令
const string direction[2] = { "head", "tail" };//移动的方向

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
			//插入到尾部
			if (a == direction[1]){
				int count = 0;
				int j = 0;
				//记录被移动的数据的位置
				//把其他的数据按顺序排列到新数组中
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

				//记录被移动的数据的位置
				//把其他的数据按顺序排列到新数组中
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
			//向后平移
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