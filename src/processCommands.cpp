//Importing necessary C++ inbuilt libraries
#include <iostream>
#include <string>
#include <limits>

// Importing the LinkedLists' classes
#include "../LinkedLists/appointmentsLL.cpp"
#include "../LinkedLists/doctorsLL.cpp"
#include "../LinkedLists/patientsLL.cpp"

//Importing exceptions
#include "../Exceptions/UnregisteredException.cpp"

//Including necessary utilities used for Creating and Reading operations
#include "../utils/exitProgram.cpp"
#include "../utils/checkIdValidity.cpp"
#include "../utils/checkDateValidity.cpp"
#include "../utils/checkGenderValidity.cpp"
#include "../utils/checkDOBValidity.cpp"

//Including the standard namespace
using namespace std;

//Initializing the patient and doctor tail pointers
Patient *patientTail = NULL;
Doctor *doctorTail = NULL;
Appointment *appointmentTail = NULL;

//Function to register a patient
void registerPatient()
{
    try {
        string patientName;
        string patientDOB;
        string patientGender;
        cout << "Enter the Patient's name: ";
        // To clear the input buffer
        cin.ignore();
        getline(cin, patientName);
        enterPatDOB:
        cout << "Enter the Patient's DOB (Format: YYYY-MM-DD): ";
        getline(cin, patientDOB);
        if(!isDOBValid(patientDOB)){
            invalidCommandError();
            goto enterPatDOB;
        }
        enterPatGender:
        cout << "Enter the Patient's gender (Male/Female): ";
        getline(cin, patientGender);
        if(!isGenderValid(patientGender)){
            invalidCommandError();
            goto enterPatGender;
        }

        Patient *newPatient = new Patient(false, patientTail, patientName, patientGender, patientDOB);
        cout << "----------------------------------------------------------\n";
        cout << "-- Patient Registered successfully" << endl;
        cout << "----------------------------------------------------------\n";
        patientTail->next = newPatient;
        newPatient->display();
        patientTail = newPatient;
    } catch (const exception& e) {
        invalidCommandError();  // Assuming this function handles the error appropriately
    }
}

//Function to display the list of registered patients
void displayPatients(Patient *patientInitializer)
{
    try {
        // Starting from the second node assuming the first node is a dummy node
        if (patientInitializer->next)
        {
            Patient *currentPatient = patientInitializer->next;
            cout << "___________________________________________________________________________________________________\n\n";
            cout << "                      Displaying List of Patients of Ruhengeri Referral Hospital                    \n\n";
            cout << "___________________________________________________________________________________________________\n\n";

            cout << "Patients\n";
            cout << "----------------------------------------------------------\n";
            do{
                currentPatient->display();
                currentPatient = currentPatient->next;
            }while(currentPatient);
        }
        else
        {
            cout << "----------------------------------------------------------\n";
            cout << "❗️-- There are no registered patients\n";
            cout << "----------------------------------------------------------\n";
        }
    } catch (const exception& e) {
        invalidCommandError();
    }
}

//Function to register a doctor
void registerDoctor()
{
    try {
        string doctorName;
        string doctorSpec;

        cout << "Enter the Doctor's name: ";

        // To clear the input buffe
        cin.ignore();
        getline(cin, doctorName);
        cout << "Enter the Doctor's Specialization: ";
        getline(cin, doctorSpec);

        Doctor *newDoctor = new Doctor(false, doctorTail, doctorName, doctorSpec);
        cout << "----------------------------------------------------------\n";
            cout << "-- Doctor Registered successfully" << endl;
            cout << "----------------------------------------------------------\n";
        doctorTail->next = newDoctor;
        newDoctor->display();
        doctorTail = newDoctor;
    } catch (const exception& e) {
        invalidCommandError();
    }
}

//Function to display the list of registered doctors
void displayDoctors(Doctor *doctorInitializer)
{
    try {
        // Starting from the second node assuming the first node is a dummy node
        if (doctorInitializer->next)
        {
            Doctor *currentDoctor = doctorInitializer->next;
            cout << "___________________________________________________________________________________________________\n\n";
            cout << "                      Displaying List of Doctors of Ruhengeri Referral Hospital                    \n\n";
            cout << "___________________________________________________________________________________________________\n\n";
            cout << "Doctors\n";
            cout << "----------------------------------------------------------\n";
            while(currentDoctor)
            {
                currentDoctor->display();
                currentDoctor = currentDoctor->next;
            }
        }
        else
        {   
            cout << "----------------------------------------------------------\n";
            cout << "❗️-- There are no registered doctors\n";
            cout << "----------------------------------------------------------\n";
        }
    } catch (const exception& e) {
        invalidCommandError();
    }
}

