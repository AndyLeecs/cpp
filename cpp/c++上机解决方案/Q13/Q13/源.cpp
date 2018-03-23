#include <iostream>
#include<string>
#include<sstream>

using namespace std;

string f(int x){
	if (x == 1)
		return"1/1";
	int upper = 1;
	int down = 1;
	bool down_inc = true;//标记是沿分母增长方向变化

	int i = 1;
	while (i <= x){
		while (upper != 0 && down != 0){
			if (down_inc)
			{
				upper--;
				down++;

			}
			else
			{
				upper++;
				down--;
			}
			i++;
			if (i == x && upper != 0 && down != 0){
				//				stringstream ss;
				//				string str1;
				//				string str2;
				//			ss << upper;
				//				ss >> str1;
				//				ss << down;
				//				ss << str2;

				//				str1 = to_string(upper);
				//				str2 = to_string(down);
				return to_string(upper)+'/'+to_string( down);

				//				string str =  "/" ;
		
			}
		}
		if (down_inc){
			upper++;

		}
		else
			down++;
		down_inc = !down_inc;
		if (i == x && upper != 0 && down != 0)
			//				stringstream ss;
			//				string str1;
			//				string str2;
			//			ss << upper;
			//				ss >> str1;
			//				ss << down;
			//				ss << str2;

			//				str1 = to_string(upper);
			//				str2 = to_string(down);
			return to_string( upper)+  '/'+to_string( down);
			


	}
	return to_string(upper) + '/' + to_string(down);
}

int main(int argc, char* argv[]){
	int x;
	cin >> x;
	cout << f(x);
//	f(x);

}