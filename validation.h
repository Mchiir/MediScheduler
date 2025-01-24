#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath> // to work with log10
#include <limits>
#include <regex>
#include <ctime> // to access current time data
#include "Patient_list.h"
#include "Doctor_list.h"
#include "Appointment_list.h"

using namespace std;

// Function to clear input stream in case of incorrect data entry
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get the current year
int getCurrentYear() {
    std::time_t t = std::time(0);   // Get current time
    std::tm* now = std::localtime(&t); // Convert to local time
    return now->tm_year + 1900; // Extract the year
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
        } else if (static_cast<int>(log10(passed_id) + 1) > 10) {
            std::cout << "The ID length should not exceed 10 digits. Please enter a valid ID." << std::endl;
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

// reusable validation function for strings
template <typename T>
T getStringParam(T passed_str, const std::string &object, const std::string &property) {
    while (true) {
        // Check if passed_str is a non-empty string with at least three alphabetic characters
        if (!passed_str.empty() && std::all_of(passed_str.begin(), passed_str.end(), ::isalpha) && passed_str.size() >= 3) {
            // Check if the string length is less than or equal to 50 characters
            if (passed_str.size() <= 50) {
                // If all validations pass, return the valid string
                return passed_str;
            } else {
                // Prompt the user to provide a shorter string if input is too long
                std::cout << "The input " << object << " " << property << " is too long. Please provide a shorter string." << std::endl;
            }
        } else {
            // Prompt the user to provide a valid string with at least three alphabetic characters
            std::cout << "The input " << object << " " << property << " is not a valid " << property << " with at least three alphabetic characters." << std::endl;
        }

        // Request new input from the user
        std::cout << "Enter " << object << " " << property << " : ";
        std::getline(std::cin, passed_str);
    }
    // Return a default value if the input does not pass validation (though this point will not be reached)
    return "";
}


// Function to validate gender
std::string getGenderParam(std::string passed_gender, const std::string &object) {
    while (true) {
        // Clear the input buffer
        clearInput();

        // Convert the input to lowercase for case-insensitive comparison
        std::transform(passed_gender.begin(), passed_gender.end(), passed_gender.begin(), ::tolower);

        // Check if the entered gender is valid
        if ((passed_gender == "male" || passed_gender == "female" || passed_gender == "1" || passed_gender == "2") && passed_gender.length() <= 6) {
            if (passed_gender == "1") {
                passed_gender = "Male";
            } else if (passed_gender == "2") {
                passed_gender = "Female";
            } else {
                // Convert the input back to capitalized format (first letter uppercase)
                passed_gender[0] = toupper(passed_gender[0]);
            }
            return passed_gender;
        } else {
            std::cout << "The input " << object << " Gender is not valid. Please enter Male (1) or Female (2)." << std::endl;
        }

        // Prompt the user to enter the gender
        std::cout << "Enter " << object << " Gender (Male/Female or 1/2): ";
        std::getline(std::cin, passed_gender);
    }

    // Return a default value if the input does not pass validation (though this point will not be reached)
    return "";
}


// Function to validate date (YYYY-MM-DD)
std::string getDateParam(std::string passed_date, const std::string &object) {
    std::regex date_pattern(R"(\d{4}-\d{2}-\d{2})"); // Regular expression for YYYY-MM-DD format
    int current_year = getCurrentYear();

    while (true) {
        // Check if the entered date matches the YYYY-MM-DD format
        if (std::regex_match(passed_date, date_pattern)) {
            // Extract year, month, and day from the passed_date
            int year, month, day;
            sscanf(passed_date.c_str(), "%4d-%2d-%2d", &year, &month, &day);

            // Basic validation
            if (year < 1900 || year > current_year) {
                std::cout << "The year must be between 1900 and " << current_year << ". Please enter a valid date." << std::endl;
            } else if (month < 1 || month > 12) {
                std::cout << "The month must be between 1 and 12. Please enter a valid date." << std::endl;
            } else if (day < 1 || day > 31) {
                std::cout << "The day must be between 1 and 31. Please enter a valid date." << std::endl;
            } else {
                // Month-specific validation
                if (month == 2) {
                    // February
                    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                    if (day > (isLeapYear ? 29 : 28)) {
                        std::cout << "February " << (isLeapYear ? "29" : "28") << " days only in a leap year. Please enter a valid date." << std::endl;
                    } else {
                        return passed_date;
                    }
                } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                    // Months with 30 days
                    if (day > 30) {
                        std::cout << "The month " << month << " has 30 days only. Please enter a valid date." << std::endl;
                    } else {
                        return passed_date;
                    }
                } else {
                    return passed_date;
                }
            }
        } else {
            std::cout << "The input " << object << " Date is not a valid date. Please enter a valid date in YYYY-MM-DD format." << std::endl;
        }

        // Prompt the user to enter the date
        std::cout << "Enter " << object << " Date (YYYY-MM-DD): ";
        std::getline(std::cin, passed_date);
    }

    // Return a default value if the input does not pass validation (though this point will not be reached)
    return "";
}


// Function to validate and check for user existence
template <typename LinkedList>
bool checkUserExistence(int user_id, const std::string &object, LinkedList &list) {
    if (list.search(user_id)) {
        std::cout << object << " ID " << user_id << " exists." << std::endl;
        return true;
    }
    std::cout << object << " ID " << user_id << " does not exist. The user must be created first." << std::endl;
    return false;
}


// function to check for user existance in a linkedlist
template <typename LinkedList>
bool isUserExisting(std::string passed_gender, const std::string &object, LinkedList list){
    
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