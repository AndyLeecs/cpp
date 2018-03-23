#include<iostream>
#include<string>

using namespace std;
const string order[] = {"ADD","REVERSE","REMOVEREPEAT","DEL","PRINT","SIZE"};

struct Node{
	int data;
	Node* next = NULL;
};
Node* head ;
void reverse(){
	if (head != NULL && head->next != NULL){
		Node* temp = head ->next;
		Node* prev = head;

		Node* fortrans = temp->next;

		temp->next = prev;
		
			prev->next = NULL;



		while (temp != NULL && temp->next != NULL && fortrans != NULL){
			prev = temp;
			temp = fortrans;
			fortrans = temp->next;
			temp->next = prev;
			
			
			
			
			
			
		}
		
		head = temp;
		
		temp->next = prev;
	}
}
//void reverse(){
//	Node* current;
//	Node * pnext;
//	Node * prev;
//	if (head == NULL || head->next == NULL)
//		return;
//	current = head->next;  /* p1指向链表头节点的下一个节点 */
//	pnext = current->next;
//	current->next = NULL;
//	while (pnext)
//	{
//		prev = pnext->next;
//		pnext->next = current;
//		current = pnext;
//		pnext = prev;
//	}
//	//printf("current = %d,next = %d \n",current->data,current->next->data);
//	head->next = current;  /* 将链表头节点指向p1 */
//}
int main(){
	int n = 0; 
	cin >> n;
	
	
	string temps;

	for (int i = 0; i < n; i++){
		cin >> temps;
		if (temps == order[0]){
			if (head == NULL)
			{
				head = new Node;
				cin >> head->data;
			}
			else{

				Node* temp = head;
				while (temp->next != NULL)
					temp = temp->next;
				Node* tail = new Node;
				temp->next = tail;
				cin >> tail->data;

			}
		}
		else if (temps == order[1]){
			reverse();
		}
		else if (temps == order[2]){
			reverse();
			bool found_first = false;
			int target = 0;
			cin >> target;
			if (head == NULL)
			{
			}
			else{
				if (head->data == target)
					found_first = true;
				Node* temp = head->next;
				Node* prev = head;
				while (temp != NULL){
					bool found = false;
					if (temp->data == target && !found_first){
						found_first = true;
						prev = prev->next;
					}
					else if (temp->data == target && found_first){
			//			if (temp->next != NULL)
						found = true;
							prev->next = temp->next;
						//delete temp;
					}
					else{
						prev = prev->next;
					}
					if (temp->next != NULL){
						if (found){
							Node* todelete = temp;
							temp = temp->next;
							delete todelete;
						}
						else{
							temp = temp->next;
						}
					}
					else
						break;
					
				}

			}
			reverse();
		}
		else if (temps == order[3]){
			int target = 0;
			cin >> target;
			if (head == NULL)
			{
			}
			else{
				while (head->data == target && head->next != NULL){
					head = head->next;
				}
				if (head->data == target && head->next == NULL){
					head = NULL;
					continue;
				}

				
				Node* temp = head -> next;
				Node* prev = head;
				
				while (temp != NULL){
					bool found = false;
					if (temp->data == target){
						//if (temp->next != NULL){
						found = true;
							prev->next = temp->next;
							//delete temp;
						//}
					}
					else{
						prev = prev->next;
					}
					if (temp->next != NULL){
						if (found){
							Node* todelete = temp;
							temp = temp->next;
							delete todelete;
						}
						else{
							temp = temp->next;
						}
					}
					else{
						break;
					}
					
				}

			}
		}
		else if (temps == order[4]){
			if (head == NULL)
				cout << "NULL";
			else
			{
				Node * temp = head;
				cout << temp->data << " ";
				while (temp->next != NULL){
					
					temp = temp->next;
					cout << temp->data;
					if (temp->next != NULL)
						cout << " ";
				}

				
			}
			//if (i != n - 1)
				cout << endl;
		}
		else if (temps == order[5]){
			int size = 1;
			if (head == NULL)
				cout << 0;
			else
			{
				Node * temp = head;
				while (temp->next != NULL){
					size++;
					temp = temp->next;
				}
				cout << size;
			}

			//if (i != n - 1)
				cout << endl;
		}

	}

//system("pause");
}
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<stack>
//using namespace std;
//stack<int> stackForElement;
//void ADD(int element);
//void PRINT();
//void REVERSE();
//void REMOVEREPEAT(int element);
//void DEL(int elemebt);
//void SIZE();
//struct  node
//{
//	int element;
//	node* next = NULL;
//};
//node * header;
//int main(){
//	header = new node[1];
//	header->element = 0;
//	header->next = NULL;
//	int length;
//	cin >> length;
//	for (int i = 0; i < length; i++)
//	{
//		string instruction;
//		cin >> instruction;
//		if (instruction == "ADD"){
//			int number;
//			cin >> number;
//			ADD(number);
//		}
//		if (instruction == "SIZE"){
//			SIZE();
//		}
//		if (instruction == "PRINT"){
//			PRINT();
//		}
//		if (instruction == "REMOVEREPEAT"){
//			int number;
//			cin >> number;
//			REMOVEREPEAT(number);
//		}
//		if ("DEL" == instruction){
//			int number;
//			cin >> number;
//			DEL(number);
//		}
//		if ("REVERSE" == instruction){
//			REVERSE();
//		}
//	}
//}
//void ADD(int element){
//	node* newNode = new node[1];
//	newNode->element = element;
//	node * temple = header;
//	while (temple->next != NULL)
//		temple = temple->next;
//	temple->next = newNode;
//	header->element++;
//}
//
//void PRINT(){
//	if (header->element == 0)
//	{
//		cout << "NULL" << endl;
//		return;
//	}
//	node* temple = header;
//	for (int i = 0; i < header->element; i++)
//	{
//		temple = temple->next;
//		if (i != header->element - 1)
//			cout << temple->element << " ";
//		else
//			cout << temple->element << endl;
//	}
//}
//void SIZE(){
//	cout << header->element << endl;
//}
//void DEL(int x){
//	node * temple = header;
//	while (temple->next != NULL){
//		if (temple->next->element == x)
//		{
//			temple->next = temple->next->next;
//			header->element--;
//			continue;
//		}
//		temple = temple->next;
//	}
//}
//void REMOVEREPEAT(int number){
//	int count = 0;
//	node * temple = header;
//	while (temple->next != NULL){
//		temple = temple->next;
//		if (temple->element == number)
//			count++;
//	}
//	if (count <= 1)
//		return;
//	temple = header;
//	while (temple->next != NULL&&count>1){
//		if (temple->next->element == number)
//		{
//			temple->next = temple->next->next;
//			header->element--;
//			count--;
//			continue;
//		}
//		temple = temple->next;
//	}
//}
//void REVERSE(){
//	if (header->element <= 1)
//		return;
//	node * itr = header;
//	for (int i = 0; i < header->element; i++){
//		itr = itr->next;
//		stackForElement.push(itr->element);
//	}
//	header->element = 0;
//	header->next = NULL;
//	while (!stackForElement.empty()){
//		ADD(stackForElement.top());
//		stackForElement.pop();
//	}
//}