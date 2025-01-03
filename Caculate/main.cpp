#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm cộng hai số lớn dạng chuỗi
string addBigIntegers(const string& a, const string& b) {
    string result = "";
    int carry = 0, sum = 0;
    int n1 = a.size(), n2 = b.size();
    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        sum = x + y + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

// Hàm trừ hai số lớn dạng chuỗi
string subtractBigIntegers(const string& a, const string& b) {
    string result = "";
    int borrow = 0, diff = 0;
    int n1 = a.size(), n2 = b.size();
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
        diff = x - y;
        result += diff + '0';
    }

    // Xóa các số 0 ở đầu
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Hàm kiểm tra độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm kiểm tra ký tự có phải là toán tử không
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Hàm chuyển đổi biểu thức từ trung tố sang hậu tố
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    for (size_t i = 0; i < infix.size(); ++i) {
        char c = infix[i];
        if (isspace(c)) continue; // Bỏ qua khoảng trắng
        if (isdigit(c)) {
            // Xử lý số
            while (i < infix.size() && (isdigit(infix[i]) || infix[i] == '-')) {
                postfix += infix[i];
                ++i;
            }
            postfix += ' ';
            --i;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
    return postfix;
}

// Hàm tính toán biểu thức hậu tố
string evaluatePostfix(const string& postfix) {
    stack<string> values;
    istringstream stream(postfix);
    string token;

    while (stream >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Nếu là số, đẩy vào stack
            values.push(token);
        } else if (isOperator(token[0])) {
            // Nếu là toán tử, lấy 2 toán hạng từ stack
            string b = values.top(); values.pop();
            string a = values.top(); values.pop();
            string result;

            switch (token[0]) {
                case '+': result = addBigIntegers(a, b); break;
                case '-': result = subtractBigIntegers(a, b); break;
                default: throw runtime_error("Chưa hỗ trợ toán tử này");
            }
            values.push(result);
        }
    }

    return values.top();
}

int main() {
    vector<string> expressions = {
        "(5 - 2) * 3",
        "800 / 4 + 20",
        "24 - 9 - (129 + 90 - 1788877888778788887877)",
        "(((-5 + (89 * 6) - 36) * (55 + 5) + 33) * 4 - 10)"
    };

    for (const auto& expr : expressions) {
        try {
            cout << "Biểu thức gốc: " << expr << endl;
            string postfix = infixToPostfix(expr);
            cout << "Biểu thức hậu tố: " << postfix << endl;
            string result = evaluatePostfix(postfix);
            cout << "Kết quả: " << result << endl << endl;
        } catch (const exception& e) {
            cout << "Lỗi: " << e.what() << endl;
        }
    }
    // string expr = "24 - 9 - (129 + 90 - 1788877888778788887877)";
    // try {
    //     cout << "Biểu thức gốc: " << expr << endl;
    //     string postfix = infixToPostfix(expr);
    //     cout << "Biểu thức hậu tố: " << postfix << endl;
    //     string result = evaluatePostfix(postfix);
    //     cout << "Kết quả: " << result << endl;
    // } catch (const exception& e) {
    //     cout << "Lỗi: " << e.what() << endl;
    // }

    return 0;
}
