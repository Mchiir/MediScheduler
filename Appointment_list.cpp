#include "Appointment_list.h"
#include <iostream>

using namespace std;

AppointmentLinkedList::AppointmentLinkedList() : head(nullptr) {}

void AppointmentLinkedList::add(const Appointment& appointment) {
    AppointmentNode* newNode = new AppointmentNode{appointment, nullptr};
    if (!head) {
        head = newNode;
    } else {
        AppointmentNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

AppointmentNode* AppointmentLinkedList::search(int id) {
    AppointmentNode* temp = head;
    while (temp) {
        if (temp->data.getId() == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void AppointmentLinkedList::display() const {
    AppointmentNode* temp = head;
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}