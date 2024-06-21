#include <iostream>
#include <string>

#include "./src/handleCommands.cpp"

using namespace std;

int main()
{
    cout<<"****************************************************************************************************************************************************************************************************\n";
    cout<<"****************************************************************************************************************************************************************************************************\n";
    cout << "Enter your name/username to get started\n";
    string username;
    getline(cin, username);
    cout << "\n ________________________________________________________________________________________________\n\n";
    cout << "                                        Hello " << username;
    cout << "\n ________________________________________________________________________________________________\n\n";
    cout << "\033["<< "33" << "m"<<"               Welcome to the Ruhengeri Referral Hospital Appointment Registration system\n\n                                   Brought to you by Yvan Ishimwe Sugira                  \n _______________________________________________________________________________________________\n"<<"\033[0m";;
    cout << "Enter a command to get started, use only numbers, i:e 1 or 2 ...\n\n";

    // Function call to handle user commands
    handleCommands();

    return 0;
}