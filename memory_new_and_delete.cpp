#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numGuests = 0;
    int i = 0;

    // Initialization 
    cout << "How many guest? ";
    cin >> numGuests;

    // Check for valid input 
    if (numGuests <= 0)
    {
        cout << "Number of guests must be at least 1.\n";
        return 0;
    }

    // Create memory space for  x guests (an array of strings)
    string *guests = new string[numGuests];

    // Return memory address of guests array
    cout << "Memory address of guests array: " << guests << "\n";

    // Ignore the leftover newline character after reading numGuests
    cin.ignore();

    // Enter guest names
    for (i = 0; i < numGuests; i++)
    {
        cout << "Enter name for guest " << (i + 1) << ": ";
        getline (cin, guests[i]);   // Read full name (including space)
    }

    // Return memory address of each guest name
     for (i = 0; i < numGuests; i++)
    {
        cout << "Memorry address of guest " << (i + 1) << ": " << &guests[i] << "\n"; 
        cout << "Size of guest " << (i + 1) << ": " << sizeof(guests[i]) << "\n"; 
    }

    // Show all guests
    cout << "Guests checked in: \n"; 
    for (i = 0; i < numGuests; i++)
    {
        cout << guests[i] << "\n";
    }

    // Clean up memory
    delete[] guests;

    return 0;
}