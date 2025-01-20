// Usage: ./GetFileLength  <file to calculate length>
// Read a file as given as the first parameter, count the length of the file and output it
// Here, length of a line is the number of characters in the line (i.e., ignoring special characters like newline)
// Length of the file is the sum of the lengths of all lines
// If no file or bad file is provided, just quit
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./GetFileLength <file to calculate length>\n";
        return 1;
    }

    // Open the file
    std::ifstream file(argv[1]);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file.\n";
        return 1;
    }

    // Initialize variables to keep track of the length of the file
    int fileLength = 0;
    std::string line;

    // Read the file line by line and calculate the length of each line
    while (std::getline(file, line)) {
        fileLength += line.length();
    }

    // Close the file
    file.close();

    // Output the total length of the file
    std::cout << fileLength << std::endl;

    return 0;
}
