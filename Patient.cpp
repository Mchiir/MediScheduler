#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient(int id, const string& n, const string& d, const string& g)
    : patient_id(id), name(n), dob(d), gender(g) {}

int Patient::getId() const {
    return patient_id;
}

void Patient::display() const {
    cout << "Patient ID: " << patient_id << ", Name: " << name 
              << ", DOB: " << dob << ", Gender: " << gender << endl;
}

const string& Patient::getName() const {
    return name;
}

const string& Patient::getDob() const {
    return dob;
}

const string& Patient::getGender() const {
    return gender;
}