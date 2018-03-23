#include<iostream>
using namespace std;

/** ÊÇ·ñÊÇÈòÄê */
bool isLeapYear(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

class DateTime{
public:
	int year, month, day, hour, minute,second;
	
	void operator ++ (){
		int monthLengths[] = {0, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (isLeapYear(year)){
			monthLengths[2] = 29;
		}
		else{
			monthLengths[2] = 28;
		}

		if (second == 59){
			second = 0;
			minute++;
		}
		else{
			second++;
		}

		if (minute == 60){
			minute = 0;
			hour++;
		}
		else{
			
		}
		
		if (hour == 24){
			hour = 0;
			day++;
		}
		else{
		
		}

		if (day == (monthLengths[month] + 1)){
			day = 1;
			month++;
		}
		else{
			
		}
		if (month == 13){
			month = 1;
			year++;
		}
		else{
			
		}

		
	}
};


int main(){
	DateTime d;
	cin >> d.year >> d.month >> d.day >> d.hour >> d.minute >> d.second;
	++d;
	cout << d.year << " " << d.month << " " << d.day << " " << d.hour << " " << d.minute << " " << d.second;
//	system("pause");
	return 0;
}