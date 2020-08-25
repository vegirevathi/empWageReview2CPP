#include <iostream>
#include <ctime>
using namespace std;

class WorkingHrs {
	int empHrs;

	private:
	int calculateHrs() {
		const int FULL_TIME = 1;
		const int PART_TIME = 2;

   	int empStatus = rand() % 3;

		switch (empStatus)
		{
			case FULL_TIME:
   	   	cout << "Employee is Full Time Present " << endl;
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

	friend int totalWorkingHrs(WorkingHrs wh);
};

int totalWorkingHrs(WorkingHrs wh) {
	const int NUM_OF_WORKING_DAYS = 20;
	const int TOTAL_WORKING_HRS = 100;
	int workingDay = 0;
	int totalEmpHrs = 0;
	int workingHr = 0;

	while (workingDay <= NUM_OF_WORKING_DAYS && workingHr <= TOTAL_WORKING_HRS) {
		totalEmpHrs += wh.calculateHrs();
		workingDay ++;
	}
	return totalEmpHrs;
}

void empWage() {
	int WAGE_PER_HOUR = 20;
	WorkingHrs wh;
	int monthlyWage = totalWorkingHrs(wh) * WAGE_PER_HOUR;
   cout << "monthly wage is " << monthlyWage;
}


int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	empWage();
	return 0;
}
