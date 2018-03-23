#include<iostream>
using namespace std;


class Chess{
public:
	int isO;//0表示没有棋子，1表示是O，2表示是X
	//int x;
	//int y;
	Chess(int b){ isO = b; }
	//Chess(int x, int y){ this->x = x; this->y = y; }
};
class Board{
public:
	int n;//n*n
	int bar;
	int** list;

	
};
int n;//n*n
int bar;
int** list;
bool check(int x,int y){
	bool over = false;
	int temp = 1;
	int chess = list[x][y];
	//横向
	int a = x-1;
	int b = y;
	while (a >= 0 && b >= 0 && a < n && b < n && list[a][b] == chess){
		temp++;
		a--;
	}
	a = x + 1;
	while ( a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		a++;
	}
	if (temp >= bar){
		over = true;
		return over;
	}
	//纵向
	temp = 1;
	a = x ;
	b = y - 1;
	while (a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		b--;
	}
	b = y + 1;
	while (a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		b++;
	}
	if (temp >= bar){
		over = true;
		return over;
	}
	//斜
	temp = 1;
	a = x-1;
	b = y - 1;
	while (a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		a--;
		b--;
	}
	a=x + 1;
	b = y + 1;
	while ( a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		a++;
		b++;
	}
	if (temp >= bar){
		over = true;
		return over;
	}
	//斜
	temp = 1;
	a = x - 1;
	b = y + 1;
	while (a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		a--;
		b++;
	}
	a = x + 1;
	b = y - 1;
	while (a >= 0 && b >= 0 && a < n && b < n&& list[a][b] == chess){
		temp++;
		a++;
		b--;
	}
	if (temp >= bar){
		over = true;
	}
	return over;
}
int main(){
//	Board* b = new Board();
	cin >> n;
	list = new int*[n];
	for (int i = 0; i < n; i++){
		list[i] = new int[n];
		for (int j = 0; j < n; j++)
			list[i][j] = 0;
	}
	cin >> bar;
	int c = 2;
	bool over = false;
	int num = 0;
	while (!over&&num!=n*n){
		int x, y;
		c==1 ? c =2 : c = 1;
		num++;
		cin >> x >> y;
		list[x][y] = c;
		over = check(x,y);
	}
	if (num == n*n && bar > 1){
		cout << "Dogfall";
	}
	else if(bar == 1){
		cout << "O Success";
	}
	else{
		c == 1 ? cout << "O Success" : cout << "X Success";
	}
//	system("pause");
//	Sleep(2000);
	return 0;
}