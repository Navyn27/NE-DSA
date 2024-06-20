#include <iostream>
#include <string>

using namespace std;

class Patient
{
    int patientId;
    string patientName;
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
    string getName()
    {
        return patientName;
    }
    string getDOB()
    {
        return patientDOB;
    }
    int getId()
    {
        return patientId;
    }
    Patient *next = NULL;
    Patient(bool isHead, Patient *firstPatient, string patientName, string patientGender, string patientDOB)
    {
        if (isHead && firstPatient == NULL)
        {
            this->patientId = 1;
        }
        else
        {
            this->patientId = makeId(firstPatient);
        }
        this->patientDOB = patientDOB;
        this->patientGender = patientGender;
        this->firstPatient = firstPatient;
        this->patientName = patientName;
    }
    void display()
    {
        cout << "ID:" << this->getId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Date of Birth: " << this->getDOB() << endl;
        cout << "Gender: " << this->getGender() << endl;
    }
};