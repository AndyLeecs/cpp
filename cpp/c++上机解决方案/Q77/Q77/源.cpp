#include<iostream>
#include<string>
using namespace std;
//�ȰѸ��ӵ�������򵥵�����ת��
//�Ȱ��Լ����߼���������֤��д����
//���Լ����߼���û�и������е�����
struct Node{
	string data = "";

	Node* prev = NULL;
};

struct Stack{
	//	Node* base;
	Node* top;
	int length = 0;
	void push(string s){
		length++;
		if (top != NULL){
			Node* n = new Node;
			n->data = s;
			n->prev = top;
			top = n;
		}
		else{
			Node* n = new Node;
			n->data = s;
			n->prev = NULL;
			top = n;
		}

	}

	string pop(){
		length--;
		string result;
		if (top != NULL){
			result = top->data;
			Node* temp = top;
//			Node* prev = new Node;

				top = top->prev;
				delete temp;
			return result;
		}
		else
			return "";
	}
	bool IsEmpty(){
		if (length<=0)
			return true;
		else
			return false;
	}
};
int main(){
	string s;
	getline(cin, s);
	string temp = "";
	string pop = "";
	Stack* stack = new Stack;
	int state = 0;//0��ʾ��TAG_NAME״̬��1��ʾ��CONTENT״̬��2��ʾ��COMMENT״̬

	//��ע�͵�������ȥ��
//	Stack *commentStack = new Stack;
	int stackcount = 0;

	for (int i = 3; i < s.length(); i++){
		stackcount = 0;
		if (s[i - 3] == '<'&&s[i - 2] == '!' && s[i - 1] == '-' && s[i] == '-')
		{
			stackcount++;
			int j = i + 1;
			while (j < s.length()){
				//if (s[j - 3] == '<'&&s[j - 2] == '!' && s[j - 1] == '-' && s[j] == '-')
				//	stackcount++;
				//else 
				if (s[j - 2] == '-' && s[j - 1] == '-' && s[j] == '>')
					stackcount--;

				if (stackcount == 0){
					s = s.erase(i - 3, j - i + 4);//��ô���ַ�����ɾ��һ���֣�ע��β�ַ�ҲҪɾ
//					cout << s;
					break;
				}
				else if (j == s.length() - 1 && stackcount != 0)
				{
					std::cout << "False";
					return 0;
				}
				j++;
			}
		}
	}
	//��������ź������ŵ���Ŀ��ƥ�䣬����
	int count = 0;

	for (int i = 0; i < s.length(); i++){
		if (s[i] == '<'){
			count++;

		}
		else if (s[i] == '>')
			count--;
	}
	if (count != 0){
		std::cout << "False";
		//		system("pause");
		return 0;
	}

	for (int i = 0; i < s.length(); i++){
		//�ж��ǲ����ɱ�ǩ��ʼ
		if (s[0] != '<'){
			std::cout << "False";
			return 0;
		}
		//�ж�<��������
		if (s[i] == '<'){
			int j = i + 1;
			if ((s[j]<'A' || s[j] > 'Z')
				&& (s[j] != '/')
				&& (s[j] != '!')){
				std::cout << "False";
				//				std::cout << "for illegal after <";
				//				break;
				//				system("pause");
				return 0;
			}
			else if (s[j] == '/'){
				i++;
				//��ʾ��һ����β��ǩ��Ӧ�ó�ջ
				pop = stack->pop();
				if (pop .length ()> 0){
					
					state = 0;  
				}
			}

			else{
				state = 0;
			}
		}
		else if (s[i] == '>'){

			if (pop.length() == 0){

				//���û����Ҫ�Ƚϵ��ַ���
				stack->push(temp);//ע����ʳ�Ա������ʱ�򣬲�����.

				temp = "";
				state = 1;

			}
			else{

				if (pop != temp)
				{
//					std::cout << pop << "/n";
//					std::cout << temp;
					std::cout << "False";
					//					std::cout << "for illegal in stack";
					//					system("pause");
					return 0;
					//					break;
				}
				for (int popi = 0; popi < pop.length(); popi++){
					if (!(pop[popi] >= 'A' && pop[popi] <= 'Z')){
						std::cout << "False";
						//						std::cout << "for illegal uppercase";
						//					system("pause");
						return 0;
						//						break;
					}
				}

				if (temp.length() > 9 || temp.length() == 0)
				{
					std::cout << "False";
					//					std::cout << "for illegal length";
					//				system("pause");
					//					break;
					return 0;
				}


				pop = "";
				temp = "";
				state = 1;

			}
		}
		else if (state == 0){

			temp += s[i];

		}
	}
	if (!stack->IsEmpty())
//	if (stack->pop().length()>0)
		std::cout << "False";
else

	std::cout << "True";
//	std::cout << pop << "\n";
//	std::cout << temp;
//std::system("pause");
}