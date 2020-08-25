#include <iostream>
#include <ctime>
using namespace std;

int main() {
	cout << "Welcome to Employee Wage Computation " << endl;

	int empStatus;
	srand(time(NULL));
	empStatus = rand() % 2;
	if (empStatus == 1) {
		cout << "employee is Present " << endl;
	}
	else {
		cout << "Employee is Absent " << endl;
	}

	return 0;
}
