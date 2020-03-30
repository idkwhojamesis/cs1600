#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

//Todo: declare your functions here.
int main()
{
    ifstream infile;
    char fileName[256];
    cout <<"Enter the name of the file to be analyzed:";
    cin >> fileName;

    // TODO: Open the filename and test that it was successful
    infile.open(fileName);
    if (infile.fail())
    {
        infile.close();
        cout << "File " << fileName << " cannot be opened.";
        return 1;
    }
    

    // Used to read in te date, price and the rest.
    double price;
    string date, junk;
    // Going to store the date of the high price and low price
    string lowDate, highDate;

    // Going to store the high price and low price.
    double high=numeric_limits<double>::min(), low=numeric_limits<double>::max();

    cout.precision(2);
    cout.setf(ios::fixed);
    
    // TODO: Implement a loop that reads line by line from input.
    // TODO: A line has the date, the price and the rest (use junk)
    // TODO: Stop reading on end of input.
    string str;
    while (getline(infile, str))
    {
        date = str.substr(0, 10);
        price = stod(str.substr(11, 11));
    
        cout << date << " " << price << endl;

        // TODO: Find the highest price
        // TODO: Save the date of the price
        if (price > high)
        {
            high = price;
            highDate = date;
        }

        // TODO: Find the lowest price
        // TODO: Save the date of the price
        if (price < low)
        {
            low = price;
            lowDate = date;
        }
    }
    cout << "High: " << high << " on " << highDate << endl;
    cout << "Low:  " << low << " on " << lowDate << endl;
    
    infile.close();
    return 0;
}
