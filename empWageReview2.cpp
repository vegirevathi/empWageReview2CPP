#include <iostream>
#include <ctime>
using namespace std;

int getWorkingHrs() {
	int empHrs;
   srand(time(NULL));

   int empStatus = rand() % 3;

	const int IS_FULL_TIME = 1;
	const int IS_PART_TIME = 2;

	switch (empStatus)
	{
	case IS_FULL_TIME:
      cout << " Employee is Full Time Present " << endl;
		empHrs = 8;
		break;
   case IS_PART_TIME:
		cout << "Employee is Part Time Present " << endl;
		empHrs = 4;
		break;
	default:
      cout << "Employee is Absent " << endl;
		empHrs = 0;
		break;
   }

	return empHrs;
}

void empWage() {
	int WAGE_PER_HOUR = 20;
	int dailyWage = getWorkingHrs() * WAGE_PER_HOUR;
   cout << "Daily wage is " << dailyWage;
}


int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	empWage();
	return 0;
}
