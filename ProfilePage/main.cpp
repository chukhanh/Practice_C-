#include <iostream>

#include "Model/Student.h"

int main() {
    Student student(
         "SV00123",                  // Student ID
         "John Doe",                 // Full name
         "Computer Science",         // Faculty
         2023,                       // Enrollment year
         "01/01/2001",               // Date of birth
         "/path/to/image.jpg",       // Profile picture
         "A passionate student who loves coding.", // Self-description
         {"Listening to music", "Watching movies", "Playing basketball"} // Hobbies
     );

    // Hiển thị thông tin sinh viên
    std::cout << " - Name: " << student.fullName
              << "\n - ID: " << student.studentId
              << "\n - Faculty: " << student.faculty
              << "\n - Enrollment Year: " << student.enrollmentYear
              << "\n - Date of Birth: " << student.dateOfBirth
              << "\nDescription: " << student.selfDescription
              << "\nHobbies: ";

    for (const auto& hobby : student.hobbies) {
        std::cout << hobby << ", ";
    }
    std::cout << std::endl;
    return 0;
}
