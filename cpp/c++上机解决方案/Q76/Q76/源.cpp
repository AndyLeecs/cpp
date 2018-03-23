#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//不要使用一些不优雅的实现，问题很多
//先做好代码设计再写代码
//注意链表不能取空，要先new一个Node才能有地址
//把复杂的问题尽量化为简单的问题，如先把长度补齐再计算
//注意联想之前同类题目的处理方式
//const int MAX = 500;//max
struct Node{
	int data = 0;;
	Node* next = NULL;
};
Node* one = new Node;
Node* two = new Node;
Node* result = new Node;

//c++中返回值不能是数组
Node * toLink(string s){
	Node* head = new Node;
	Node* before = new Node;
	head->next = before;
	head->data= s[1] - '0';
	Node* temp;

	int length = s.length();
	for (int i = 3; i < length; i++){
		if (s[i] != '>')
		{
			
			before->data = s[i] - '0';
			temp = new Node;
			before->next = temp;
			before = temp;

		}
	}

	return head;
}

void add(){

	Node* oneTemp = one;
	Node* twoTemp = two;

	int sum = 0;
	int adder = 0;


	result = new Node;

	Node* resultNext = result;
	Node* temp;

	int oneLen = 1;
	int twoLen = 1;

	while (oneTemp->next != NULL){
		oneTemp = oneTemp->next;
		oneLen++;
	}
	while (twoTemp->next != NULL){
		twoTemp = twoTemp->next;
		twoLen++;
	}

		while (oneLen < twoLen){
			temp = new Node;
			oneTemp->next = temp;
			oneTemp = temp;
			oneTemp->data = 0;
			oneLen++;
		}
		while (oneLen > twoLen){
			temp = new Node;
			twoTemp->next = temp;
			twoTemp = temp;
			twoTemp->data = 0;
			twoLen++;
		}
	

	oneTemp = one;
	twoTemp = two;

	while (oneTemp != NULL && twoTemp != NULL)
	{

		sum = oneTemp->data + twoTemp->data + adder;
		if (sum >= 10){
			sum = sum % 10;
			adder = 1;
		}
		else
		{
			adder = 0;
		}

		resultNext->data = sum;
		temp = new Node;
		resultNext->next = temp;
		resultNext = temp;

		oneTemp = oneTemp->next;
		twoTemp = twoTemp->next;
	}

	if (oneTemp == NULL && twoTemp != NULL)
	//while ((twoTemp = twoTemp->next )!= NULL)
		resultNext = twoTemp;
	else if (oneTemp != NULL && twoTemp == NULL)
		//while ((oneTemp = oneTemp->next) != NULL)
		resultNext = oneTemp;



	do{
		sum = resultNext->data + adder;
		if (sum >= 10){
			sum = sum % 10;
			adder = 1;
		}
		else
		{
			adder = 0;
		}
		resultNext->data = sum;
		temp = new Node;
		resultNext->next = temp;
		resultNext = temp;
	} while (resultNext->next != NULL);

	if (adder != 0)
	{
		
		resultNext->data = adder;
	}

	return;
	}


void toString(){
	string s = "";
	while (result != NULL){
		s += ">";
		s += (result->data+'0');
		
		result = result->next;
	}
	reverse(s.begin(), s.end());

	s += "null";
//string a=s.substr(0,5);       //获得字符串s中 从第0位开始的长度为5的字符串//默认时的长度为从开始位置到尾
	//判断高位0
	while (s[0] == '0' && s.length()>2)
		s = s.substr(2);

	cout << s;
}
int main(){
	//处理输入为倒序，且去掉末尾的null
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	reverse(s1.begin(), s1.end());
	s1 = s1.substr(4);
	reverse(s2.begin(), s2.end());
	s2 = s2.substr(4);

	one = toLink(s1);
	two = toLink(s2);
	add();
	toString();
//	system("pause");

}