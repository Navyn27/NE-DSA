#include <iostream>
#include <string>

#include "person.cpp"
using namespace std;

class Patient : public Person
{
    string patientDOB;
    string patientGender;
    Patient *firstPatient;
    int makeId(Patient *firstPatient)
    {
        if (firstPatient)
        {
            return firstPatient->getId() + 1;
        }
        else
        {
            return 1;
        }
    }

public:
    string getGender()
    {
        return patientGender;
    }
    string getDOB()
    {
        return patientDOB;
    }
    Patient *nextPatient;
    Patient(bool isHead, Patient *firstPatient, string patientName, string patientGender, string patientDOB)
    {
        if (isHead)
        {

            this->firstPatient = NULL;
        }
        else
        {
            this->firstPatient = firstPatient;
        }
        Person(makeId(firstPatient), patientName);
        this->patientDOB = patientDOB;
        this->patientGender = patientGender;
    }
};

void displayPatients(Patient *patient)
{
    cout << "___________________________________________________________________________________________________\n\n";
    cout << "                      Displaying List of Patients of Ruhengeri Referral Hospital                    \n\n";
    cout << "___________________________________________________________________________________________________\n\n";
    while (patient->nextPatient != NULL)
    {
        cout << "----------------------------------------------------------";
        cout << "ID:" << patient->getId();
        cout << ", Name: " << patient->getName();
        cout << ", Date of Birth: " << patient->getDOB();
        cout << ", Gender: " << patient->getGender() << endl;
        patient = patient->nextPatient;
    }
}
int main()
{
    Patient *firstPatient = new Patient(true, nullptr, "John", "Male", "1990-01-01");
}