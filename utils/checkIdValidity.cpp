#include <iostream>

using namespace std;

//Function to check if the patient id is valid
bool isPatientIdValid(Patient *patientInitializer,int patientId){
    cout<<"here";
    Patient *currentPatient = patientInitializer;
    while(currentPatient){
        if(currentPatient->getId() == patientId){
            return true;
        }
        currentPatient = currentPatient->next;
    }
    return false;
}


//Function to check if the doctor id is valid
bool isDoctorIdValid(Doctor *doctorInitializer, int doctorId){
    Doctor *currentDoctor = doctorInitializer;
    while(currentDoctor){
        if(currentDoctor->getId() == doctorId){
            return true;
        }
        currentDoctor = currentDoctor->next;
    }
    return false;
}