//
// Created by ChuKhanhhh on 1/1/25.
//

#ifndef FILE_H
#define FILE_H
#include "../Student/Student.h"

std::vector<Student> loadStudents(const std::string &filePath);
std::vector<std::string> splitCSV(const std::string &line);


#endif //FILE_H
