//
// Created by ChuKhanhhh on 4/1/25.
//

#include "Calculations.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

#include "../../Constant/Common.h"

// Hàm trả về độ ưu tiên của toán tử
int precedence(const char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case ':':
            return 2;
        default:
            return -1; // Return -1 for unsupported operators
    }
}

// Hàm kiểm tra xem ký tự có phải là toán tử không
bool isOperator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == ':';
}

// Hàm chuyển biểu thức infix (tiền tố) sang hậu tố (postfix)
std::string infixToPostfix(const std::string &expression) {
    std::stack<char> ops;
    std::string postfix;
    std::string number;

    for (char c: expression) {
        if (isdigit(c)) {
            // Nếu là chữ số
            number += c;
        } else if (c == ' ') {
            // Nếu là khoảng trắng
            if (!number.empty()) {
                // Kết thúc một số và thêm vào hậu tố
                postfix += number + " ";
                number = "";
            }
        } else if (isOperator(c)) {
            // Nếu là toán tử
            if (!number.empty()) {
                // Đẩy số trước đó vào hậu tố
                postfix += number + " ";
                number = "";
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(c);
        } else if (c == '(') {
            // Nếu là dấu ngoặc mở
            ops.push(c);
        } else if (c == ')') {
            // Nếu là dấu ngoặc đóng
            if (!number.empty()) {
                postfix += number + " ";
                number = "";
            }
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.pop(); // Loại bỏ dấu ngoặc mở
        }
    }

    // Xử lý số cuối cùng nếu còn sót lại
    if (!number.empty()) {
        postfix += number + " ";
    }

    // Lấy tất cả toán tử còn lại trong stack và thêm vào hậu tố
    while (!ops.empty()) {
        postfix += ops.top();
        postfix += " ";
        ops.pop();
    }

    return postfix;
}

// Hàm cộng hai số lớn dạng chuỗi
std::string addBigIntegers(const std::string &a, const std::string &b) {
    std::string result;
    int carry = 0, sum = 0;
    const int n1 = a.size(), n2 = b.size();
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0 || carry) {
        const int x = (i >= 0) ? a[i--] - '0' : 0;
        const int y = (j >= 0) ? b[j--] - '0' : 0;
        sum = x + y + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

// Hàm trừ hai số lớn dạng chuỗi
std::string subtractBigIntegers(const std::string &a, const std::string &b) {
    std::string result;
    int borrow = 0, diff = 0;
    const int n1 = a.size(), n2 = b.size();
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        y += borrow;
        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += x - y + '0';
    }

    // Xóa các số 0 ở đầu
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Hàm kiểm tra token có phải số BigInit hay không
bool isBigInit(const std::string &token) {
    if (token.empty()) return false; // Chuỗi rỗng không phải số
    size_t start = 0;

    // Kiểm tra dấu âm ở đầu
    if (token[0] == '-') {
        if (token.size() == 1) return false; // Dấu trừ một mình không hợp lệ
        start = 1;
    }

    // Kiểm tra các ký tự còn lại có phải chữ số không
    for (size_t i = start; i < token.size(); i++) {
        if (!isdigit(token[i])) {
            return false; // Gặp ký tự không phải số
        }
    }

    // Kiểm tra nếu số quá lớn (BigInt)
    if (token.size() > BIG_NUMBER_THRESHOLD.size() ||
        (token.size() == BIG_NUMBER_THRESHOLD.size() && token > BIG_NUMBER_THRESHOLD)) {
        return true; // Token là BigInt nếu vượt quá ngưỡng
    }

    return false; // Token không phải BigInt
}

bool containsBigInt(const std::string &expression) {
    std::stringstream stream(expression); // Tách token trong biểu thức
    std::string token;

    // Duyệt qua từng token trong biểu thức
    while (stream >> token) {
        if (isBigInit(token)) {
            return true; // Nếu tìm thấy số BigInt, trả về true
        }
    }

    return false; // Nếu không tìm thấy số BigInt, trả về false
}

std::string evaluatePostfix(const std::string &postfix) {
    std::stringstream ss(postfix);
    std::string token;
    std::string result;

    if (containsBigInt(postfix)) {
        std::stack<std::string> stack;
        while (ss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                // Là số (cả âm)
                stack.push(token); // Push token as string
            } else {
                // Là toán tử
                std::string b = stack.top();
                stack.pop();
                std::string a = stack.top();
                stack.pop();

                // Handling BigInt operations
                switch (token[0]) {
                    case '+': stack.push(addBigIntegers(a, b));
                        break;
                    case '-': stack.push(subtractBigIntegers(a, b));
                        break;
                    // Add other operators as needed
                    default: throw std::runtime_error("Chưa hỗ trợ toán tử này");
                }
            }
        }
        result = stack.top();
    } else {
        std::stack<long long> stack;
        while (ss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                // Là số (cả âm)
                stack.push(stoll(token)); // Push token as string
            } else {

                // Regular integer operations
                long long numB = stack.top(); stack.pop();
                long long numA = stack.top(); stack.pop();
                switch (token[0]) {
                    case '+':
                        stack.push(numA + numB);
                    break;
                    case '-':
                        stack.push(numA - numB);
                    break;
                    case '*':
                        stack.push(numA * numB);
                    break;
                    case '/':
                    case ':':
                        if (numB == 0) throw std::runtime_error("Lỗi chia cho 0");
                    stack.push(numA / numB);
                    break;
                    default:
                        throw std::runtime_error("Toán tử không hợp lệ");
                }
            }
        }
        result = std::to_string(stack.top());
    }
    return result; // Kết quả cuối cùng dưới dạng string
}
