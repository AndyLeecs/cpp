#include<iostream>
#include<string>
using namespace std;

	template<typename T>
	//从小到大排序
	void sort(T A[], unsigned int num)
	{
		for (int i = 1; i < num; i++)
		for (int j = 0; j<num - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				T t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
		}
	}
	int count_ ;
	template<typename T>
	void BinarySearch(T a[], const T& x, int n)
	{
		int left = 0;
		int right = n - 1;
		count_ = 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (a[middle] == x)
				return;
			else
				count_++;
			if (x >= a[middle])
				left = middle + 1;
			else
				right = middle - 1;
		}
		return;
	}


	int main(){
		while (cin){
			int n;
			cin >> n;
			int*a = new int[n];
			bool isInt = false;
			double*b = new double[n];
			bool isDouble = false;
			char*c = new char[n];
			bool isChar = false;

			double d;
			cin >> d;

			if (cin.good() == 1)
			{
				if (d == (double)((int)d)){
					isInt = true;
					a[0] = (int)d;
					for (int i = 1; i < n; i++){
						cin >> a[i];
					}
				}
				else{

					isDouble = true;
					b[0] = d;
					for (int i = 1; i < n; i++){
						cin >> b[i];
					}
				}
			}
			else{
				cin.clear();
				isChar = true;
				//c[0] = d;
				//for (int i = 1; i < n; i++){
				//	cin >> c[i];
				//}
				for (int i = 0; i < n; i++){
					cin >> c[i];
				}
			}



			if (isInt)
			{
				//for (int i = 0; i < n; i++)
				//	cout << a[i];
				int target;
				cin >> target;
				sort(a, n);
				BinarySearch(a, target, n);

			}
			else if (isDouble){
				//for (int i = 0; i < n; i++)
				//	cout << b[i];
				double target;
				cin >> target;
				sort(b, n);
				BinarySearch(b, target, n);
			}
			else {
				//for (int i = 0; i < n; i++)
				//	cout << c[i];
				char target;
				cin >> target;
				sort(c, n);
				BinarySearch(c, target, n);
			}

			cout << count_<<endl;

		}
//			system("pause");
			return 0;
		}
	