#include <iostream>

#include "Constant/Common.h"
#include "Model/File/File.h"
#include "Model/Student/Student.h"
#include <vector>

int main() {
    // Load students from CSV file
    const std::vector<Student> students = loadStudents(STUDENT_FULL_PATH);

    // Print students for verification
    if(students.empty()) {
        printf("\nKhông tìm thấy thông tin sinh viên trong hệ thống.\n");

    }else {
        int index = 1; // Start the index at 1
        for (const auto& student : students) {
            printf("\nThông tin sinh viên thứ [%d] trong hệ thống là: ", index);
            student.print();
            generateStudentHTML(student);
            ++index; // Increment the index for the next student
        }
    }
    return 0;
}
