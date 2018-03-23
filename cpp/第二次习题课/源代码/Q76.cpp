#include <iostream>
#include <string>

using namespace std;
//链表的结构体处理
struct LinkList{
	LinkList* pre;  //前一结点指针
	LinkList* next; //后一结点指针
	int val; //结点值的记录
	LinkList(int val1){ // 结点初始化
		val = val1;
		pre = NULL; //初始为NULL
		next = NULL;
	}
};
//链表的输出
void print_linklist(LinkList* head){
	int isFirst = 1;//标识位，判断是否为头结点
	while (head != NULL){ //当头结点不为NULL时
		if (!isFirst){  
			cout << ">";  
		}
		isFirst = 0;
		cout << head->val; //输入下一个值
		head = head->next; //指针指向下一个结点
	}
	cout << ">null";  //打印"NULL"
}

int main1(){
	char c; 
	//第一个数值的输入
	LinkList* head1 = NULL; //定义头结点
	LinkList* end1 = NULL;  //定义尾结点
	int isFirst = 1; //定义标识符
	
	//数据的输入
	while ((c = cin.get()) != 'n'){
		if (isFirst&&c == '0'){
			c = cin.get();
			continue;
		}
		isFirst = 0;
		LinkList* node = new LinkList(c - '0');
		if (head1 == NULL){ //当头结点空时，进行赋值
			head1 = node;   //给头结点赋值
			end1 = node;    //给尾结点赋值（头结点也是尾结点）
		}
		else{  //当头结点不为空时，进行赋值
			end1->next = node;//尾结点的next指针指向新结点
			node->pre = end1; //新结点的pre指针指向尾结点
			end1 = node;      //将新结点赋值给尾结点
		}
		cin.get();
	}
	string tmp;
	getline(cin, tmp);//获取行输入
	//第二个数值的输入
	LinkList* head2 = NULL;//定义头结点
	LinkList* end2 = NULL; //定义尾结点
	isFirst = 1;//定义标识符
	while ((c = cin.get()) != 'n'){
		if (isFirst&&c == '0'){
			c = cin.get();
			continue;
		}
		isFirst = 0;
		LinkList* node = new LinkList(c - '0');
		if (head2 == NULL){
			head2 = node;
			end2 = node;
		}
		else{
			end2->next = node;
			node->pre = end2;
			end2 = node;
		}
		cin.get();
	}
	//定义第三个结点 用于存储计算结果
	LinkList* head3 = NULL;
	LinkList* end3 = NULL;
	int plus = 0;//设置进位标识符
	while (end1!=NULL && end2!=NULL)//循环体
	{
		int new_val = end1->val + end2->val+ plus; //对每一位进行运算
		end1 = end1->pre;//指针指向前一个结点
		end2 = end2->pre;//指针指向前一个结点
		if (new_val > 9){ //若需要进位
			plus = 1;  //进位标识符置为1
		}
		else{
			plus = 0; //否则进位标识符置为0
		}
		LinkList* res = new LinkList(new_val%10); //取余赋值 避免超过10的情况
		//对存储结果的链表进行赋值
		if (end3 == NULL){
			end3 = res;
			head3 = res;
		}
		else{
			head3->pre = res;
			res->next = head3;
			head3 = res;
		}
	}
	//当第二个链表不为空时
	if (end2 != NULL){
		end1 = end2; 
		head1 = head2;
	}
	//循环体处理进位
	while (end1 != NULL){
		int new_val = end1->val + plus;
		end1 = end1->pre;
		if (new_val > 9){
			plus = 1;
		}
		else{
			plus = 0;
		}
		LinkList* res = new LinkList(new_val%10);
		if (end3 == NULL){
			end3 = res;
			head3 = res;
		}
		else{
			head3->pre = res;
			res->next = head3;
			head3 = res;
		}
	}

	if (plus == 1){
		LinkList* add = new LinkList(1);
		add->next = head3;
		head3->pre = add;
		head3 = add;
	}
	//输出
	print_linklist(head3);
	return 0;
}