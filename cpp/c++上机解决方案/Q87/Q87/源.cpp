//#include<string>
#include<iostream>
//��������
//string ת int n = atoi(str);
//�ݹ���ȵ�����
//string���ʹ�ûή��Ч�ʵ��³�ʱ
using namespace std;
int n;
const int MAX = 1300;

int last[MAX];
int map[MAX];

int sum;
//string tempmap;
char tempmap[100];

//���map

//void getRoad(int indexi ,  int indexj ,int sumtemp){
//	//��ü����˸ýڵ�֮���
//	sumtemp = map[indexi][indexj] + sumtemp;
//	if (indexi == (n - 1)){
//		//roads[road_index] = sumtemp;
//		//road_index++;
//		if (first){
//			sum = sumtemp;
//			first = false;
//		}
//		else if (sum > sumtemp)
//			sum = sumtemp;
//	}
//	else
//	{	getRoad(indexi + 1, indexj, sumtemp);
//		getRoad(indexi + 1, indexj + 1, sumtemp);
//	}
//}
int main(){
	cin >> n;
	//���map	
	//ע���string����int
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			cin >> tempmap;
//			map[j] = atoi(tempmap.c_str());//ע��stringתc����ַ���
			map[j] = atoi(tempmap);
	
			if (j == 0)
				map[j] += last[j];
			else if (j == i)
				map[j] += last[j - 1];
			else{
				if (last[j] < last[j - 1])
					map[j] += last[j];
				else
					map[j] += last[j - 1];


			}

		}
		for (int k = 0; k <= i; k++)
			last[k] = map[k];
	}
	//���road,
//	getRoad(0, 0, 0);
	sum = map[n - 1];
	for (int i = 0; i < n; i++){
		if (sum > map[i])
			sum = map[i];
	}
	
	cout << sum << endl;
//	system("pause");

}