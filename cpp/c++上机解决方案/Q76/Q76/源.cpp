#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//��Ҫʹ��һЩ�����ŵ�ʵ�֣�����ܶ�
//�����ô��������д����
//ע��������ȡ�գ�Ҫ��newһ��Node�����е�ַ
//�Ѹ��ӵ����⾡����Ϊ�򵥵����⣬���Ȱѳ��Ȳ����ټ���
//ע������֮ǰͬ����Ŀ�Ĵ���ʽ
//const int MAX = 500;//max
struct Node{
	int data = 0;;
	Node* next = NULL;
};
Node* one = new Node;
Node* two = new Node;
Node* result = new Node;

//c++�з���ֵ����������
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
//string a=s.substr(0,5);       //����ַ���s�� �ӵ�0λ��ʼ�ĳ���Ϊ5���ַ���//Ĭ��ʱ�ĳ���Ϊ�ӿ�ʼλ�õ�β
	//�жϸ�λ0
	while (s[0] == '0' && s.length()>2)
		s = s.substr(2);

	cout << s;
}
int main(){
	//��������Ϊ������ȥ��ĩβ��null
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