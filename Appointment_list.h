#ifndef APPOINTMENT_LIST_H
#define APPOINTMENT_LIST_H

#include "Appointment.h"

using namespace std;

struct AppointmentNode
{
    Appointment data;
    AppointmentNode *next;
};

class AppointmentLinkedList
{
private:
    AppointmentNode *head;

public:
    AppointmentLinkedList();
    void add(const Appointment &appointment);
    AppointmentNode *search(int id);
    void display() const;

    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif