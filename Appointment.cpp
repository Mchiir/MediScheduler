#include "Appointment.h"
#include <iostream>

using namespace std;

Appointment::Appointment(int id, int p_id, int d_id, const string &date)
    : appointment_id(id), patient_id(p_id), doctor_id(d_id), appointment_date(date) {}

int Appointment::getId() const
{
    return appointment_id;
}

void Appointment::display() const
{
    cout << "Appointment ID: " << appointment_id << ", Patient ID: " << patient_id
         << ", Doctor ID: " << doctor_id << ", Date: " << appointment_date << endl;
}

int Appointment::getPatientId() const
{
    return patient_id;
}

int Appointment::getDoctorId() const
{
    return doctor_id;
}

const string &Appointment::getAppointmentDate() const
{
    return appointment_date;
}