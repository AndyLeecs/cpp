#include<iostream>
#include<string>
using namespace std;
int n;
string list[500];
//排序算法使用快排
//返回值为bool，尽量先做判断
int getIndex(char a){
	
	if (a >= 'a' && a <= 'z')
		return 2 * (a - 'a');
	else
		return 2*(a - 'A')+1;
}
bool isForwardThanChar(char a, char b){
	if (a == b)
		return true;
	int aa = getIndex(a);
	int bb = getIndex(b);
	if (aa > bb)
		return false;
	else
		return true;
}
bool isForwardThan(string a, string b){
	int alength = a.length();
	int blength = b.length();
	if (a == b)
		return true;
	else if (alength < blength)
		return true;
	else if (alength > blength)
		return false;
	else{
		for (int i = 0; i < alength; i++){
			if (a[i] != b[i])
			if (isForwardThanChar(a[i], b[i]))
				return true;//最后AC的点，就是尽量早跳出循环，直接return true 而不是在循环结束之后再return true
			else
				return false;
		}
	}
	return true;
}

//void sort(){
//	for (int k = 0; k < n ;k ++)
//	for (int i = k+1; i < n; i++)
//	{
//		if (isForwardThan(list[k], list[i]))
//		{
//			string temp = list[i];
//			list[i] = list[k];
//			list[k] = temp;
//		}
//	}
//}

void sort(int left, int right){
	int i, j;
	string temp;
	string base;
	if (left > right)
		return;

	base = list[left];//存基准
	i = left;
	j = right;

	while (i != j){
		while (isForwardThan(base,list[j]) && i < j){
			j--;

		}
		while (isForwardThan(list[i],base) && i < j){
			i++;
		}

		if (i < j){
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}


	
	list[left] = list[i];
	list[i] = base;

	sort(left, i - 1);
	sort(i + 1, right);

}


int main(){
	cin >> n ;
	cin.get();

	for (int i = 0; i < n; i++){
		cin>>list[i];
		//cin >> p;
		//list[i] = p;
	}

	sort(0,n-1);

	for (int i = 0; i < n; i++)
		cout << list[i]<<endl;
//	system("pause");
}