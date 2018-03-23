#include<iostream>
#include<string>
using namespace std;

//对比功能函数体
int compare(string str1,string str2){
	//若字符串1长度小于字符串2 return 1
	if (str1.length()<str2.length()){
		return 1;
	}
	//若字符串1长度大于字符串2 return -1
	if (str1.length()>str2.length()){
		return -1;
	}
	//当字符串长度相等时，判断前后算法
	if (str1.length()==str2.length()){
		for (int i = 0; i < str1.length();i++){
			if (str1[i]==str2[i]){
				continue;
			}
			else{
				if ((str1[i] <= 90 && str2[i] <= 90) || (str1[i] >=97 && str2[i] >=97)){
					if (str1[i]<str2[i]){
						return 1;
					}
					else{
						return -1;
					}
				}
				int v1, v2;
				v1 = str1[i],v2=str2[i];
				if (str1[i]<=90){//为大写字母
					v1 = str1[i] + 32;
				}
				if (str2[i] <= 90){//为大写字母
					v2 = str2[i] + 32;
				}

				if (v1<v2){
					return 1;
				}
				else if(v1==v2){
					return (str1[i] > str2[i])?1:-1;
				}
				else{
					return -1;
				}
			}
		}
	}
	return 0;
}

int main(){
	int n;
	cin >> n;
	string*str = new string[n];

	for (int i = 0; i < n;i++){
		cin >> str[i];
	}

	for (int i = 0; i < n;i++){
		for (int j = 1+i; j < n;j++){
			if (compare(str[i],str[j])<0){
				string temp = str[j];
				str[j] = str[i];
				str[i]=temp;
			}
		
		}
		cout << endl << endl;
	}

	for (int i = 0; i < n-1; i++){
		cout << str[i] << endl;;
	}
	cout << str[n-1];

	return 1;
}