#include <iostream>
using namespace std;

void printLoanPayments(double loanAmount, double annualInterest, double monthlyPayment);

int main() {
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	double loanAmount, annualInterest, monthlyPayment;
	cout << "What is the loan amount? ";
	cin >> loanAmount;
	cout << "What is the annual interest? Type answer as a decimal (.1 for 10 % , etc) ";
	cin >> annualInterest;
	if (annualInterest > .25) {
	    do {
	        cout << "Interest greater than 25% is illegal and is called 'criminal usury'." <<endl;
	        cout << "Enter an interest rate less than 25%" << endl;
	        cout << "What is the annual interest? Type answer as a decimal (.1 for 10%, etc) ";
	        cin >> annualInterest;
	    } 
	    while (annualInterest > .25);
	}
    cout << "What is the monthly payment? ";
    cin >> monthlyPayment;
    if (monthlyPayment < loanAmount * annualInterest / 12) {
        cout <<"ERROR: monthly payment must be greater than $" << (loanAmount * annualInterest / 12) << endl << "Please rerun with larger payment. Goodbye." << endl;
        return 1;
    }
    else
        printLoanPayments(loanAmount, annualInterest, monthlyPayment);
	return 0;
}

void printLoanPayments(double loanAmount, double annualInterest, double monthlyPayment) {
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
    int month = 1;
    double monthlyInterest = annualInterest/12;
    double balance = loanAmount;
    double payment = monthlyPayment;
    double interest;
    double paidOnBalance;
    double totalIntPaid = 0;
    cout << "Month	Balance	Payment	PaidOnBalance	Interest	Total Int. Paid \n";
    do {
        double interestAccrued = monthlyInterest * balance;
        paidOnBalance = payment - interestAccrued;
        balance -= paidOnBalance;
        totalIntPaid += interestAccrued;
        cout << month << "      " << balance << "      " << payment << "     " << paidOnBalance  << "       " << interestAccrued << "       " << totalIntPaid << endl;
        if (month % 12 == 0) {
            for (int i = 0; i < 50; i++) {
                cout << '$';
            }
            cout << endl;
        }
        month += 1;
    }
    while  (balance > 0);
}
