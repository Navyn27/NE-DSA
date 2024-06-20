#include <iostream>
#include <string>

// Importing the LinkedLists' classes
// #include "../LinkedLists/appointmentsLL.cpp"
#include "../LinkedLists/doctorsLL.cpp"
#include "../LinkedLists/patientsLL.cpp"
#include "../Exceptions/UnregisteredException.cpp"

#include "./exitProgram.cpp"

using namespace std;

Patient *patientTail = NULL;
Doctor *doctorTail = NULL;

void registerPatient()
{
    string patientName;
    string patientDOB;
    string patientGender;
    cout << "Enter the Patient's name: ";
    cin.ignore();
    getline(cin, patientName);
    cout << "Enter the Patient's DOB: ";
    getline(cin, patientDOB);
    cout << "Enter the Patient's gender: ";
    getline(cin, patientGender);

    Patient *newPatient = new Patient(false, patientTail, patientName, patientGender, patientDOB);
    cout << "Patient Registered successfully" << endl;
    patientTail->next = newPatient;
    newPatient->display();
    patientTail = newPatient;
    return;
}

void displayPatients(Patient *patientInitializer)
{
    if (patientInitializer->next)
    {
        Patient *currentPatient = patientInitializer->next;
        cout << "___________________________________________________________________________________________________\n\n";
        cout << "                      Displaying List of Patients of Ruhengeri Referral Hospital                    \n\n";
        cout << "___________________________________________________________________________________________________\n\n";

        cout << "Patients\n";
        cout << "----------------------------------------------------------\n";
        do
        {
            currentPatient->display();
            currentPatient = currentPatient->next;
        } while (currentPatient->next != NULL);
    }
    else
    {
        cout << "There are no registered doctors\n";
    }
}

void registerDoctor()
{
    string doctorName;
    string doctorSpec;

    cout << "Enter the Doctor's name: ";
    cin.ignore();
    getline(cin, doctorName);
    cout << "Enter the Doctor's Specialization: ";
    getline(cin, doctorSpec);

    Doctor *newDoctor = new Doctor(false, doctorTail, doctorName, doctorSpec);
    cout << "Patient Registered successfully" << endl;
    doctorTail->next = newDoctor;
    newDoctor->display();
    doctorTail = newDoctor;
}

void displayDoctors(Doctor *doctorInitializer)
{
    if (doctorInitializer->next)
    {
        Doctor *currentDoctor = doctorInitializer->next;
        cout << "___________________________________________________________________________________________________\n\n";
        cout << "                      Displaying List of Doctors of Ruhengeri Referral Hospital                    \n\n";
        cout << "___________________________________________________________________________________________________\n\n";
        cout << "Doctors\n";
        cout << "----------------------------------------------------------\n";
        do
        {
            currentDoctor->display();
            currentDoctor = currentDoctor->next;
        } while (currentDoctor->next != NULL);
    }
    else
    {
        cout << "There are no registered doctors\n";
    }
}

void registerAppointment()
{
    int doctorId;
    int patientId;
    int appointmentDate;

    cout << "Enter the Doctor's Id: ";
    cin.ignore();
    getline(cin, doctorName);
    cout << "Enter the Patient's Id: ";
    getline(cin, doctorSpec);

    if (!patientIdExists(patientId) || !doctorIdExists(doctorId))
    {
        unregisteredError();
    }
    else
    {
        Doctor *newDoctor = new Doctor(false, doctorTail, doctorName, doctorSpec);
        cout << "Patient Registered successfully" << endl;
        doctorTail->next = newDoctor;
        newDoctor->display();
        doctorTail = newDoctor;
    }
}

void displayAppointments()
{
}

void processCommands(int initialCommand)
{
    Patient *initialiserPatient = new Patient(true, NULL, "Init", "Ïnit", "0000-00-00");
    Doctor *initialiserDoctor = new Doctor(true, NULL, "Init", "Init");

    patientTail = initialiserPatient;
    doctorTail = initialiserDoctor;

    int command = initialCommand;
    while (command != 7)
    {
        try
        {
            switch (command)
            {
            case 1:
                registerPatient();
            case 2:
                registerDoctor();
            case 3:
                registerAppointment();
            case 4:
                displayPatients(initialiserPatient);
            case 5:
                displayDoctors(initialiserDoctor);
            case 6:
                displayAppointments();
            default:
                invalidCommandError();
            }
        }
        catch (invalid_argument const &ex)
        {
            invalidCommandError();
        }
        cout << "Next Command:";
        cin >> command;
    }
}