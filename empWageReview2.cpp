#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class EmployeeWage
{
	public:
	virtual int calculateHrs() = 0;
};


class WorkingHrs : EmployeeWage
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
};

class EmployeeWageBuilder
{
	public:
   string companyName;
   int numOfWorkingDays;
   int numOfWorkingHrs;
   int wagePerHr;
	int numOfMonths;

	EmployeeWageBuilder(string company, int months, int workingDays, int workingHrs, int wage)
	{
		this->companyName = company;
		this->numOfWorkingHrs = workingHrs;
		this->numOfWorkingDays = workingDays;
		this->wagePerHr = wage;
		this->numOfMonths = months;
	}
};

void write(vector<int>, EmployeeWageBuilder);

void calculateWage(EmployeeWageBuilder e) {
	int workingDay = 0;
	int totalEmpHrs = 0;
	int workingHr = 0;
	vector <int> wages;

	WorkingHrs wh;
   while (workingDay <= e.numOfWorkingDays && workingHr <= e.numOfWorkingHrs)
   {
		int dailyWage = wh.calculateHrs() * e.wagePerHr;
		wages.push_back(dailyWage);

      totalEmpHrs += wh.calculateHrs();
      workingDay ++;
   }
   int monthlyWage = totalEmpHrs * e.wagePerHr;
   cout << "Monthly wage for company " << e.companyName << " is " << monthlyWage << endl;

	write(wages, e);
}

void write(vector<int> wages, EmployeeWageBuilder e)
{
	fstream myfile;
	myfile.open("Wages.csv", ios::out | ios::app);
	myfile.seekg(0, ios::end);

	if(myfile.is_open())
	{
		if(myfile.tellp() == 0)
		{
			myfile << "Company, Month, Day, DailyWage, MonthlyWage " << endl;
		}

		myfile.seekg(0, ios::beg);
		for (int month = 1; month <= e.numOfMonths; month++)
		{
			for (int day = 1; day <= e.numOfWorkingDays; day++)
			{
				wages[month] += wages[day];
				myfile << e.companyName << ", " << month << ", " << day << ", " << wages[day] << ", " << wages[month] << endl;
			}
			wages[month] = 0;
		}
	}
	myfile.close();
}

int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	EmployeeWageBuilder e1 = EmployeeWageBuilder("DMART", 2, 20, 100, 20);
	calculateWage(e1);
	EmployeeWageBuilder e2 = EmployeeWageBuilder("Reliance", 3, 25, 120, 30);
	calculateWage(e2);

	return 0;
}
