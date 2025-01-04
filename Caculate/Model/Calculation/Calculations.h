//
// Created by ChuKhanhhh on 4/1/25.
//

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <string>
#include <vector>

// Hàm trả về độ ưu tiên của toán tử
int precedence(char op);

// Hàm kiểm tra xem ký tự có phải là toán tử không
bool isOperator(char c);

// Hàm chuyển biểu thức infix (tiền tố) sang hậu tố (postfix)
std::string infixToPostfix(const std::string &expression);

// Hàm tính toán giá trị biểu thức hậu tố
std::string evaluatePostfix(const std::string &postfix);

// Hàm cộng hai số lớn dạng chuỗi
std::string addBigIntegers(const std::string& a, const std::string& b);

// Hàm trừ hai số lớn dạng chuỗi
std::string subtractBigIntegers(const std::string& a, const std::string& b);

// Hàm kiểm tra token có phải số BigInit hay không
bool isBigInit(const std::string& token);

// Hàm kiểm tra hàm chuyển đổi hậu tố có số BigInit không ?
bool containsBigInt(const std::string& expression);

#endif //CALCULATIONS_H
