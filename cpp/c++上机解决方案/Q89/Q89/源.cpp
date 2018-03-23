#include<iostream>
#include<string>
//initializing first
//使用if-else还是连续的if
using namespace std;
int n;
string node1;
int node1num;
int node2num;
string node2;
string list[15];
bool getttt = false;
int result = -1;


int getGap(int a , int b ,int gap){
	if (a >= b && a - 1 >= b){
		if (getttt = false)
			return -1;
		else
			return result;
	}
		
	if (b == (2 * a) || b == (2 * a + 1)){
		getttt = true;
		result = gap;
		return gap;
	}
	else{
		gap += 1;
		getGap(2 * a, b, gap);
		getGap(2 * a + 1, b,gap);
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> list[i];
	}
	cin >> node1 >> node2;
	
	for (int i = 1; i <= n; i++){
		if (list[i] == node1)
			node1num = i;
		if (list[i] == node2)
			node2num = i;
		if (node1num != 0 && node2num != 0)
			break;
	}

	
	if (node1num == node2num)
	{
		cout << 0;
		return 0;
	}
	else if (node1num > node2num){
		int temp = node1num;
		node1num = node2num;
		node2num = temp;
		
	}

	//看两个节点是否满足左右子树关系
	cout << getGap(node1num, node2num,1);
//system("pause");


}