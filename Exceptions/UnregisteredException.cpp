#include <iostream>
#include <string>

using namespace std;

void unregisteredError(string person)
{
    cerr << "___________________________________________________________\n\n";
    cerr << "❌ -- The entered "<<person<<"'s id is non existent\n\n";
    cerr << "___________________________________________________________\n\n";
    cerr << "Please register the individual first using options\n\n 1: Register a Patient\n 2: Register a Doctor\n\n Before proceeding to booking an appointment\n";
    cerr << "___________________________________________________________\n\n";
}