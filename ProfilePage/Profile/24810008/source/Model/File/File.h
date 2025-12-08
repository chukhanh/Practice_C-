//
// Created by ChuKhanhhh on 1/1/25.
//

#ifndef FILE_H
#define FILE_H

#include "../Student/Student.h"
#include <string>
#include <vector>
std::vector<Student> loadStudents(const std::string &filePath);
std::vector<std::string> splitCSV(const std::string &line);
std::string replacePlaceholder(const std::string& html, const std::string& placeholder, const std::string& value);
bool fileExists(const std::string& path);
void generateStudentHTML(const Student& student);
#endif //FILE_H
