#ifndef PATIENT_LIST_H
#define PATIENT_LIST_H

#include "Patient.h"

using namespace std;

struct PatientNode {
    Patient data;
    PatientNode* next;
};

class PatientLinkedList {
private:
    PatientNode* head;

public:
    PatientLinkedList();
    void add(const Patient& patient);
    PatientNode* search(int id);
    void display() const;

    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif