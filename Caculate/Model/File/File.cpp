//
// Created by ChuKhanhhh on 1/1/25.
//

#include "File.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> loadCalculations(const std::string &filePath) {
    std::vector<std::string> calculations; // Vector để lưu các phép tính
    std::ifstream inputFile(filePath);    // Mở file

    // Kiểm tra nếu không thể mở file
    if (!inputFile.is_open()) {
        std::cerr << "Không thể mở file: " << filePath << std::endl;
        return calculations; // Trả về vector rỗng
    }

    std::string line;
    // Đọc từng dòng từ file và lưu vào vector
    while (std::getline(inputFile, line)) {
        // Loại bỏ các khoảng trắng thừa ở đầu và cuối mỗi dòng
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if (!line.empty()) {  // Nếu dòng không rỗng
            calculations.push_back(line);  // Lưu vào vector
        }
    }

    inputFile.close(); // Đóng file
    return calculations; // Trả về danh sách các phép tính
}

void saveOutPutCalculations(const std::string &filePath, const std::vector<std::string>& results) {
    std::ofstream outputFile(filePath); // Mở file để ghi

    // Kiểm tra nếu không thể mở file
    if (!outputFile.is_open()) {
        std::cerr << "Không thể mở file để ghi: " << filePath << std::endl;
        return;
    }

    // Ghi từng dòng từ vector results vào file
    for (const auto &result : results) {
        outputFile << result << std::endl;
    }

    outputFile.close(); // Đóng file sau khi hoàn thành
}