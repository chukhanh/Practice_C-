//
// Created by ChuKhanhhh on 1/1/25.
//

#include "File.h"

#include <sstream>
#include <string>
#include <vector>

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
        student.studentId = trimQuotes(tokens[0]);
        student.fullName = trimQuotes(tokens[1]);
        student.faculty = trimQuotes(tokens[2]);
        student.enrollmentYear = trimQuotes(tokens[3]);
        student.dateOfBirth = trimQuotes(tokens[4]);
        student.profilePicture = trimQuotes(tokens[5]);
        student.selfDescription = trimQuotes(tokens[6]);

        // Process hobbies (if any exist)
        for (size_t i = 7; i < tokens.size(); ++i) {
            // Split the hobby by semicolons
            std::string hobbiesString = trimQuotes(tokens[i]);
            std::istringstream hobbyStream(hobbiesString);
            std::string hobby;
            while (std::getline(hobbyStream, hobby, ';')) {
                student.hobbies.push_back(hobby);
            }
        }
        students.push_back(student);
    }

    file.close();
    return students;
}

std::string replacePlaceholder(const std::string& html, const std::string& placeholder, const std::string& value) {
    std::string result = html;
    size_t pos = result.find(placeholder);
    while (pos != std::string::npos) {
        result.replace(pos, placeholder.length(), value);
        pos = result.find(placeholder, pos + value.length());
    }
    return result;
}

// Hàm kiểm tra file tồn tại
bool fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}


// Hàm tạo hoặc cập nhật HTML từ Student
void generateStudentHTML(const Student& student) {
    // Đọc tệp HTML có sẵn vào một chuỗi
    std::ifstream inputFile(DEFAULT_HTML_PATH);
    if (!inputFile.is_open()) {
        std::cerr << "Không thể mở file template HTML: " << DEFAULT_HTML_PATH << std::endl;
        return;
    }
    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string htmlTemplate = buffer.str();
    inputFile.close();

    // Thay thế các placeholder bằng thông tin của sinh viên
    htmlTemplate = replacePlaceholder(htmlTemplate, "{studentName}", student.fullName);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{studentId}", student.studentId);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{faculty}", student.faculty);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{enrollmentYear}", student.enrollmentYear);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{dateOfBirth}", student.dateOfBirth);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{profilePicture}", DEFAULT_SAVE_IMAGE_PATH + student.profilePicture);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{selfDescription}", student.selfDescription);
    htmlTemplate = replacePlaceholder(htmlTemplate, "{studentEmail}", convertNameToEmail(student.fullName));

    // Xử lý sở thích, in từng sở thích nếu có
    std::string hobbies;
    for (size_t i = 0; i < student.hobbies.size(); ++i) {
        if (i != 0) {
            hobbies += "\n"; // Add a newline to separate <li> elements
        }
        hobbies += "<li>" + student.hobbies[i] + "</li>";
    }
    htmlTemplate = replacePlaceholder(htmlTemplate, "{hobbies}", hobbies);

    // Tạo đường dẫn đầy đủ cho file HTML
    std::string outputFilePath = DEFAULT_SAVE_HTML_PATH + student.studentId + HTML_FILE;

    // Kiểm tra file đã tồn tại chưa
    if (fileExists(outputFilePath)) {
        std::cout << "File " << outputFilePath << " đã tồn tại, sẽ được cập nhật." << std::endl;
    } else {
        std::cout << "File " << outputFilePath << " chưa tồn tại, sẽ được tạo mới." << std::endl;
    }

    // Lưu tệp HTML mới hoặc cập nhật file
    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Không thể ghi file HTML: " << outputFilePath << std::endl;
        return;
    }
    outputFile << htmlTemplate;
    outputFile.close();

    std::cout << "File HTML đã được tạo/cập nhật thành công tại: " << outputFilePath << std::endl;
}