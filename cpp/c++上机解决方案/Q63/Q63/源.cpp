#include <iostream>
#include<vector>
#include<string>
using namespace std;

void print(vector<int> vec, int size){
	for (int i = 0; i < size; i++){
		cout << vec[i];
		if (i != (size - 1))
			cout << " ";
		else
			cout << endl;
	}
	

}
int main(int argc, char*argv[]){
	int n = 0;
	cin >> n;
	vector<int> vec;
//	_int64 temp;
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		vec.push_back(temp);
	}

//	_int64 order_num;
	int order_num;
	cin >> order_num;

	string order;
//	_int64 order_op;//²Ù×÷Êý
	int order_op;

	for (int i = 0; i < order_num; i ++){
//	for (_int64 i = 0; i < order_num; i++){
		cin >> order;
		if (order == "add"){
			cin >> order_op;

			for (int i = 0; i < n; i++){
				vec[i] += order_op;
			}
		}
		else if (order == "sub"){
			cin >> order_op;

			for (int i = 0; i < n; i++){
				vec[i] -= order_op;
			}
	}
		else if (order == "mul"){
			cin >> order_op;

			for (int i = 0; i < n; i++){
				vec[i] *= order_op;
			}
		}

		else if (order == "pow"){
			cin >> order_op;

			for (int i = 0; i < n; i++){
				int temp = vec[i];
			for (int j = 1; j < order_op; j++){
				vec[i] *= temp;
			}
		}
//			for (_int64 j = 1; j < order_op; j++)
				


		}

		else if (order == "sqa"){
//			_int64 sum = 0;
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += vec[i] *vec[i];
			cout << sum << endl;
		}

		else if (order == "print"){
			print(vec, n);
		}
	}

}
