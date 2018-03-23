#include <iostream>
#include <string>
#include <vector>

using namespace std;
//二叉树结构体的构造
struct Tree
{
	Tree* left;    //左结点指针
	Tree* right;   //右结点指针
	string val;    //结点存储的值
	Tree(string& val1){  //定义结点变量
		left = NULL;  //默认为NULL
		right = NULL; 
		val = val1;  
	}
}*PTree;
//使用vector向量类来处理输入的字符串
//依据空格符将一个字符串分割为多个字符串 
vector<string> split(string& str, const char* c)
{
	char *cstr, *p; //定义字符指针
	vector<string> res; //定义向量字符串
	cstr = new char[str.size() + 1]; //分配内存空间
	//将输入的str字符串正规化后传入cstr指针
	strcpy(cstr, str.c_str()); //c_str()函数返回一个指向正规C字符串的指针
	p = strtok(cstr, c);//strtok()函数以传入的C字符为标识分割字符串cstr
	while (p != NULL)
	{
		res.push_back(p);//将分割的字符串传入res向量的尾部
		p = strtok(NULL, c);
	}
	return res; //返回res向量字符串
}
int isFirst = 1;//全局变量作为标识
//递归输出二叉树中序遍历函数
void print_middle(Tree* root){
	//若存在左结点，则递归至左结点
	if (root->left != NULL){
		print_middle(root->left);
	}
	//若结点的值不为空
	if (root->val!="null"){
		if (!isFirst){
			cout << " ";
		}
		isFirst = 0;//将标识位改为0
		cout << root->val;//输出结点的值
	}
	//若存在右结点，则递归至右结点
	if (root->right != NULL){
		print_middle(root->right);
	}
}
int main(){
	string str = "";
	getline(cin, str);//获取输入的字符串
	vector<string> vs = split(str, " ");//使用split函数处理字符串，存至向量vs
	int ceng = 0;//二叉树的层数
	vector<Tree*> vt;//二叉树向量vt
	//将输入的字符串传入二叉树向量
	for (int i = 0; i < vs.size(); i++){
		if((pow(2, ceng+1)-1) == i){
			ceng++;
		}
		int fa = int((i + 1 - pow(2, ceng)) / 2) + pow(2, ceng - 1) - 1;
		int isRight = int(i + 1 - pow(2, ceng)) % 2;
		string tmp = vs[i];
		Tree* tm = new Tree(tmp);
		vt.push_back(tm);
		if (isRight){
			vt[fa]->right = tm;
		}
		else{
			vt[fa]->left = tm;
		}
	}
	print_middle(vt[0]);//从头结点开始递归
	return 0;
}