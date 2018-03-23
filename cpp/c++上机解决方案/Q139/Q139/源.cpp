#include<iostream>
#include<vector>
#include<string>


using namespace std;
class p{
public:
	int id = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	bool reverse = false;
	bool single = false;
	double cal = 0;

};

double suan(int a, int b, int c){
	return a*0.299 + b*0.587 + c*0.114;
}

bool operator > (p&a, p&b){
	if (a.cal < b.cal){
		return false;
	}
	else if(a.cal == b.cal){
		if (a.id < b.id)
			return false;
	}

	return true;
}
template<typename T>
void sort(T A[]){
	for (int i = 0; i < max; i++)
	for (int j = 0; j < max - i; j++){
		if (A[j]>A[j + 1]){
			T t = A[j];
			A[j] = A[j + 1];
			A[j + 1] = t;
		}
	}
}

const int max = 2000;
p array[max];

int main(){
	//ifstream in("d:\\c++\\in.txt");
	//streambuf *cinbuf = cin.rdbuf(); //save old buf 
	//cin.rdbuf(in.rdbuf()); //redirect cin to in.txt! 
	int n;
	cin >> n;
//	p array[max];
	int list[max];
//	int* list = new int[n];
	string s;
	int id;
	string temp;
	for (int i = 0; i < max; i++){

		list[i] = 0;

	}
	for (int i = 0; i < n; i++){
		cin >> s;
		if (s == "Add"){
			p reg;
			p& f = reg;
			f.r = 0;

			cin >> s;
			temp = s;
			cin >> s;
			s = s.substr(1);

			reg.id = atoi(s.c_str());
			id = reg.id;
			//注意是从index1开始输出
			array[id] = reg;
			list[id] = 1;
			if (temp == "normal"){


			}
			else if (temp == "reverse"){
				array[id].reverse = true;
			}
			else if (temp == "single"){
				array[id].single = true;
			}
		}

		else if (s == "Set"){
			cin >> s;
			s = s.substr(1);
			id = atoi(s.c_str());
			int r, g, b;
			cin >> r >> g >> b;
			if (array[id].reverse){
				array[id].r = 255 - r;
				array[id].g = 255 - g;
				array[id].b = 255 - b;
				array[id].cal = suan(array[id].r, array[id].g, array[id].b);
			}
			else if (array[id].single){
				array[id].r =  r;
				array[id].cal = suan(array[id].r, array[id].g, array[id].b);
			}

			else{
				array[id].r = r;
				array[id].g =  g;
				array[id].b = b;
				array[id].cal = suan(array[id].r, array[id].g, array[id].b);
			}
			
		}
		else if (s == "Group"){
		}
	}
	cin >> s;
	if (s == "Normal"){
		//	cout << list[28];

	}
	else{
		sort(array);
	}
	for (int i = 1; i <= max; i++){
		//	cout << list[i];
		int k = array[i].id;
		if (list[k] == 1){
			cout << "P" << array[i].id << " " << array[i].r << " " << array[i].g << " " << array[i].b << endl;
		}
	}
	
	//		Sleep(2000);
	//	cout << ;
//	system("pause");
	return 0;
}