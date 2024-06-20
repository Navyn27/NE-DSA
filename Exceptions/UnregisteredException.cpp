#include <iostream>
#include <string>

using namespace std;

void unregisteredError()
{
    cerr<<"                            ❌❌\n";
    cerr << "The entered individual's id (patient/doctor) is non existent\n\n";
    cerr << "Please register the individual first using options\n\n 1: Register a Patient\n 2: Register a Doctor\n\n Before proceeding to registering an appointment\n";
}