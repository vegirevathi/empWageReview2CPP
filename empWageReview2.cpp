#include <iostream>
#include <ctime>
using namespace std;

class WorkingHrs {
	private:
	int empHrs;
   int empStatus = rand() % 3;

	private:
	int calculateHrs() {
		switch (empStatus)
		{
		case 1:
      	cout << " Employee is Full Time Present " << endl;
			empHrs = 8;
			break;
   	case 2:
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

	friend void empWage(WorkingHrs wh);
};

void empWage(WorkingHrs wh) {
	int WAGE_PER_HOUR = 20;
	int dailyWage = wh.calculateHrs() * WAGE_PER_HOUR;
   cout << "Daily wage is " << dailyWage;
}


int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	WorkingHrs wh;
	empWage(wh);
	return 0;
}
