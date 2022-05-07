// Adam LaDue
// CIS 1202 501
// May 6, 2022



#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes
void getEmployeeData(int[], int[], double[], int);
void calcPay(int[], int[], double[], double[], int);

// Main Program
int main()
{
	cout << "* Welcome to The Payroll System *" << endl;
	const int AMNT = 7;
	int empID[AMNT] = { 5964609, 5931928, 2328911, 8031549,
	7188409, 7271179, 3994243 };
	int hours[AMNT];
	double payRate[AMNT];
	double wages[AMNT];

	ofstream backupFile;
	backupFile.open("EmployeeData.txt");

	getEmployeeData(empID, hours, payRate, AMNT);
	calcPay(empID, hours, payRate, wages, AMNT);

	for (int i = 0; i < AMNT; i++) // Interaction Menu
	{
		cout << fixed << showpoint << setprecision(2); 
		cout << "_________________\n";
		cout << " Employee # " << empID[i] << "\n";
		cout << " Pay Rate = $" << payRate[i] << endl;
		cout << " Hours Worked = " << hours[i] << endl;
		cout << " Gross Pay = $" << wages[i] << endl;
		cout << "_________________\n";
		backupFile << empID[i] << " " << hours[i] << " " << payRate[i] << " " << endl;
	}
	backupFile.close();
	system("pause");
	return 0;
}
