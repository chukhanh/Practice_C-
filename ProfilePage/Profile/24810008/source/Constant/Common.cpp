//
// Created by ChuKhanhhh on 1/1/25.
//
#include "Common.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Hàm loại bỏ dấu " " quanh chuỗi
std::string trimQuotes(const std::string& input) {
    std::string result = input;

    // Xóa khoảng trắng ở đầu và cuối chuỗi
    size_t start = result.find_first_not_of(" \t\n\r");
    size_t end = result.find_last_not_of(" \t\n\r");
    if (start != std::string::npos && end != std::string::npos) {
        result = result.substr(start, end - start + 1);
    } else {
        result = ""; // Nếu chỉ toàn khoảng trắng, trả về chuỗi rỗng
        return result;
    }

    // Kiểm tra và xóa dấu ngoặc kép thẳng "..."
    if (result.size() >= 2 && result.front() == '"' && result.back() == '"') {
        result = result.substr(1, result.size() - 2);
    }

    // Kiểm tra và xóa dấu ngoặc kép cong “...”
    if (result.size() >= 6 && result.substr(0, 3) == "“" && result.substr(result.size() - 3) == "”") {
        result = result.substr(3, result.size() - 6);
    }

    if (result.size() >= 6 && result.substr(0, 3) == "”" && result.substr(result.size() - 3) == "”") {
        result = result.substr(3, result.size() - 6);
    }

    // Xóa khoảng trắng lần cuối nếu còn sót
    start = result.find_first_not_of(" \t\n\r");
    end = result.find_last_not_of(" \t\n\r");
    if (start != std::string::npos && end != std::string::npos) {
        result = result.substr(start, end - start + 1);
    } else {
        result = ""; // Nếu chỉ toàn khoảng trắng, trả về chuỗi rỗng
    }

    return result;
}

std::string convertNameToEmail(const std::string& fullName) {
    std::string trimmedName = trimQuotes(fullName); // Loại bỏ khoảng trắng thừa
    std::istringstream iss(trimmedName);                // Tách từ dựa trên khoảng trắng
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() < 2) return ""; // Nếu không đủ họ và tên, trả về rỗng

    // Lấy ký tự đầu từ họ, tên đệm (nếu có), và tên chính
    std::string email;
    email += std::tolower(words[0][0]);               // Ký tự đầu tiên của họ
    if (words.size() > 2) {
        email += std::tolower(words[1][0]);           // Ký tự đầu tiên của tên đệm
    }
    email += std::tolower(words.back()[0]);           // Tên chính (toàn bộ)
    email += "@gmail.com";

    return email;
}