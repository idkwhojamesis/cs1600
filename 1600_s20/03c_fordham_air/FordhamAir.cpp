// FordhamAir.cpp 
// Add to this partially built code. 
// fill in code where there is a TODO


#include<iostream>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint); // show decimals even if not needed
	cout.precision(2); // two places to the right of the decimal

// TODO: enter the missing types below

	int time;
	float ticketPrice;
	char destination; //'C'=Chicago, 'P'=Portland, 'M'=Miami
	char typeOfDay; //'D'=weekDay 'E'=weekEnd
	bool isDayTime;
	bool isWeekend;
	static float MiamiDD = 150.0;
	static float MiamiDN = 100.0;
	static float MiamiED = 180.0;
	static float MiamiEN = 120.0;
	float factor;

	cout << "Welcome to Fordham Airlines!" << endl;

	cout << "What is your destination? ([C]hicago, [M]iami, [P]ortland) ";
	cin >> destination;

	cout << "What time will you travel? (Enter time between 0-2359) ";
	cin >> time;

// TODO: set isDayTime to true if time 5AM or later, but before 7PM 
    if (time >= 500 && time < 1900)
    {
        isDayTime = true;
    }
    else
    {
        isDayTime = false;
    }

	cout << "What type of day are you traveling? (week[E]nd or week[D]ay) ";
	cin >> typeOfDay;
// TODO: set isWeekend to true if typeOfDay  is 'E', otherwise false
    if (typeOfDay == 'E')
    {
        isWeekend = true;
    }
    else
    {
        isWeekend = false;
    }
	

// Depending upon the destination, and whether it is weekend, day/night
// set the appropriate price
// I recommend using a switch  
	switch (destination)
	{
	    case 'C':
	        factor = 0.5;
	        break;
	    case 'M':
	        factor = 1.0;
	        break;
	    case 'P':
	        factor = 2.0;
	        break;
	    default:
	        factor = 1.0;
	        break;
	}
	
	float miamiPrice;
	
	if (isDayTime)
	{
	    if (isWeekend)
	    {
	        miamiPrice = MiamiED;
	    }
	    else
	    {
	        miamiPrice = MiamiDD;
	    }
	}
	
	else
	{
	    if (isWeekend)
	    {
	        miamiPrice = MiamiEN;
	    }
	    else
	    {
	        miamiPrice = MiamiDN;
	    }
	}
	
	ticketPrice = miamiPrice * factor;

// I am providing much of the Input and Output dialog to simplify this program
	cout << "Each ticket will cost: $" << ticketPrice << endl;

	int numTickets;
	cout << "How many tickets do you want? ";
	cin >> numTickets;

// TODO: calculate the totalCost based on the number of tickets and ticketPrice, then print it
    float totalCost = ticketPrice * (float)numTickets;
	
	cout << "You owe: $" << totalCost << endl;

// TODO: declare a variable that will hold the user's payment
// prompt the user for "Amount paid? "
// read in the user's Payment
    float userPay;
    cout << "Amount paid? ";
    cin >> userPay;

// TODO: calculate the change (a float)
	float change = userPay - totalCost;
	
// TODO: If the user's payment is too little, then print this message:
    if (change < 0)
    {
	    cout << "That is too little! No tickets ordered.";
    }
    
// otherwise print these 2 lines:
	else
	{
		cout << "You will get in change: $" << change << endl;
		cout << "Your tickets have been ordered!";
	}
	return 0;
}

