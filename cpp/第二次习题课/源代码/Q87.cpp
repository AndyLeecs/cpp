#include<iostream>
using namespace std;

//��̬�滮����
int sum(int**data,int **value,int x,int y,int len){
	//cout << " x: " <<x<< " y" <<y<< " data[x][y]" << data[x][y] << "  value[x][y]"<<value[x][y]<< endl;
	if (value[x][y]!=0){
		return value[x][y];
	}
	else if (x==0&&y==0){
		value[x][y] = data[x][y];
		return value[x][y];
	}
	else if (x==y){//�ھ���ĶԽ�����,ֻ����������
		value[x][y] = sum(data,value,x-1,y-1,len)+data[x][y];
	}
	else if (x !=0 && y==0){//�����һ����ֻ����������
		value[x][y] = sum(data, value, x-1, y, len)+data[x][y];
	}
	else{
		//ȡ����������ֵС��
		int left = sum(data, value, x - 1, y-1, len);//����
		int right = sum(data, value, x-1, y , len);//����
		value[x][y] =(left > right ? right : left) + data[x][y];
	}
	return value[x][y];
}

int main(){
	int row, column;
	cin >> row;
	column = row;

	//����һ  
	//����ռ�  
	int ** a = new int *[row];
	int **value = new int*[row];
	for (int i = 0; i < row; i++){
		a[i] = new int[column];
		value[i] = new int[column];
	}


	//��ʼ������
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