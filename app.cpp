#include <iostream>
#include "Patient_list.h"
#include "Doctor_list.h"
#include "Appointment_list.h"
#include "validation.h"

using namespace std;

void registerPatient(PatientLinkedList &patientsLL, int patient_id, const string &name, const string &dob, const string &gender)
{
    Patient newPatient(patient_id, name, dob, gender);
    patientsLL.add(newPatient);
    cout << "Patient registered successfully." << endl;
}

void registerDoctor(DoctorLinkedList &doctorsLL, int doctor_id, const string &name, const string &specialization)
{
    Doctor newDoctor(doctor_id, name, specialization);
    doctorsLL.add(newDoctor);
    cout << "Doctor registered successfully." << endl;
}

void registerAppointment(AppointmentLinkedList &appointmentsLL, PatientLinkedList &patientsLL, DoctorLinkedList &doctorsLL,
                         int appointment_id, int patient_id, int doctor_id, const string &appointment_date)
{

    if (!patientsLL.search(patient_id))
    {
        cout << "Patient ID " << patient_id << " does not exist! Please register the patient first." << endl;
        return;
    }

    if (!doctorsLL.search(doctor_id))
    {
        cout << "Doctor ID " << doctor_id << " does not exist! Please register the doctor first." << endl;
        return;
    }

    Appointment newAppointment(appointment_id, patient_id, doctor_id, appointment_date);
    appointmentsLL.add(newAppointment);
    cout << "Appointment registered successfully." << endl;
}

void displayPatients(PatientLinkedList &patientsLL)
{
    if (patientsLL.isEmpty())
    {
        cout << "No patients to display." << endl;
    }
    else
    {
        patientsLL.display();
    }
}

void displayDoctors(DoctorLinkedList &doctorsLL)
{
    if (doctorsLL.isEmpty())
    {
        cout << "No doctors to display." << endl;
    }
    else
    {
        doctorsLL.display();
    }
}

void displayAppointments(AppointmentLinkedList &appointmentsLL)
{
    if (appointmentsLL.isEmpty())
    {
        cout << "No appointments to display." << endl;
    }
    else
    {
        appointmentsLL.display();
    }
}
/*
    int doctor_id;
    string name;
    string specialization;

    int patient_id;
    string name;
    string dob;
    string gender;

    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
*/

int main()
{
    PatientLinkedList patientsLL;
    DoctorLinkedList doctorsLL;
    AppointmentLinkedList appointmentsLL;

    cout << "Welcome to MediScheduler.\n"
         << endl;

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
            cout << "PATIENT REGISTRATION" << endl;
            cout << "----------------------" << endl;
            cout << "Enter Patient ID: ";
            cin >> patient_id;
            patient_id = getId(patient_id, "Patient", patientsLL);
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
            cout << "DOCTOR REGISTRATION" << endl;
            cout << "--------------------" << endl;
            cout << "Enter Doctor ID: ";
            cin >> doctor_id;
            doctor_id = getId(doctor_id, "Doctor", doctorsLL);
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
            cout << "APPOINTMENT REGISTRATION" << endl;
            cout << "------------------------" << endl;
            cout << "Enter Appointment ID: ";
            cin >> appointment_id;
            appointment_id = getId(appointment_id, "Appointment", appointmentsLL);
            cin.ignore();
            
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