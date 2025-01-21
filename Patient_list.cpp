#include "Patient_list.h"
#include <iostream>

using namespace std;

PatientLinkedList::PatientLinkedList() : head(nullptr) {}

void PatientLinkedList::add(const Patient& patient) {
    PatientNode* newNode = new PatientNode{patient, nullptr};
    if (!head) {
        head = newNode;
    } else {
        PatientNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

PatientNode* PatientLinkedList::search(int id) {
    PatientNode* temp = head;
    while (temp) {
        if (temp->data.getId() == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void PatientLinkedList::display() const {
    PatientNode* temp = head;
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}