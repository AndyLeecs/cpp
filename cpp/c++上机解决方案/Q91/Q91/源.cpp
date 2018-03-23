#include <iostream>
#include<string>
#include<iomanip>

using namespace std;
//ע���ʽ
//�����ж��ѭ����ʱ��һ��Ҫ��ѭ��������һ�����ʵ�����
//���ڲ�ͬ���͵ı�����ú��ʵ�����
//��������ʦ�ķ���д��ע��
//ʲôʱ������ѭ����tie��ʱ��һ�£�����ע��while�����ѭ������
//дÿ��������ʱ��ȷ��һ���ǲ���Ҫ�õ�ֵ
//��������Ϊbool��ʱ��һ��Ҫȷ�����������е����
//�ȽϺ���ע���Ǵ��ڵ��ڻ��ǲ�����

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

	base = db[left];//���׼
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
	int n;//ѧ����Ϣ��Ŀ
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
		//����
		int index = 0;
		while (true){
			if (db[index].id == id){
				db[index].score[j] = score;
				//����ɾ�����Ѹ�λ�õ��������
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
			total_sum += db[dbindex].avscore;//ƽ���ֵĺ�
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
