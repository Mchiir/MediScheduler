#ifndef DOCTOR_LIST_H
#define DOCTOR_LIST_H

#include "Doctor.h"

using namespace std;

struct DoctorNode
{
    Doctor data;
    DoctorNode *next;
};

class DoctorLinkedList
{
private:
    DoctorNode *head;

public:
    DoctorLinkedList();
    void add(const Doctor &doctor);
    DoctorNode *search(int id);
    void display() const;

    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif