#include <iostream>
#include <string>
#include <stack>

using namespace std;
//判断字符是否是起始TAG的字符
int checkCommentStart(string& line, int i){
	if (line.length() < (i + 4)){
		return 0;
	}
	if (line[i] == '<'&&line[i + 1] == '!'&&line[i + 2] == '-'&&line[i + 3] == '-'){
		return 1;
	}
	return 0;
}
//判断字符是否是末尾TAG的字符
int checkCommentEnd(string& line, int i){
	if (line.length() < (i + 3)){
		return 0;
	}
	if (line[i] == '-'&&line[i + 1] == '-'&&line[i + 2] == '>'){
		return 1;
	}
	return 0;
}
//获取TAG的起点
string getTagStart(string& line, int i){
	if (line[i] != '<'){
		return "";
	}
	i++;
	string tagname = "";
	int count = 0;
	while (i < line.length()){
		if (line[i] == '>'){
			if (count > 9){
				return "";
			}
			return tagname;
		}
		if ((line[i] >= 'A'&&line[i] <= 'Z')){
			tagname = tagname + line[i];
			count += 1;
		}
		else{
			return "";
		}
		i++;
	}
	return "";
}
//获取TAG的终点
string getTagEnd(string& line, int i){
	if (line[i] != '<'){
		return "";
	}
	i++;
	if (i >= line.length()){
		return "";
	}
	if (line[i] != '/'){
		return "";
	}
	i++;

	string tagname = "";
	int count = 0;
	while (i < line.length()){
		if (line[i] == '>'){
			if (count > 9){
				return "";
			}
			return tagname;
		}
		if ((line[i] >= 'A'&&line[i] <= 'Z')){
			tagname = tagname + line[i];
			count++;
		}
		else{
			return "";
		}
		i++;
	}
	return "";
}

int main(){
	string line;
	getline(cin, line);
	int findTag = 0;
	int inComment = 0;
	string tagname = "";
	int res = 0;
	stack<string> ss;//栈的数据结构
	int isVaild = false;//标识位判断是否符合TAG标准
	string top;
	char a[8];
	cin.get(a, 5, 'c');
	for (int i = 0; i < line.length(); i++){
		if (inComment){
			res = checkCommentEnd(line, i);
			if (res){
				i = i + 2;
				inComment = 0;
			}
			continue;
		}

		if (line[i] == '('){
			ss.push("(");
		}

		if (line[i] == ')'){
			top = ss.top();
			if (top == "("){
				ss.pop();
				continue;
			}
			else{
				isVaild = false;
				break;
			}
		}

		if (line[i] == '<'){
			res = checkCommentStart(line, i);
			if (res){
				inComment = 1;
				i = i + 3;
				continue;
			}

			int isStartTag = 0;
			string tag = getTagStart(line, i);
			if (tag != ""){
				ss.push(tag);
				i = i + tag.length() + 1;
				continue;
			}
			else{
				isStartTag = 0;
			}

			int isEndTag = 0;
			tag = getTagEnd(line, i);
			if (tag != ""){
				string top = ss.top();
				if (top != tag){
					isVaild = false;
					break;
				}
				else{
					ss.pop();
					i = i + tag.length() + 2;
					continue;
				}
			}
			else{
				isEndTag = 0;
			}

			if (isStartTag == 0 && isEndTag == 0){
				isVaild = false;
				break;
			}

		}

	}

	if (!ss.empty()){
		isVaild = false;
	}
	else{
		isVaild = true;
	}

	if (isVaild){
		cout << "True";
	}
	else{
		cout << "False";
	}

	return 0;

}