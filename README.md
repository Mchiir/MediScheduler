# MediScheduler Project

A simple C++ project for scheduling medical appointments, managing patients, and doctors using linked lists.

## Features

- Register and display patients.
- Register and display doctors.
- Register and display appointments between patients and doctors.
- Ensure that appointments are only scheduled when both the patient and doctor exist.

## Project Structure

The project contains the following key components:

- **Patient**: Manages patient information such as `patient_id`, `name`, `dob`, and `gender`.
- **Doctor**: Manages doctor information such as `doctor_id`, `name`, and `specialization`.
- **Appointment**: Manages appointment information including `appointment_id`, `patient_id`, `doctor_id`, and `appointment_date`.
- **Linked Lists**: Separate linked lists for storing patients, doctors, and appointments.

## Requirements

- A C++ compiler supporting C++11 or later (e.g., `g++`).
- A Unix-like terminal (or an environment like WSL or Cygwin on Windows).
- `make` installed (usually pre-installed on Unix-based systems).

## Setup and Compilation

1. Clone the repository:
    ```bash
    git clone https://github.com/Mchiir/MediScheduler.git
    cd MediScheduler
    ```

2. To compile, link, and run the project, run the following `make` command:
    ```bash
    make
    ```

   This will:
   - Compile the source files (`*.cpp`).
   - Link them to create the executable `MediScheduler.exe` (or just `MediScheduler` on Unix-based systems).
   - Automatically run the executable after building.

3. To clean up the build (remove object files and the executable), run:
    ```bash
    make clean
    ```

   This will:
   - Delete the compiled object files (`*.o`).
   - Delete the generated executable (`MediScheduler.exe` or `MediScheduler`).

## Usage

Once compiled and built, the project will automatically run upon executing `make`. If you want to manually run the project after building it, you can use the following command:

```bash
./MediScheduler  # On Unix-like systems
MediScheduler.exe  # On Windows