//Function to register an appointment
void registerAppointment(Patient *patientInitializer, Doctor *doctorInitializer)
{
    try {
        string doctorId;
        string patientId;
        string appointmentDate;
        enterDoc:
        cout << "Enter the Doctor's Id: ";
        cin>>doctorId;
        if(!isNumber(doctorId)){
            invalidCommandError();
            goto enterDoc;
        }
        enterPat:
        cout << "Enter the Patient's Id: ";
        cin>>patientId;
        if(!isNumber(patientId)){
            invalidCommandError();
            goto enterPat;
        }
        enterDate:
        // Clear input buffer before reading the date
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the Appointment Date: ";
        getline(cin, appointmentDate);
        if(!isDateValid(appointmentDate)){
            invalidCommandError();
            goto enterDate;
        }

        if (!isPatientIdValid(patientInitializer,stoi(patientId)) || stoi(patientId) == 0)
        {
            unregisteredError("patient");
        }
        else if(!isDoctorIdValid(doctorInitializer,stoi(doctorId)) || stoi(doctorId) == 0){
            unregisteredError("doctor");
        }
        else
        {
            Appointment *newAppointment = new Appointment(appointmentTail, stoi(doctorId), stoi(patientId), appointmentDate);
            cout << "----------------------------------------------------------\n";
            cout << "-- Appointment Registered successfully" << endl;
            cout << "----------------------------------------------------------\n";
            appointmentTail->next = newAppointment;
            newAppointment->display();
            appointmentTail = newAppointment;
        }
    } catch (const exception& e) {
        invalidCommandError();
    }
}

//Function to display the list of registered appointments
void displayAppointments(Appointment *appointmentInitializer)
{
    try {
        // Starting from the second node assuming the first node is a dummy node
        if (appointmentInitializer->next)
        {
            Appointment *currentAppointment = appointmentInitializer->next;
            cout << "Appointments\n";
            cout << "----------------------------------------------------------\n";
            while(currentAppointment)
            {
                currentAppointment->display();
                currentAppointment = currentAppointment->next;
            }
        }
        else
        {   
            cout << "----------------------------------------------------------\n";
            cout << "❗️-- There are no registered appointments\n";
            cout << "----------------------------------------------------------\n";
        }
    } catch (const exception& e) {
        invalidCommandError();
    }
}

//Function to process the commands
void processCommands(string initialCommand)
{   
    //Initializing a linked list that will store all patients
    Patient *initialiserPatient = new Patient(true, NULL, "Init", "Ïnit", "0000-00-00");
    
    //Initializing a linked list that will store all doctors
    Doctor *initialiserDoctor = new Doctor(true, NULL, "Init", "Init");

    // Initializing a linked list that will store all appointments
    Appointment *initialiserAppointment = new Appointment(NULL ,0, 0, "0000-00-00");

    //Assigning the pointer of the linked list to the tail pointers
    patientTail = initialiserPatient;
    doctorTail = initialiserDoctor;
    appointmentTail = initialiserAppointment;

    //Handling command inputs and redirecting to appropriate function for execution
    string command = initialCommand;
    if(!isNumber(command)){
        invalidCommandError();
        return;    
    }
    while (stoi(command) != 7)
    {   
        try
        {
            switch (stoi(command))
            {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                registerAppointment(initialiserPatient, initialiserDoctor);
                break;
            case 4:
                displayPatients(initialiserPatient);
                break;
            case 5:
                displayDoctors(initialiserDoctor);
                break;
            case 6:
                displayAppointments(initialiserAppointment);
                break;
            default:
                invalidCommandError();
                break;
            }
        }
        catch (invalid_argument const &ex)
        {
            invalidCommandError();
        }
        catch(...)
        {
            invalidCommandError();
        }
        cout << "**>Next Command:";
        cin >> command;
    }
    exitProgram();
}