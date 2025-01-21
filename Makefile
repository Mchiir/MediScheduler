# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = app.cpp Patient.cpp Patient_list.cpp Doctor.cpp Doctor_list.cpp Appointment.cpp Appointment_list.cpp

# Output executable
TARGET = MediScheduler.exe  # Change to .exe for Windows

# Build rule
all: $(TARGET) run

# Link the object files to create the executable
$(TARGET): $(SRCS:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the application
run:
	./$(TARGET)

# Clean rule to remove object files and the executable
clean:
	del $(TARGET) *.o
