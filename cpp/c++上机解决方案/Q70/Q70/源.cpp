#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

int main(int argc, char* argv[]){
	int n;//学生信息数目
	cin >> n;

	struct student{
		string name;
		string id;
		string class_name;
		double score;
	};
	student db[100];
	string temp;
	
	for (int i = 0; i < n; i++){
		cin >> db[i].name >> db[i].id >> db[i].class_name >> db[i].score;
		//去重
		for (int j = 0; j < i; j++)
		if (db[j].id == db[i].id && db[j].class_name == db[i].class_name && db[j].score == db[i].score){
			db[j].class_name = "";
			db[j].name = "";
		}

	}


		int m;//命令条数
		cin >> m;
		string order;
		string ope;
		for (int i = 0; i < m; i++){
			cin >> order >> ope;
			if (order == "course")
			{
				double student_num = 0;
				double sum = 0;

				for (int j = 0; j < n; j++)
				if (db[j].class_name == ope){
					student_num++;
					sum += db[j].score;
				}
				cout << ope << " " << setiosflags(ios::fixed)<< setprecision(2) << sum / student_num << endl;
			}
			if (order == "student")
			{
				double course_num = 0;
				double sum = 0;
				for (int j = 0; j < n; j++)
				if (db[j].name == ope){
					course_num++;
					sum += db[j].score;
				}
				cout << ope << " " <<setiosflags(ios::fixed) << setprecision(2) << sum / course_num << endl;

			}
		}

	}