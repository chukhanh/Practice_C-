//
// Created by ChuKhanhhh on 1/1/25.
//

#include "File.h"

#include <sstream>

std::vector<std::string> splitCSV(const std::string &line) {
    std::vector<std::string> tokens;
    std::string token;
    bool insideQuotes = false;

    for (const char currentChar : line) {
        // Handle starting and ending quotes
        if (currentChar == '"') {
            insideQuotes = !insideQuotes;
            continue; // Skip the quote character
        }

        // If we are not inside quotes and encounter a comma, treat it as a delimiter
        if (!insideQuotes && currentChar == ',') {
            tokens.push_back(token);  // Push the token we have collected so far
            token.clear();  // Clear token to start a new one
        } else {
            token.push_back(currentChar);  // Otherwise, add the character to the token
        }
    }

    // Push the last token if there is one
    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<Student> loadStudents(const std::string &filePath) {
    std::vector<Student> students;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
        return students;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = splitCSV(line);

        if (tokens.size() < 7) {
            std::cerr << "Error: Invalid data format in line: " << line << "\n";
            continue;
        }

        Student student;
        student.studentId = tokens[0];
        student.fullName = tokens[1];
        student.faculty = tokens[2];
        student.enrollmentYear = tokens[3];
        student.dateOfBirth = tokens[4];
        student.profilePicture = tokens[5];
        student.selfDescription = tokens[6];

        // Process hobbies (if any exist)
        for (size_t i = 7; i < tokens.size(); ++i) {
            // Split the hobby by semicolons
            std::string hobbiesString = tokens[i];
            std::istringstream hobbyStream(hobbiesString);
            std::string hobby;
            while (std::getline(hobbyStream, hobby, ';')) {
                hobby.erase(0, hobby.find_first_not_of(" \t")); // Trim leading spaces
                hobby.erase(hobby.find_last_not_of(" \t") + 1); // Trim trailing spaces
                student.hobbies.push_back(hobby);
            }
        }
        students.push_back(student);
    }

    file.close();
    return students;
}