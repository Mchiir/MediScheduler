#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

using namespace std;

class Doctor
{
private:
    int doctor_id;
    string name;
    string specialization;

public:
    Doctor(int id, const string &n, const string &s);
    int getId() const;
    void display() const;
    const string &getName() const;
    const string &getSpecialization() const;
};

#endif