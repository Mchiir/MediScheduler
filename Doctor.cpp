#include "Doctor.h"
#include <iostream>

using namespace std;

Doctor::Doctor(int id, const string &n, const string &s)
    : doctor_id(id), name(n), specialization(s) {}

int Doctor::getId() const
{
    return doctor_id;
}

void Doctor::display() const
{
    cout << "Doctor ID: " << doctor_id << ", Name: " << name
         << ", Specialization: " << specialization << endl;
}

const string &Doctor::getName() const
{
    return name;
}

const string &Doctor::getSpecialization() const
{
    return specialization;
}