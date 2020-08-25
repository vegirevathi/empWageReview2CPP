#include <iostream>
#include <ctime>
using namespace std;

class WorkingHrs {
	int empHrs;

	private:
	int calculateHrs() {
		const int FULL_TIME = 1;
		const int PART_TIME = 2;

		srand(time(NULL));
   	int empStatus = rand() % 3;

		switch (empStatus)
		{
		case FULL_TIME:
      	cout << " Employee is Full Time Present " << endl;
			empHrs = 8;
			break;
   	case PART_TIME:
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
