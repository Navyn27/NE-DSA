#include <iostream>
#include <string>

using namespace std;

class Doctor
{
    int doctorId;
    string doctorName;
    string doctorSpecialization;
    Doctor *firstDoctor;
    int makeId()
    {
        if (firstDoctor)
        {
            return firstDoctor->getId() + 1;
        }
        else
        {
            return 1;
        }
    }

public:
    string getSpecialization()
    {
        return doctorSpecialization;
    }
    string getName()
    {
        return doctorName;
    }
    int getId()
    {
        return doctorId;
    }
    Doctor *next = NULL;
    Doctor(bool isHead, Doctor *firstDoctor, string doctorName, string doctorSpecialization)
    {
        if (isHead)
        {
            this->doctorId = 0;
        }
        else
        {
            this->doctorId = makeId();
        }
        this->doctorSpecialization = doctorSpecialization;
        this->firstDoctor = firstDoctor;
        this->doctorName = doctorName;
    }

    void display()
    {
        cout << "ID:" << this->getId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Specialization: " << this->getSpecialization() << endl;
    }
};