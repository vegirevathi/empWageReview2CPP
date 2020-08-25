#include <iostream>
#include <ctime>
using namespace std;

void empWage() {
	int empStatus;
	const int WAGE_PER_HOUR = 20;
	int empHrs;
   srand(time(NULL));
   empStatus = rand() % 2;
   if (empStatus == 1) {
      cout << "employee is Present " << endl;
		empHrs = 8;
   }
   else {
      cout << "Employee is Absent " << endl;
		empHrs = 0;
   }

	int dailyWage = empHrs * WAGE_PER_HOUR;
	cout << "Daily wage is " << dailyWage;
}


int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	empWage();
	return 0;
}
