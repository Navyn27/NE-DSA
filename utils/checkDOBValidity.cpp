#include <iostream>

using namespace std;

bool isDOBValid(const string& date) {
    if (date.length() != 10) return false;

    if (date[4] != '-' || date[7] != '-') return false;

    string yearStr = date.substr(0, 4);
    string monthStr = date.substr(5, 2);
    string dayStr = date.substr(8, 2);

    if (!isNumber(yearStr) || !isNumber(monthStr) || !isNumber(dayStr)) return false;

    int year = stoi(yearStr);
    int month = stoi(monthStr);
    int day = stoi(dayStr);

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    // Check for February
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29) return false;
        if (!isLeapYear && day > 28) return false;
    }

    if(year>2024) return false;
    if(month>6) return false;
    if(day>21) return false;

    return true;
}