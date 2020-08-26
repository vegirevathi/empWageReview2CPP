#include <iostream>
#include <ctime>
using namespace std;


class WorkingHrs
{
	int empHrs;

	public:
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

	//friend class EmployeeWage;
};

class EmployeeWageBuilder1
{
	int numOfWorkingDays = 20;
	int numOfWorkingHrs = 100;
	int wagePerHr = 20;
	string companyName = "DMART";

	int workingDay = 0;
	int totalEmpHrs = 0;
	int workingHr = 0;


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


class EmployeeWageBuilder2
{
   int numOfWorkingDays = 25;
   int numOfWorkingHrs = 120;
   int wagePerHr = 25;
   string companyName = "Reliance";

   int workingDay = 0;
   int totalEmpHrs = 0;
   int workingHr = 0;


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
	EmployeeWageBuilder1 e1;
	e1.calculateWage(wh);
	EmployeeWageBuilder2 e2;
	e2.calculateWage(wh);
	return 0;
}
