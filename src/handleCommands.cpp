#include <iostream>
#include <string>

#include "../Exceptions/InvalidCommandException.cpp"
#include "../utils/checkIsInteger.cpp"

#include "processCommands.cpp"

using namespace std;

// Function to handle user commands from the menu
void handleCommands()
{
    string command;  // Variable to store user input
    // Display the menu options to the user
    cout << "Menu: \n\n";
    cout << "1. -- Register a Patient\n";
    cout << "2. -- Register a Doctor\n";
    cout << "3. -- Book an Appointment\n";
    cout << "4. -- Display Registered Patients\n";
    cout << "5. -- Display Registered Doctors\n";
    cout << "6. -- Display Registered Appointments\n";
    cout << "7. -- Exit the System\n\n";
    start:
    try
    {
        cin >> command;  // Read user input
        // Validate the command input
        if (!stoi(command) || stoi(command) > 6 || stoi(command) < 1 || !isNumber(command))
        {
            throw("Invalid Command");  // Throw an exception if command is invalid
            goto start;  // Restart command input process
        }
        if (stoi(command) == 7)
            exitProgram();  // Exit the program if command is 7
        else
            processCommands(command);  // Process valid commands
    }
    catch (invalid_argument const &ex)
    {
        invalidCommandError();  // Handle invalid argument exceptions
        goto start;
    }
    catch(...)
        {
            invalidCommandError();
            goto start;
        }
}