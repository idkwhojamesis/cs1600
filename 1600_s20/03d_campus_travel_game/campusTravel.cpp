// TODO: Write your campusTravel.cpp code here
#include <iostream>
using namespace std;

#include <string>

int main()
{
    int playerDist = 14;
    cout << "You are " << playerDist << " mile(s) from campus!\n";
    int counter = 0;
    
    while (counter < 4)
    {
        cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) "; 
        string travel;
        getline(cin,travel);
        if (travel == "1" || travel == "2" || travel == "3")
        {
            int travelInt = stoi(travel);
            counter++;
            switch (travelInt)
            {
                case 1:
                    playerDist -= 2;
                    break;
                case 2:
                    playerDist -= 5;
                    break;
                case 3:
                    playerDist -= 10;
                    break;
                default:
                    cout << "error";
                    return 1;
            }
            if (playerDist <= 0) break;
            cout << "You are " << playerDist << " mile(s) from campus!\n";
        }
        else
        {
            cout << "Invalid choice, try again!\n";
        }
    }
    
    if (playerDist == 0)
    {
        cout << "You are " << playerDist << " mile(s) from campus!\n";
        cout << "You have won!";
    }
    else 
    {
        if (playerDist < 0)
            cout << "You have over-shot your target!\n";
        if (playerDist > 0)
            cout << "You haven't reached your target!\n";
        cout << "You lose!";
    }
}