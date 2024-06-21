#include <iostream>
#include <string>

using namespace std;

class Appointment
{
    int appointmentId;
    int patientId;
    int doctorId;
    string appointmentDate;
    int makeId(Appointment *firstAppointment)
    {
        if (firstAppointment)
        {
            return firstAppointment->getAppointmentId() + 1;
        }
        else
        {
            return 1;
        }
    }
    public:
    Appointment *next = NULL;
    Appointment(Appointment *firstAppointment, int docId, int patId, string apptDate)
    {
        appointmentId = makeId(firstAppointment);
        patientId = patId;
        doctorId = docId;
        appointmentDate = apptDate;
    };
    int getAppointmentId()
    {
        return appointmentId;
    }
    int getPatientId()
    {
        return patientId;
    }
    int getDoctorId()
    {
        return doctorId;
    }
    string getAppointmentDate()
    {
        return appointmentDate;
    }
    void display()
    {
        cout << "ID:" << this->getAppointmentId() << endl;
        cout << "PatientID: " << this->getPatientId() << endl;
        cout << "DoctorID: " << this->getDoctorId() << endl;
        cout << "Appointment Date: " << this->getAppointmentDate() << endl;
        cout << "----------------------------------------------------------\n";
    }
};
