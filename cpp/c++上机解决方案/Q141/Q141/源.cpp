#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<Windows.h>
#include<fstream>

using namespace std;
class car{
public:
	int id;
	string type;
	double size;
	int time;
	int wait;
	double fee;
	//��ͣʱ��
	int totaltime = 0;
	//�ѵȴ�ʱ��
	int waittime = 0;
	car():type(""),id(0){
		size = 0;
		time = 0;
		wait = 0;
		fee = 0;
	};
	car(string s, int i) :type(s), id(i){
		if (s == "S"){
			size = 1;
			time = 1;
			wait = 1;
			fee = 1.5;
		}
		if (s == "M"){
			size = 1.5;
			time = 2;
			wait = 2;
			fee = 3;

		}
		if (s == "L"){
			size = 2;
			time = 1;
			wait = 3;
			fee = 4.5;

		}
	}
};

int n;//��λ
string s;//sunny rainy
string temp;
double count_;
string type;
int id;
vector<car> v;
vector<car> park;
car*list_;
void check(){
	if (s == "sunny"){
		//��ǰͣ�������뿪���շ�
		for (int i = 0; i < park.size(); i++){
			++park[i].totaltime;
			if (park[i].totaltime == park[i].time){
				count_ += park[i].fee;
				park.erase(park.begin()+i);
			}
		}
		//��ǰ�ȴ����У��뿪
		for (int i = 0; i < v.size(); i++){
			++v[i].waittime;
			if (v[i].waittime == v[i].wait){
				v.erase(v.begin()+i);
			}
		}

	}
	else{

	}
}
//�������֮�󣬼���ͣ��
void checkEnd(){
	while (v.size() != 0){
		check();
		if (s == "sunny"){
			//��鵱ǰ���
			check();
			list_ = new car[n * 2];
			car c = car(type, id);
			v.push_back(c);
			int kong = 0;
			for (int i = 0; i < n; i++)
			if (list_[i].type == ""){
				kong = i;
				break;
			}
			//�Ƿ��ܹ�ͣ��
			for (int i = 0; i < v.size(); i++){
				if (n - kong >= v[i].size * 2){
					park.push_back(v[i]);
					v.erase(v.begin() + i);
					kong += v[i].size;
				}
				else{
					break;
				}
			}
			//��ӡ��ǰʱ��
			if (park.size() == 0)
				cout << "null" << endl;
			for (int i = 0; i < park.size(); i++){
				if (i != 0)
					cout << " ";
				cout << park[i].type << park[i].id;
			}
			cout << endl;

		}
	}
}
void main(){
	cin >> n;
	cin >> s;
	

	while (1){
		cin >> temp;
		if (temp == "end")
		{
			checkEnd();
            break;
		}
		else{
			cin >> temp >> temp;
			type = temp.substr(0, 1);
			id = atoi(temp.substr(1).c_str());
		}
		if (s == "sunny"){
			//��鵱ǰ���
			check();
			list_ = new car[n * 2];
			car c = car(type, id);
			v.push_back(c);
			int kong = 0;
			for (int i = 0; i < n; i++)
			if (list_[i].type == ""){
				kong = i;
				break;
			}
			//�Ƿ��ܹ�ͣ��
			for (int i = 0; i < v.size(); i++){
				if (n - kong >= v[i].size * 2){
					park.push_back(v[i]);
					v.erase(v.begin()+i);
					kong += v[i].size;
				}
				else{
					break;
				}
			}
			//��ӡ��ǰʱ��
			if (park.size() == 0)
				cout << "null"<<endl;
			for (int i = 0; i < park.size(); i++){
						if (i != 0)
							cout << " ";
						cout << park[i].type << park[i].id;
					}
			cout << endl;

			}
		
		else{

		}
	}
	cout << count_;
}