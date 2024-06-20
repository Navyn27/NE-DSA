#include <iostream>
#include <string>

#include "./utils/handleCommands.cpp"

using namespace std;

int main()
{
    cout << "Enter your name/username to get started\n";
    string username;
    getline(cin, username);
    cout << "\n ________________________________________________________________________________________________\n\n";
    cout << "Hello " << username;
    cout << "\n ________________________________________________________________________________________________\n\n";
    cout << "Welcome to the Ruhengeri Referral Hospital Appointment Registration system\n\n _______________________________________________________________________________________________\n";
    cout << "Enter a command to get started, use only numbers, i:e 1 or 2 ..." << endl;

    handeCommands();

    return 0;
}