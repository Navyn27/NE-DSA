#include <iostream>
#include <string>

#include "../Exceptions/InvalidCommandException.cpp"
#include "checkIsInteger.cpp"

#include "processCommands.cpp"

using namespace std;

void handeCommands()
{
    string command;

start:
    cout << "Menu: \n\n";
    cout << "1. Register a Patient\n";
    cout << "2. Register a Doctor\n";
    cout << "3. Book an Appointment\n";
    cout << "4. Display Registered Patients\n";
    cout << "5. Display Registered Doctors\n";
    cout << "6. Display Registered Appointments\n";
    cout << "7. Exit the System\n";

    try
    {
        cin >> command;
        if (!stoi(command) || stoi(command) > 6 || stoi(command) < 1 || !isNumber(command))
        {
            throw("Invalid Command");
            goto start;
        }
        if (stoi(command) == 7)
            exitProgram();
        else
            processCommands(stoi(command));
    }
    catch (invalid_argument const &ex)
    {
        invalidCommandError();
    }
}