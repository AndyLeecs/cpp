#include <iostream>
using namespace std;

int main() {
	int matrix[100][100];
	int m;
	int n;
	int l = 1, i, j, k;
	cin >> m >> n;
	//数组的输入
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	k = 0;
	i = 0;
	j = 0;
	int *num = new int[m*n];//将二维数组转为一维数组，以便计算
	//建立一个无限循环等待break
	for (;;) {
		//数组的处理
		for (; j<n - i; j++) {
			num[k]= matrix[i][j];
			//将二维数组值传入一维数组
			k++;
			//当k标识至数组长度时，break
			if (k == m*n)
				break;
			if (j == n - i - 1) {
				i++;
				l = 2;
				break;
			}
		}
		if (k == m*n)
			break;
		//数组的处理
		for (; i<m - n + 1 + j; i++) {
			num[k] = matrix[i][j];
			k++;
			if (k == m*n)
				break;
	
			if (i == m - n + j) {
				j--;
				l = 3;
				break;
			}
		}
		if (k == m*n)
			break;
		//数组的处理
		for (; j >= m - 1 - i; j--) {
			num[k] = matrix[i][j];
			k++;
			if (k == m*n)
				break;

			if (j == m - i - 1) {
				i--;
				l = 4;
				break;
			}
		}
		if (k == m*n)
			break;
		//数组的处理
		for (; i>j; i--) {
			num[k] = matrix[i][j];
			k++;
			if (k == m*n)
				break;

			if (i == j + 1) {
				j++;
				l = 1;
				break;
			}
		}

		if (k == m*n)
			break;
	}
	int step;
	cin >> step;
	cout << num[step];
	return 0;
}