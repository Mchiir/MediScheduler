#include <iostream>
#include "Patient_list.h"
#include "Doctor_list.h"
#include "Appointment_list.h"

using namespace std;

void registerPatient(PatientLinkedList &patientsLL, int patient_id, const string &name, const string &dob, const string &gender){
    if (patientsLL.search(patient_id)) {
        cout << "Patient ID already exists!" << endl;
    } else {
        Patient newPatient(patient_id, name, dob, gender);
        patientsLL.add(newPatient);
        cout << "Patient registered successfully." << endl;
    }
};

void registerDoctor(DoctorLinkedList &doctorsLL, int doctor_id, const string &name, const string &specialization){
    if (doctorsLL.search(doctor_id)) {
        cout << "Doctor ID already exists!" << endl;
    } else {
        Doctor newDoctor(doctor_id, name, specialization);
        doctorsLL.add(newDoctor);
        cout << "Doctor registered successfully." << endl;
    }
};
void registerAppointment(AppointmentLinkedList &appointmentsLL, PatientLinkedList &patientsLL, DoctorLinkedList &doctorsLL,
                         int appointment_id, int patient_id, int doctor_id, const string &appointment_date)
    {
        if (appointmentsLL.search(appointment_id)) {
            cout << "Appointment ID already exists!" << endl;
            return;
        }
        
        if (!patientsLL.search(patient_id)) {
            cout << "Patient ID does not exist!" << endl;
            return;
        }
        
        if (!doctorsLL.search(doctor_id)) {
            cout << "Doctor ID does not exist!" << endl;
            return;
        }

        Appointment newAppointment(appointment_id, patient_id, doctor_id, appointment_date);
        appointmentsLL.add(newAppointment);
        cout << "Appointment registered successfully." << endl;
    };

void displayPatients(PatientLinkedList &patientsLL){
    if (patientsLL.isEmpty()) {
        cout << "No patients to display." << endl;
    } else {
        patientsLL.display();
    }
};

void displayDoctors(DoctorLinkedList &doctorsLL){
    if (doctorsLL.isEmpty()) {
        cout << "No doctors to display." << endl;
    } else {
        doctorsLL.display();
    }
};

void displayAppointments(AppointmentLinkedList &appointmentsLL){
    if (appointmentsLL.isEmpty()) {
        cout << "No appointments to display." << endl;
    } else {
        appointmentsLL.display();
    }
};

int main()
{
    PatientLinkedList patientsLL;
    DoctorLinkedList doctorsLL;
    AppointmentLinkedList appointmentsLL;

    cout << "Welcome to MediScheduler.\n" << endl;

    int choice;
    do
    {
        cout << "\n1. Register Patient" << endl;
        cout << "2. Register Doctor" << endl;
        cout << "3. Register Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int patient_id;
            string name, dob, gender;
            cout << "Enter Patient ID: ";
            cin >> patient_id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter DOB (YYYY-MM-DD): ";
            getline(cin, dob);
            cout << "Enter Gender: ";
            getline(cin, gender);
            registerPatient(patientsLL, patient_id, name, dob, gender);
            break;
        }
        case 2:
        {
            int doctor_id;
            string name, specialization;
            cout << "Enter Doctor ID: ";
            cin >> doctor_id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Specialization: ";
            getline(cin, specialization);
            registerDoctor(doctorsLL, doctor_id, name, specialization);
            break;
        }
        case 3:
        {
            int appointment_id, patient_id, doctor_id;
            string appointment_date;
            cout << "Enter Appointment ID: ";
            cin >> appointment_id;
            cout << "Enter Patient ID: ";
            cin >> patient_id;
            cout << "Enter Doctor ID: ";
            cin >> doctor_id;
            cin.ignore();
            cout << "Enter Appointment Date (YYYY-MM-DD): ";
            getline(cin, appointment_date);
            registerAppointment(appointmentsLL, patientsLL, doctorsLL, appointment_id, patient_id, doctor_id, appointment_date);
            break;
        }
        case 4:
            displayPatients(patientsLL);
            break;
        case 5:
            displayDoctors(doctorsLL);
            break;
        case 6:
            displayAppointments(appointmentsLL);
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}