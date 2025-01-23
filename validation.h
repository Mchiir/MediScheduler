#ifndef VALIDATION_H
#define VALIDATION_H

#include <regex>
#include <string>
#include "Patient_list.h"
#include "Doctor_list.h"
#include "Appointment_list.h"

using namespace std;

bool isValidID(int id) {
    return id > 0;
}

bool isValidString(const string &str) {
    return !str.empty();
}

bool patientExists(PatientLinkedList &patientsLL, int patient_id) {
    return patientsLL.search(patient_id);
}

bool doctorExists(DoctorLinkedList &doctorsLL, int doctor_id) {
    return doctorsLL.search(doctor_id);
}

bool appointmentExists(AppointmentLinkedList &appointmentsLL, int appointment_id) {
    return appointmentsLL.search(appointment_id);
}

bool isValidDate(string date) {
    // Check if format is DD/MM/YYYY
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;
    
    // Extract day, month, year
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    
    // Basic validation
    if (year < 1900 || year > 2024) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Month-specific validation
    if (month == 2) {
        // February
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28)) return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Months with 30 days
        if (day > 30) return false;
    }
    
    return true;
}

#endif // VALIDATION_H