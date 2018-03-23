#include <iostream>
#include <string>
#include <vector>

using namespace std;
//二叉树结构体
struct TreeNode
{
	string val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(string x) :val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(string data, int m);
int calculateLen(TreeNode *r, string first, string second);
int findChild(TreeNode *r, string cmp, int len);
int main(){
	//数据的输入
	string count;
	getline(cin, count);
	string data;
	getline(cin, data);
	string firstnode;
	getline(cin, firstnode);
	string secondnode;
	getline(cin, secondnode);
	//调用方法
	int num = atoi(count.c_str());
	TreeNode *root = buildTree(data, num);
	int len = calculateLen(root, firstnode, secondnode);
	cout << len;
	//system("pause");
	return 0;
}
//二叉树的建立
TreeNode* buildTree(string data, int m) {
	string* tmp = new string[m];
	for (int i = 0; i < m; i++) {
		size_t pos = data.find(" ");
		tmp[i] = data.substr(0, pos);
		data = data.substr(pos + 1);
	}
	vector <TreeNode*> nodearr;
	for (int i = 0; i < m; i++) {
		nodearr.push_back(new TreeNode(tmp[i]));
	}

	for (int i = 0; i < m; i++) {
		if (m > 2 * i + 1) {
			nodearr[i]->left = nodearr[2 * i + 1];
		}
		if (m > 2 * i + 2) {
			nodearr[i]->right = nodearr[2 * i + 2];
		}
	}

	return nodearr[0];
}
//计算长度
int calculateLen(TreeNode *r, string first, string second) {
	if (first.compare(second) == 0) {
		return 0;
	}
	string v = r->val;
	if (v.compare(first) == 0) {
		int res = findChild(r, second, 0);
		return res;
	}
	if (v.compare(second) == 0) {
		int res = findChild(r, first, 0);
		return res;
	}
	//cannot find
	int lres = -1;
	int rres = -1;
	if (r->left != NULL) {
		lres = calculateLen(r->left, first, second);
	}
	if (r->right != NULL) {
		rres = calculateLen(r->right, first, second);
	}
	return (lres >= rres ? lres : rres);
}
//查找孩子
int findChild(TreeNode *r, string cmp, int len) {
	string v = r->val;
	if (v.compare(cmp) == 0) {
		return len;
	}
	else {
		int l = len + 1;
		int leftres = -1;
		int rightres = -1;
		if (r->left != NULL) {
			leftres = findChild(r->left, cmp, l);
		}
		if (r->right != NULL) {
			rightres = findChild(r->right, cmp, l);
		}
		if (leftres == -1 && rightres == -1) {
			return -1;
		}
		else {
			return (leftres >= rightres ? leftres : rightres);
		}
	}
	return 0;
}
