
# Define the compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Define the executable file 
TARGET = program

# Define the source files
SOURCES = ECAirlineFinancial.cpp ECAirlineOperation.cpp ECAirlineSimulator.cpp ECAirlineTicketing.cpp ECAirport.cpp ECAirSimTest-part1.cpp ECFlight.cpp ECFlightItinerary.cpp

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files into a binary
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJECTS) $(TARGET)
	clear

# Phony targets
.PHONY: all clean
