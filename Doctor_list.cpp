#include "Doctor_list.h"
#include <iostream>

using namespace std;

DoctorLinkedList::DoctorLinkedList() : head(nullptr) {}

void DoctorLinkedList::add(const Doctor &doctor)
{
    DoctorNode *newNode = new DoctorNode{doctor, nullptr};
    if (!head)
    {
        head = newNode;
    }
    else
    {
        DoctorNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

DoctorNode *DoctorLinkedList::search(int id)
{
    DoctorNode *temp = head;
    while (temp)
    {
        if (temp->data.getId() == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void DoctorLinkedList::display() const
{
    DoctorNode *temp = head;
    while (temp)
    {
        temp->data.display();
        temp = temp->next;
    }
}