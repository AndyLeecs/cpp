#include <iostream>
#include <string>

using namespace std;

struct linkedList
{
	string val;
	linkedList *next;
	linkedList(string x) :val(x), next(NULL){}
};
linkedList* add(linkedList *l, string v);
linkedList* reverse(linkedList *l);
linkedList* removerepeat(linkedList *l, string v);
linkedList* del(linkedList *l, string v);
string print(linkedList *l);
string size(linkedList *l);
int main() {
	linkedList *head = NULL;
	string ct;
	getline(cin, ct);
	int count = atoi(ct.c_str());
	string res = "";
	for (int i = 0; i < count; i++) {
		//cout <<"index:"<< i<<endl;
		string command;
		getline(cin, command);
		if (command.compare("SIZE") == 0) {
			res = res + size(head) + "\n";
		}
		else if (command.compare("PRINT") == 0) {
			res = res + print(head) + "\n";
		}
		else if (command.compare("REVERSE") == 0) {
			head = reverse(head);
		}
		else {
			size_t pos = command.find(" ");
			string op = command.substr(0, pos);
			string value = command.substr(pos + 1);
			if (op.compare("ADD") == 0) {
				//cout << "value:" << value<<endl;
				head = add(head, value);
			}
			else if (op.compare("DEL") == 0) {
				head = del(head, value);
			}
			else if (op.compare("REMOVEREPEAT") == 0) {
				head = removerepeat(head, value);
			}
		}
	}
	res = res.substr(0, res.length() - 1);
	cout << res;
	//system("pause");
	return 0;
}
//添加数字功能算法
linkedList* add(linkedList *l, string v) {
	linkedList *t = l;
	if (t == NULL) {
		t = new linkedList(v);
		t->next = NULL;
		return t;
	}
	else {
		linkedList *h = t;
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = new linkedList(v);
		return h;
	}
}
//翻转链表功能的算法
linkedList* reverse(linkedList *l) {
	if (l == NULL){
		return NULL;
	}
	if (l->next == NULL){
		return l;
	}
	if (l->next->next == NULL){
		linkedList *tmp = l->next;
		l->next = NULL;
		tmp->next = l;
		return tmp;
	}
	linkedList *p = l;
	linkedList *q = l->next;
	linkedList *r = NULL;
	p->next = NULL;
	while (q->next != NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	q->next = p;
	l = q;
	return l;
}
//删除重复数据的方法
linkedList* removerepeat(linkedList *l, string v) {
	linkedList *tmp = l;
	linkedList *t = l;
	linkedList *pre = NULL;
	int count = 0;
	while (tmp != NULL) {
		if (tmp->val.compare(v) == 0) {
			count++;
		}
		tmp = tmp->next;
	}
	while (t != NULL) {
		if (t->val.compare(v) == 0) {
			if (pre == NULL) {
				if (count != 1) {
					l = l->next;
					t = t->next;
					count--;
				}
				else {
					pre = t;
					t = t->next;
				}
			}
			else {
				if (count != 1) {
					pre->next = t->next;
					t = t->next;
					count--;
				}
				else {
					pre = t;
					t = t->next;
				}
			}
		}
		else {
			pre = t;
			t = t->next;
		}
	}
	return l;
}
//链表内容删除的方法
linkedList* del(linkedList *l, string v) {
	linkedList *t = l;
	linkedList *pre = NULL;
	while (t != NULL) {
		if (t->val.compare(v) == 0) {
			if (pre == NULL) {
				l = l->next;
				t = t->next;
			}
			else {
				pre->next = t->next;
				t = t->next;
			}
		}
		else {
			pre = t;
			t = t->next;
		}
	}
	return l;
}
//打印功能函数
string print(linkedList *l) {
	if (l == NULL){
		return "NULL";
	}
	linkedList *t = l;
	string res = "";
	while (t != NULL) {
		if (t->next != NULL) {
			res = res + t->val + " ";
			t = t->next;
		}
		else {
			res = res + t->val;
			break;
		}
	}
	return res;

}
string size(linkedList *l) {
	int i = 0;
	linkedList *t = l;
	while (t != NULL) {
		i++;
		t = t->next;
	}

	string r = to_string(i);
	return r;
}