#ifndef COMMON_H
#define COMMON_H
#include <string>

const std::string STUDENT_FILE_NAME = "student.csv";
const std::string STUDENT_FULL_PATH = R"(../Document/student.csv)";
const std::string DEFAULT_HTML_PATH = R"(../Website/defaultHtml.html)";
const std::string DEFAULT_SAVE_HTML_PATH = R"(../Website/)";
const std::string DEFAULT_SAVE_IMAGE_PATH = R"(./Image/)";
const std::string HTML_FILE = ".html";

// Hàm xoá dấu “ ” trong chuỗi
// Hàm xoá khoảng cách trước vào sau
std::string trimQuotes(const std::string& str);
// Hàm tách tên thành email
std::string convertNameToEmail(const std::string& fullName);
#endif //COMMON_H
