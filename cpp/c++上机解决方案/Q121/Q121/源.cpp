#include<iostream>
#include<string>
using namespace std;
class Student{
public:
	string id, name;
	int age;
	double weight,score1, score2, score3;
	double grade(){
		return (score1 * 4 + score2 * 4 + score3 * 3) / 11 / 20;
	}
};
template<typename T>
int compare(T a, T b){
	if (a > b)
		return 1;
	if (a == b)
		return 0;
	if (a < b)
		return -1;
}
int compare(Student a, Student b){
	return compare(a.grade(), b.grade());
}
int compare (string a, string b){
	return strcmp(a.c_str(), b.c_str());
}


int main(){
	Student* a = new Student();
	Student* b = new Student();

	cin >> a->id >> a->name >> a->age >> a->weight >> a->score1 >> a->score2 >> a->score3;
	cin >> b->id >> b->name >> b->age >> b->weight >> b->score1 >> b->score2 >> b->score3;

	cout << " " << compare(a->name, b->name) << " " << compare(a->age, b->age) << " " << compare(a->weight, b->weight) << " " << compare(*a, *b);
		
	return 0;
}