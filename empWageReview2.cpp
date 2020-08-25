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

	friend class EmployeeWage;
};

class EmployeeWage {
	int numOfWorkingDays;
	int numOfWorkingHrs;
	int wagePerHr;
	string companyName;

	int workingDay = 0;
	int totalEmpHrs = 0;
	int workingHr = 0;

	public:
	EmployeeWage(string company, int workingDays, int workingHrs, int wage)
	{
		companyName = company;
		numOfWorkingDays = workingDays;
		numOfWorkingHrs = workingHrs;
		wagePerHr = wage;
	}

	public:
	void calculateWage(WorkingHrs wh) {
		while (workingDay <= numOfWorkingDays && workingHr <= numOfWorkingHrs)
		{
			totalEmpHrs += wh.calculateHrs();
			workingDay ++;
		}
		int monthlyWage = totalEmpHrs * wagePerHr;
		cout << "Monthly wage for company " << companyName << " is " << monthlyWage << endl;
	}
};


int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	WorkingHrs wh;
	EmployeeWage e1 = EmployeeWage("DMART", 20, 100, 20);
	e1.calculateWage(wh);
	EmployeeWage e2 = EmployeeWage("Reliance", 25, 120, 30);
	e2.calculateWage(wh);
	return 0;
}
