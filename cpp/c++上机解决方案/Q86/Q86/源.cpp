#include<string>
#include<iostream>
//switch里面的break
//注意不要去改临时变量的值，而是改静态变量或者返回值
using namespace std;
struct square{
	string data;
	bool isMet = false;
};
const int MAX = 100000;
string result[MAX];
int m;
int n;
int indexnow;
square matrix[MAX];
const string state[4] = { "right", "down", "left", "up" };
//
//返回访问方块结果，如果被访问过了，或者出界了，返回false
//否则，访问该方块，并把该方块的值记录在result数组里
bool meetSquare(int x, int y){
	if (x >= m || x<0)
		return false;
	if (y >= n || y<0)
		return false;
	square temp = matrix[x*n + y];
	//cout << temp.data;
	//cout << temp.isMet;
	if (temp.isMet)
		return false;

	//cout << temp.data;
	result[indexnow] = matrix[x*n + y].data;
		matrix[x*n + y].isMet = true;
		//cout << temp.isMet;
		indexnow++;
		return true;
	

}
void getResult(){
	
	int state = 0;
	int x = 0;
	int y = 0;

	bool justChange = false;
	while (true){
		bool con = meetSquare(x, y);
		if ((!con) && (!justChange)){
			state = (state + 1) % 4;
			switch (state){
			case 0:
				x++;
				y++;
				break;
			case 1:
				y--;
				x++;
				break;
			case 2:
				x--;
				y--;
				break;
			case 3:
				y++;
				x--;
				break;
			}
			justChange = true;
		}
		else if ((!con) && justChange)
			break;
		else{
			justChange = false;
			switch (state){
			case 0:
				y++;
				break;
			case 1:
				x++;
				break;
			case 2:
				y--;
				break;
			case 3:
				x--;
				break;
			}
		}
		
	}
}
int main(){
	cin >> m >> n;
	int length = m * n;
	for (int i = 0; i < length; i++){
		cin >> matrix[i].data;
	}
	int index;
	cin >> index;
	getResult();
	//for (int i = 0; i < length; i++){
	//	cout << result[i];
	//}
	//system("pause");
	cout << result[index];
}