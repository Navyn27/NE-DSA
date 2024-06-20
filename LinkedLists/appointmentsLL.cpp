#include <iostream>
#include <string>

using namespace std;

class Appointment
{
    int appointmentId;
    int patientId;
    int doctorId;
    string appointmentDate;
    Appointment *next;
    int makeFirstAppt(Appointment *firstAppointment)
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
    Appointment(Appointment *firstAppointment, int docId, std::string apptDate)
    {
        appointmentId = makeFirstAppt(firstAppointment);
        patientId = patId;
        doctorId = docId;
        appointmentDate = apptDate;
        next = NULL;
    };
    int getAppointmentId()
    {
        return apoointmentId;
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
        cout << "PatientID: " << this->getPatiendId() << endl;
        cout << "DoctorID: " << this->getDoctorId() << endl;
        cout << "Appointment Date: " << this->getAppointmentDate() << endl;
    }
}
