#include<iostream>
using namespace std;

#include <string>

void Get2Ints(int& x, int& y);
void Swap(int& a, int& b);
void SwapAndMult(int& a, int& b, int mult);
void Print2Ints(int a, int b);

int main()
{
    int x;
    int y;
    int mult;
    Get2Ints(x,y);
    Print2Ints(x,y);
    Swap(x,y);
    cout << "After swap:" << endl;
    Print2Ints(x,y);
    cout << "Enter the multiplier: ";
    cin >> mult;
    cout << mult << endl;
    SwapAndMult(x, y, mult);
    cout << "After swap and mult: " << endl;
    Print2Ints(x,y);
}

void Get2Ints(int& x, int& y)
{
    int a;
    int b;
    cout << "Input two numbers: ";
    cin >> a;
    cin >> b;
    x = a;
    y = b;
}

void Print2Ints(int a, int b)
{
    cout << a << " " << b << endl;
}

void Swap(int& a, int& b)
{
    int p;
    p = a;
    a = b;
    b = p;
}
void SwapAndMult(int& a, int& b, int mult)
{
    Swap(a,b);
    a *= mult;
    b *= mult;
}
