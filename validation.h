#ifndef VALIDATION_H
#define VALIDATION_H

#include <regex>
#include <string>
#include "Patient_list.h"
#include "Doctor_list.h"
#include "Appointment_list.h"

using namespace std;

// Function to clear input stream in case of incorrect data entry
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Template function to get a valid ID
template <typename T, typename LinkedList>
T getId(T passed_id, const std::string &object, LinkedList &list) {
    // Checking if 'passed_id' is a valid integer
    while (true) {
        if (!std::is_integral<T>::value) {
            clearInput();
            std::cout << "Invalid " << object << " ID type. Please enter a positive integer." << std::endl;
        } else if (std::cin.fail() || passed_id <= 0) {
            clearInput();
            std::cout << "Invalid ID. Please enter a positive integer." << std::endl;
        } else if (list.search(passed_id)) {
            std::cout << object << " ID " << passed_id << " already exists! Please enter a different ID." << std::endl;
        } else {
            break;
        }

        std::cout << "Enter " << object << " ID: ";
        std::cin >> passed_id;
    }

    return passed_id;
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
    // Check if format is YYYY-MM-DD
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    // Extract day, month, year
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    // Basic validation
    if (year < 1900 || year > 2025) return false;
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