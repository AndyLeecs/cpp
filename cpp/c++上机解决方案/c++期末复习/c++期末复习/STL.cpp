#include<vector>
#include<iostream>
using namespace std;

//1.����ͳ�ʼ��
vector<int> vec1;    //Ĭ�ϳ�ʼ����vec1Ϊ��
vector<int> vec2(vec1);  //ʹ��vec1��ʼ��vec2
vector<int> vec3(vec1.begin(), vec1.end());//ʹ��vec1��ʼ��vec2
vector<int> vec4(10);    //10��ֵΪ0��Ԫ��
vector<int> vec5(10, 4);  //10��ֵΪ4��Ԫ��
void main(){
//2.���ò�������
vec1.push_back(100);            //β�����Ԫ��
int size = vec1.size();         //Ԫ�ظ���
bool isEmpty = vec1.empty();    //�ж��Ƿ�Ϊ��
cout << vec1[0] << endl;        //ȡ�õ�һ��Ԫ��
vec1.insert(vec1.end(), 5, 3);    //��vec1.backλ�ò���5��ֵΪ3��Ԫ��
vec1.pop_back();              //ɾ��ĩβԪ��
vec1.erase(vec1.begin(), vec1.begin() + 2);//ɾ��vec1[0]-vec1[2]֮���Ԫ�أ�������vec1[2]����Ԫ��ǰ��
cout << (vec1 == vec2) ? true : false;  //�ж��Ƿ����==����=��>=��<=...
vector<int>::iterator iter = vec1.begin();    //��ȡ�������׵�ַ
vector<int>::const_iterator c_iter = vec1.begin();   //��ȡconst���͵�����
vec1.clear();                 //���Ԫ��

//3.����
//�±귨
int length = vec1.size();
for (int i = 0; i<length; i++)
{
	cout << vec1[i];
}
cout << endl << endl;
//��������
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
void print(int &elem){	//����&���� 
	cout << elem << " ";
}
//qsprt���������ָ�ʽ����ȽϺ�������bj����qsort������������
// *��(int *)��ͬһ���ȼ������������Ϸ����Ǵ�������
int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}
int bj(int a, int b){
	return a > b;
}
int main(){
	int a[] = { 0, 3, 9, 1, 4, 8, 5, 2, 6, 7 };

	//algorithmͷ�ļ�for_each( , , )�����÷�
	for_each(a, a + 10, print);
	cout << endl;

	//����ģ�庯��,�����±��0��ʼ���������±�Ϊ0-9��Ԫ��
	qsort(a, 10, sizeof(a[0]), cmp);
	for_each(a, a + 10, print);
	cout << endl;

	//algorithm�е�swap����
	char x = 'X', y = 'Y';
	swap(x, y);
	printf("x = %c, y = %c\n", x, y);

	char str[] = "abcdefgh";
	//algorithm�еķ�ת����
	reverse(str + 2, str + 7);	//ǰ�պ� 
	cout << str << endl;


	int aa[] = { 0, 3, 9, 1, 4, 8, 5, 2, 6, 7 };
	for_each(aa, aa + 10, print);
	cout << endl;
	//qsort,sortʱ�临�Ӷȶ���O(n*log(n))����ʵ����sort�ٶ�һ���qsort�죡��
	// sort(aa, aa+10);
	//���������������Ĭ��sortΪ��������
	sort(aa, aa + 10, bj);
	//��������Ӵ�С������sort����������������cmp����
	for_each(aa, aa + 10, print);


	cout << endl << max(66, 88) << endl << min(66, 88) << endl;
	//max��min����


	//��·�鲢,ͷ�ļ�algorithm
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


