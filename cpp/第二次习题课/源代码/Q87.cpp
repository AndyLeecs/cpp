#include<iostream>
using namespace std;

//动态规划函数
int sum(int**data,int **value,int x,int y,int len){
	//cout << " x: " <<x<< " y" <<y<< " data[x][y]" << data[x][y] << "  value[x][y]"<<value[x][y]<< endl;
	if (value[x][y]!=0){
		return value[x][y];
	}
	else if (x==0&&y==0){
		value[x][y] = data[x][y];
		return value[x][y];
	}
	else if (x==y){//在矩阵的对角线上,只能往左上走
		value[x][y] = sum(data,value,x-1,y-1,len)+data[x][y];
	}
	else if (x !=0 && y==0){//最左边一个，只能往右上走
		value[x][y] = sum(data, value, x-1, y, len)+data[x][y];
	}
	else{
		//取左上与右上值小的
		int left = sum(data, value, x - 1, y-1, len);//左上
		int right = sum(data, value, x-1, y , len);//右上
		value[x][y] =(left > right ? right : left) + data[x][y];
	}
	return value[x][y];
}

int main(){
	int row, column;
	cin >> row;
	column = row;

	//方法一  
	//申请空间  
	int ** a = new int *[row];
	int **value = new int*[row];
	for (int i = 0; i < row; i++){
		a[i] = new int[column];
		value[i] = new int[column];
	}


	//初始化三角
	for (int i = 0; i < row;i++){
		for (int j = 0; j < i + 1;j++){
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < row; j++){
			value[i][j]=0;
		}
	}


	for (int i = 0; i < row;i++){
		sum(a, value, row-1, i, row);
	}

	int min = value[row-1][0];
	for (int i = 0; i < row; i++){
		if (value[row-1][i]<min){
			min = value[row-1][i];
		}
	}
	cout << min;
	return 1;
}