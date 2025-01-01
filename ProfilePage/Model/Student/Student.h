//
// Created by ChuKhanhhh on 1/1/25.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>

#include "../../Constant/Common.h"


struct Student {
    std::string studentId;                // Student ID, string with max 10 characters
    std::string fullName;                 // Full name, string with max 30 characters
    std::string faculty;                  // Faculty, string with max 30 characters
    std::string enrollmentYear;                   // Enrollment year
    std::string dateOfBirth;              // Date of birth in dd/mm/yyyy format
    std::string profilePicture;           // Path to profile picture
    std::string selfDescription;          // Self-description, string with max 1000 characters
    std::vector<std::string> hobbies;     // List of hobbies

    // Default constructor
    Student() : enrollmentYear("0") {}
    // Constructor (optional) to simplify initialization
    Student(
        std::string  studentId,
        std::string  fullName,
        std::string  faculty,
        std::string enrollmentYear,
        std::string  dateOfBirth,
        std::string  profilePicture,
        std::string  selfDescription,
        const std::vector<std::string>& hobbies = {}
    )
        : studentId(std::move(studentId)), fullName(std::move(fullName)), faculty(std::move(faculty)), enrollmentYear(std::move(enrollmentYear)),
          dateOfBirth(std::move(dateOfBirth)), profilePicture(std::move(profilePicture)),
          selfDescription(std::move(selfDescription)), hobbies(hobbies) {}

    void print() const {
        std::cout << "\n- MSSV: " << studentId
                  << "\n- Họ và tên: " << fullName
                  << "\n- Khoa: " << faculty
                  << "\n- Khóa: " << enrollmentYear
                  << "\n- Ngày sinh: " << dateOfBirth
                  << "\n- Hình ảnh cá nhân: " << profilePicture
                  << "\n- Mô tả bản thân: " << selfDescription
                  << "\n- Sở thích: ";
        for (const auto& hobby : hobbies) {
            std::cout << "\n  + "<< hobby << "; ";
        }
        std::cout << "\n";
    }
};

#endif //STUDENT_H
