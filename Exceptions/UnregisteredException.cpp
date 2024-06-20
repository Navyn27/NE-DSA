#include <iostream>
#include <string>

using namespace std;

void logUnregisteredError(string person)
{
    cerr << "The requested " << person << " is non existent\n\n";
    cerr << "Please register the individual first using options\n\n 1: Register a Patient\n 2: Register a Doctor\n\n Before proceeding to registering an appointment\n;
}