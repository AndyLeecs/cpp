#include <iostream>
#include <string>
#include <vector>

using namespace std;
//学生信息结构体
struct info
{
	string name;
	int id;
	string subject;
	int score;
	info(string n, int i, string s, int sc) :name(n), id(i), subject(s), score(sc){}
};
//排序结构体
struct sort
{
	int id;
	double mean;
	sort(int i, double m) :id(i), mean(m){}
};
info* parse(string v) {
	string *tmp = new string[4];
	for (int i = 0; i < 4; i++) {
		size_t pos = v.find(" ");
		tmp[i] = v.substr(0, pos);
		v = v.substr(pos + 1);
	}
	info *res = new info(tmp[0], atoi(tmp[1].c_str()), tmp[2], atoi(tmp[3].c_str()));
	return res;
}
int main() {
	string ct;
	getline(cin, ct);
	int count = atoi(ct.c_str());
	string res = "";
	int info_len = 0;
	vector<info*> totalinfo;
	for (int i = 0; i < count; i++) {
		string inf;
		getline(cin, inf);
		info *ready = parse(inf);
		if (info_len == 0) {
			totalinfo.push_back(ready);
			info_len++;
		}
		else {
			int isadd = 1;
			for (int j = 0; j < info_len; j++) {
				info *temp = totalinfo[j];
				if ((temp->id == ready->id) && (temp->subject.compare(ready->subject) == 0)) {
					totalinfo[j]->score = ready->score;
					isadd = 0;
				}
			}
			if (isadd == 1) {
				totalinfo.push_back(ready);
				info_len++;
			}
		}
	}
	int num_sub = 0;
	vector<string> totalsub;
	int sub_len = 0;
	vector<int> totalid;
	int id_len = 0;
	for (int i = 0; i < info_len; i++) {
		if (sub_len == 0) {
			totalsub.push_back(totalinfo[i]->subject);
			sub_len++;
		}
		else {
			int isdump = 0;
			for (int j = 0; j < sub_len; j++) {
				if (totalinfo[i]->subject.compare(totalsub[j]) == 0) {
					isdump = 1;
					break;
				}
			}
			if (isdump == 0) {
				totalsub.push_back(totalinfo[i]->subject);
				sub_len++;
			}
		}
	}

	for (int i = 0; i < info_len; i++) {
		if (id_len == 0) {
			totalid.push_back(totalinfo[i]->id);
			id_len++;
		}
		else {
			int isdump = 0;
			for (int j = 0; j < id_len; j++) {
				if (totalinfo[i]->id == totalid[j]) {
					isdump = 1;
					break;
				}
			}
			if (isdump == 0) {
				totalid.push_back(totalinfo[i]->id);
				id_len++;
			}
		}
	}
	//每个人平均fen
	vector<double> mean;
	for (int i = 0; i < id_len; i++) {
		int sum = 0;
		for (int j = 0; j < info_len; j++) {
			if (totalid[i] == totalinfo[j]->id) {
				sum = sum + totalinfo[j]->score;
			}
		}
		double r = sum / (double)sub_len;
		//cout << totalid[i] << ":" << r<<endl;
		mean.push_back(r);
	}
	double sum = 0;
	for (int i = 0; i < id_len; i++) {
		sum = sum + mean[i];
	}
	double m = sum / (double)id_len;
	//cout << "t_mean:" << m<<endl;

	vector<sort*> sortlist;
	int sort_len = 0;
	//find
	for (int i = 0; i < id_len; i++) {
		if (mean[i] <= m) {
			sortlist.push_back(new sort(totalid[i], mean[i]));
			sort_len++;
		}
	}
	//cout << "sort:" << sort_len << endl;
	//sort
	for (int i = 0; i < sort_len - 1; i++) {
		for (int j = 0; j < sort_len - i - 1; j++) {
			if (sortlist[j]->mean < sortlist[j + 1]->mean) {
				sort *tmp = sortlist[j];
				sortlist[j] = sortlist[j + 1];
				sortlist[j + 1] = tmp;
			}
			else if (sortlist[j]->mean == sortlist[j]->mean) {
				if (sortlist[j]->id < sortlist[j + 1]->id) {
					sort *tmp = sortlist[j];
					sortlist[j] = sortlist[j + 1];
					sortlist[j + 1] = tmp;
				}
			}
		}
	}

	//output
	string res1 = "";
	for (int i = 0; i < sort_len; i++) {
		res1 = res1 + to_string(sortlist[i]->id) + "\n";
		//cout << sortlist[i]->id<<endl;
	}
	res1 = res1.substr(0, res1.length() - 1);
	cout << res1;

	//system("pause");
	return 0;
}