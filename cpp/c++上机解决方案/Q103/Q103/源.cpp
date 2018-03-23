#include <iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
int maxInPer = 0;
int line = 0;
void cal(int *array, int iSize){
	int max = 0;
	//			bool same = false;
	for (int i = 0; i < iSize; i++){
		cout << array[i];
		int width = 1;
		int j = i-1;
		bool same = false;

		while (j >= 0 && array[i] <= array[j]){
			width++;
			if (array[i] == array[j]){
				same = true;
				break;
			}
			j--;

		}
		if (!same){
			j = i + 1;
			while (j< iSize && array[i] <= array[j]){
				width++;
				j++;
			}
			//		result[i] = width*array[i];
			int temp = width*array[i];
			if (temp > max){
				max = temp;
			}
		}
	}
	cout << endl;
	//line++;
	//cout << max;
	//cout << endl;
	
	if (maxInPer < max)
		maxInPer = max;


}
bool ifchange(int*p,int*q){
	int* temp;
	for (temp = p; temp < q; temp++){
		if (*temp == *q)
			return false;
	}
	return true;

}
void Permutation(int*array, int*array_t, int&isize, int iSize){
	int i;
	int *pch;
	if (isize == 1)
		cal(array, iSize);
	else{
		for (pch = array_t, i = 0; i < isize; i++,pch++){
			if (ifchange(array_t,pch)){
				swap(*array_t, *pch);
				isize--;
				Permutation(array, array_t + 1, isize, iSize);
				isize++;
				swap(*array_t, *pch);

			}
		}
	}
}
int main(){
	
	ifstream fin;
	fin.open("d:\\c++\\第二次机考\\求柱形图的最大矩形面积\\test_cases\\test9.in");
	cin.rdbuf(fin.rdbuf());
	string s;

	cin >> s;
	int n = 0;
		cin >> n;
		int* array = new int[n];
		for (int i = 0; i < n; i++){
			cin >> array[i];
		}
		if (s == "NORMAL"){
			int max = 0;
			int maxn = 1;
//			bool same = false;
			for (int i = 0; i < n; i++){
				int width = 1;
				
				//if (i >= 1 && array[i] == array[i - 1])
				//{
				//	continue;
				//}
				//else 
			//	if(i!=0){
			//		int j = i-1;
			//		bool same = false;
			//		while( j >= 0){
			////			if (array[j] < array[i])
			////				break;
			//			if (array[i] == array[j])
			//				same = true;
			//			j--;
			//		}

			//		if (j == 0 && same)
			//			continue;
			//	}
				bool same = false;

					int j = i - 1;
				while ( j >= 0 && array[i] <= array[j]){
					width++;
					if (array[i] == array[j]){
						same = true;
					}
					j--;
					
				}
				j = i + 1;
				while (j< n && array[i] <= array[j]){
					width++;
					j++;
				}
		//		result[i] = width*array[i];
				int temp = width*array[i];
				if (temp == max && !same){
					maxn++;
				}
				else if (temp > max){
					max = temp;
					maxn = 1;
				}
				
			}

			cout << max << " " << maxn;
//			quickSort(result, 0, n);


		}
		else{
			int* temp = new int[n];
			memcpy(temp, array, n*sizeof(int));
			while (prev_permutation(array, array + n)){
				cal(array, n);
			}
			while (next_permutation(temp, temp + n))
				cal(temp, n);
//			Permutation(array, array, n, n);
			cout << maxInPer;
		}

   system("pause");
	}

