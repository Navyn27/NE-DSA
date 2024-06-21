#include <iostream>
#include <string>

using namespace std;

bool isGenderValid(const string& gender) {
    return gender == "Male" || gender == "Female";
}