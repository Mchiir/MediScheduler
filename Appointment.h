#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

using namespace std;

class Appointment
{
private:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;

public:
    Appointment(int id, int p_id, int d_id, const string &date);
    int getId() const;
    void display() const;
    int getPatientId() const;
    int getDoctorId() const;
    const string &getAppointmentDate() const;
};

#endif