#include<iostream>
#include<string>
using namespace std;
//输出数组函数
void printF(int*num,int length){
	//循环体输出数组
	for (int i = 0; i < length;i++){
		cout << num[i];
		if (i!=length-1){
			cout << " ";//各个数之间打印空格
		}
	}
}
//replace功能函数
int* replace(int*num,int len,int oldValue,int newValue){
	//对数组进行循环
	for (int i = 0; i < len;i++){
		if (num[i]==oldValue){
			num[i] = newValue;
		}//用新的值替换旧的值
	}
	return num;//返回数组
}
//move到数组头部功能函数
int* moveFront(int*num,int location){
	int value = num[location];
	for (int i = location; i >=1;i--){
		num[i] = num[i - 1];
	}
	num[0] = value;
	return num;
}
//move到数组尾部功能函数
int* moveEnd(int*num,int location,int len){
	int value = num[location];
	for (int i = location; i <len-1; i++){
		num[i] = num[i + 1];
	}
	num[len-1] = value;
	return num;
}
//translate到数组尾部功能函数
int* translateTail(int*num, int shift, int len){
	int *newNum = new int[len];//创建一个新数组用于存储
	for (int i = 0; i < len;i++){
		newNum[(i+shift)%len] = num[i];
	}
	//循环算法
	delete num;//释放数组空间
	return newNum;//返回newNum数组
}
//translate到数组头部功能函数
int* translateHead(int*num, int shift, int len){
	int *newNum = new int[len];//创建一个新数组用于存储
	int location;
	for (int i = len-1; i >=0; i--){
		newNum[i] = num[(i+shift)%len];
	}
	//循环算法
	delete num;//释放数组空间
	return newNum;//返回newNum数组
}

int main(){
	int n;
	cin >> n;
	int*num = new int[n];
	for (int i = 0; i < n;i++){
		cin >> num[i];
	}
	int commandNum;
	cin >> commandNum;
	string command;
	//命令的输入判断
	for (int i = 0; i < commandNum; i++){
		cin >> command;
		//当命令为print时
		if (command.compare("print")==0){
			printF(num,n);
			if (i!=commandNum-1){
				cout << endl;
			}
		}
		//当命令为replace时
		else if(command.compare("replace")==0){
			int v1, v2;
			cin >> v1 >> v2;
			num = replace(num,n,v1,v2);
		}
		//当命令为move时
		else if (command.compare("move")==0){
			string dir;
			cin >> dir;
			int v;
			cin >> v;
			//move到数组尾部输入
			if (dir.compare("tail")==0){
				for (int i = 0; i < n;i++){
					if (num[i]==v){
						num = moveEnd(num,i,n);
						//i--;
					}
				}
			}
			//move到数组头部输入
			else{
				for (int i = 0; i < n; i++){
					if (num[i] == v){
						num = moveFront(num, i);
						//i--;
					}
				}
			}
		}
		else{
			string dir;
			int shift;
			cin >> dir;
			cin >> shift;
			if (dir.compare("tail")==0){
				num = translateTail(num,shift,n);
			}
			else{
				num = translateHead(num, shift, n);
			}
		}
	}

	return 1;
}