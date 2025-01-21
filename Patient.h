#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient {
private:
    int patient_id;
    string name;
    string dob;
    string gender;

public:
    Patient(int id, const string& n, const string& d, const string& g);
    int getId() const;
    void display() const;
    const string& getName() const;
    const string& getDob() const;
    const string& getGender() const;
};

#endif