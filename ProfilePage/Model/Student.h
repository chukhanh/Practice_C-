//
// Created by ChuKhanhhh on 1/1/25.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <utility>
#include <vector>


struct Student {
    std::string studentId;                // Student ID, string with max 10 characters
    std::string fullName;                 // Full name, string with max 30 characters
    std::string faculty;                  // Faculty, string with max 30 characters
    int enrollmentYear;                   // Enrollment year
    std::string dateOfBirth;              // Date of birth in dd/mm/yyyy format
    std::string profilePicture;           // Path to profile picture
    std::string selfDescription;          // Self-description, string with max 1000 characters
    std::vector<std::string> hobbies;     // List of hobbies

    // Constructor (optional) to simplify initialization
    Student(
        std::string  studentId,
        std::string  fullName,
        std::string  faculty,
        int enrollmentYear,
        std::string  dateOfBirth,
        std::string  profilePicture,
        std::string  selfDescription,
        const std::vector<std::string>& hobbies = {}
    )
        : studentId(std::move(studentId)), fullName(std::move(fullName)), faculty(std::move(faculty)), enrollmentYear(enrollmentYear),
          dateOfBirth(std::move(dateOfBirth)), profilePicture(std::move(profilePicture)),
          selfDescription(std::move(selfDescription)), hobbies(hobbies) {}
};


#endif //STUDENT_H
