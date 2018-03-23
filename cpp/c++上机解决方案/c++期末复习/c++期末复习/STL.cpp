#include<vector>
#include<iostream>
using namespace std;

//1.定义和初始化
vector<int> vec1;    //默认初始化，vec1为空
vector<int> vec2(vec1);  //使用vec1初始化vec2
vector<int> vec3(vec1.begin(), vec1.end());//使用vec1初始化vec2
vector<int> vec4(10);    //10个值为0的元素
vector<int> vec5(10, 4);  //10个值为4的元素
void main(){
//2.常用操作方法
vec1.push_back(100);            //尾部添加元素
int size = vec1.size();         //元素个数
bool isEmpty = vec1.empty();    //判断是否为空
cout << vec1[0] << endl;        //取得第一个元素
vec1.insert(vec1.end(), 5, 3);    //从vec1.back位置插入5个值为3的元素
vec1.pop_back();              //删除末尾元素
vec1.erase(vec1.begin(), vec1.begin() + 2);//删除vec1[0]-vec1[2]之间的元素，不包括vec1[2]其他元素前移
cout << (vec1 == vec2) ? true : false;  //判断是否相等==、！=、>=、<=...
vector<int>::iterator iter = vec1.begin();    //获取迭代器首地址
vector<int>::const_iterator c_iter = vec1.begin();   //获取const类型迭代器
vec1.clear();                 //清空元素

//3.遍历
//下标法
int length = vec1.size();
for (int i = 0; i<length; i++)
{
	cout << vec1[i];
}
cout << endl << endl;
//迭代器法
vector<int>::iterator iter = vec1.begin();
for (; iter != vec1.end(); iter++)
{
	cout << *iter;
}
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void print(int &elem){	//有无&均可 
	cout << elem << " ";
}
//qsprt必须用这种格式定义比较函数，像bj定义qsort传入参数会出错
// *和(int *)是同一优先级运算符，但结合方向是从右向左
int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}
int bj(int a, int b){
	return a > b;
}
int main(){
	int a[] = { 0, 3, 9, 1, 4, 8, 5, 2, 6, 7 };

	//algorithm头文件for_each( , , )函数用法
	for_each(a, a + 10, print);
	cout << endl;

	//快排模板函数,数组下标从0开始，即排序下标为0-9的元素
	qsort(a, 10, sizeof(a[0]), cmp);
	for_each(a, a + 10, print);
	cout << endl;

	//algorithm中的swap函数
	char x = 'X', y = 'Y';
	swap(x, y);
	printf("x = %c, y = %c\n", x, y);

	char str[] = "abcdefgh";
	//algorithm中的反转函数
	reverse(str + 2, str + 7);	//前闭后开 
	cout << str << endl;


	int aa[] = { 0, 3, 9, 1, 4, 8, 5, 2, 6, 7 };
	for_each(aa, aa + 10, print);
	cout << endl;
	//qsort,sort时间复杂度都是O(n*log(n))，但实际中sort速度一般比qsort快！！
	// sort(aa, aa+10);
	//不传入第三个参数默认sort为升序排序
	sort(aa, aa + 10, bj);
	//传入参数从大到小排序，且sort第三个参数不能用cmp函数
	for_each(aa, aa + 10, print);


	cout << endl << max(66, 88) << endl << min(66, 88) << endl;
	//max和min函数


	//二路归并,头文件algorithm
	int ak[] = { 1, 9, 5, 4, 7 };
	int ka[] = { 3, 6, 2, 8, 0 };
	int kk[15];
	sort(ak, ak + 5);
	sort(ka, ka + 5);
	merge(ak, ak + 5, ka, ka + 5, &kk[1]);

	for_each(ak, ak + 5, print);
	cout << endl;
	for_each(ka, ka + 5, print);
	cout << endl;
	for_each(kk + 1, kk + 11, print);
	cout << endl;
	return 0;
	//vector<int>().swap(vt)
}


