#include <iostream>
#include<string>
#include<iomanip>

using namespace std;
//注意格式
//可能有多层循环的时候，一定要给循环变量起一个合适的名字
//对于不同类型的变量起好合适的名字
//按刘钦老师的方法写好注释
//什么时候跳出循环，tie的时候看一下，尤其注意while里面的循环变量
//写每个变量的时候都确定一下是不是要用的值
//返回类型为bool的时候一定要确定覆盖了所有的情况
//比较函数注意是大于等于还是不大于

const int CLASS = 6;
struct studentDB{

	long long id = 0;
	double score[CLASS];
	double avscore;
};
const int MAX = 80;
//student list[MAX];
studentDB db[MAX];
string classes[CLASS];

int class_max_index = 0;
int real_num = 0;
int db_num = 0;
double total_sum;
double total_av;
bool isForwardThan(studentDB a, studentDB b){
	if (a.id == b.id)
		return true;
	else if (a.avscore > b.avscore)
		return true;
	else if (a.avscore < b.avscore)
		return false;
	else if (a.id >b.id)
		return true;
	else
		return false;
}
void sort(int left, int right){
	int i, j;
	studentDB temp;
	studentDB base;
	if (left > right)
		return;

	base = db[left];//存基准
	i = left;
	j = right;

	while (i != j){
		while (isForwardThan(base, db[j]) && i < j){
			j--;

		}
		while (isForwardThan(db[i], base) && i < j){
			i++;
		}

		if (i < j){
			temp =db[i];
			db[i] = db[j];
			db[j] = temp;
		}
	}



	db[left] = db[i];
	db[i] = base;

	sort(left, i - 1);
	sort(i + 1, right);

}

int main(int argc, char* argv[]){
	int n;//学生信息数目
	cin >> n;

	string lesson;
	string name;
	long long id;
	double score;

	for (int i = 0; i < n; i++){
		cin >> name;
		cin >> id;
		cin >> lesson;
		cin >> score;

		bool new_class = true;
		//		int no_class_index = 0;
		int j = 0;

		while (j < CLASS){
			if (classes[j] == lesson){
				new_class = false;
				break;
			}
			if (classes[j] == "" && new_class){
				classes[j] = lesson;
				class_max_index = j;
				break;
			}
			j++;
		}
		//插入
		int index = 0;
		while (true){
			if (db[index].id == id){
				db[index].score[j] = score;
				//惰性删除，把该位置的名字清除
				break;
			}


			if (db[index].id == 0){
				db[index].id = id;
				db[index].score[j] = score;
				break;

			}
			index++;
		}
	}
		int dbindex = 0;
			while(db[dbindex].id != 0){
			double sum = 0;
			for (int k = 0; k <= class_max_index; k++)
				sum += db[dbindex].score[k];
			db[dbindex].avscore = sum / (class_max_index + 1);
			total_sum += db[dbindex].avscore;//平均分的和
			real_num++;

			dbindex++;
		}

		total_av = total_sum / real_num;

		sort(0, real_num - 1);

		int i = 0;
		while (true){
			if (db[i].avscore <= total_av)
				break;
			i++;

		}
		for (int temp = i; temp < real_num -1; temp++){
			cout << db[temp].id << endl;
		}
		cout << db[real_num - 1].id ;

//system("pause");
	}
