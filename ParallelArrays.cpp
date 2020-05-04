#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

const int SIZE = 50;
double hourlyPay[SIZE]; // use in getHourlyPay

int highestPay(double grossPay[], int numberOfEmployees);
int lowestPay(double grossPay[], int numberOfEmployees);
void getHourlyPay(string NameArray[], int NumberOfNamesFilled);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

	string employeeNames[SIZE];
	double grossPay[SIZE];
	double totalHours[SIZE];
    
    // TODO: Read in the employee names and return the numberOfEmployees.
    int numberOfEmployees = 0;
    while (true) {
        string enterName;
        cout << "Enter an employee name: ";
        getline(cin, enterName);
        if (enterName == "quit") {
            break;
        }
        employeeNames[numberOfEmployees] = enterName;
        numberOfEmployees++;
    }

    getHourlyPay(employeeNames, numberOfEmployees);
    
    // TODO: Read in the daily hours for each employee. There will be 7 entries per week. 
    for (int i = 0; i < numberOfEmployees; i++) {
        grossPay[i] = 0;
        double total = 0;
        
        cout << "Enter " << employeeNames[i] << "'s hours for 7 days (0 if day off): ";
        for (int i = 0; i < 7; i++) {
          double dayHour;
          cin >> dayHour;
          total += dayHour;
        }
        totalHours[i] = total;
        // Calculating gross pay
        grossPay[i] = totalHours[i] * hourlyPay[i];
    }
 
    // NOTE: This prints the headers with a set width for each field.  Follow this format for the entries
    cout << setw(20) << "Employee Name" << setw(12) << "Total Hours" << setw(10) << "Gross Pay" << endl;
    
    // TODO: For each employee, print: name, total hours and gross pay
    for (int i = 0; i < numberOfEmployees; i++) {
        cout << setw(20) << employeeNames[i] << setw(12) << totalHours[i] << setw(10) << grossPay[i] << endl;
    }
    
	cout << "Highest Pay: $" <<  grossPay[highestPay(grossPay, numberOfEmployees)] << " " << employeeNames[highestPay(grossPay, numberOfEmployees)] << "\n";
	cout << "Lowest Pay: $" <<  grossPay[lowestPay(grossPay, numberOfEmployees)] << " " << employeeNames[lowestPay(grossPay, numberOfEmployees)] << "\n";
    return 0;
}

int highestPay(double grossPay[], int numberOfEmployees) {
    int result = 0;
    for (int i = 0; i < numberOfEmployees; i++) {
        if (grossPay[i] > grossPay[result]) result = i;
    }
    return result;
}
int lowestPay(double grossPay[], int numberOfEmployees) {
    int result = 0;
    for (int i = 0; i < numberOfEmployees; i++) {
        if (grossPay[i] < grossPay[result]) result = i;
    }
    return result;
}

void getHourlyPay(string NameArray[], int NumberOfNamesFilled) {
    for (int i = 0; i < NumberOfNamesFilled; i++) {
        cout << "Enter " << NameArray[i] << "'s hourly pay rate: ";
        double payRate;
        cin >> payRate;
        hourlyPay[i] = payRate;
    }
}

