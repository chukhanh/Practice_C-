#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Hàm trả về độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm kiểm tra xem ký tự có phải là toán tử không
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Hàm chuyển biểu thức infix (tiền tố) sang hậu tố (postfix)
string infixToPostfix(const string &expression) {
    stack<char> ops;
    string postfix = "";
    string number = "";

    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];

        if (isdigit(c)) {  // Nếu là chữ số
            number += c;
        } else if (c == ' ') {  // Nếu là khoảng trắng
            if (!number.empty()) {  // Kết thúc một số và thêm vào hậu tố
                postfix += number + " ";
                number = "";
            }
        } else if (isOperator(c)) {  // Nếu là toán tử
            if (!number.empty()) {  // Đẩy số trước đó vào hậu tố
                postfix += number + " ";
                number = "";
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(c);
        } else if (c == '(') {  // Nếu là dấu ngoặc mở
            ops.push(c);
        } else if (c == ')') {  // Nếu là dấu ngoặc đóng
            if (!number.empty()) {
                postfix += number + " ";
                number = "";
            }
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.pop();  // Loại bỏ dấu ngoặc mở
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

// Hàm tính toán giá trị biểu thức hậu tố
long long evaluatePostfix(const string &postfix) {
    stack<long long> stack;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {  // Là số (cả âm)
            stack.push(stoll(token));
        } else {  // Là toán tử
            long long b = stack.top(); stack.pop();
            long long a = stack.top(); stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") stack.push(a / b);
        }
    }
    return stack.top();  // Kết quả cuối cùng
}

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

// Hàm tính toán biểu thức hậu tố
string evaluatePostfixForBigInit(const string& postfix) {
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

// Hàm kiểm tra token có phải số BigInit hay không
bool isBigInit(const string& token) {
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
    const string BIG_NUMBER_THRESHOLD = "100000"; // Ngưỡng xác định BigInt
    if (token.size() > BIG_NUMBER_THRESHOLD.size() ||
       (token.size() == BIG_NUMBER_THRESHOLD.size() && token > BIG_NUMBER_THRESHOLD)) {
        return true; // Token là BigInt nếu vượt quá ngưỡng
       }

    return false; // Token không phải BigInt
}

bool containsBigInt(const string& expression) {
    stringstream stream(expression); // Tách token trong biểu thức
    string token;

    // Duyệt qua từng token trong biểu thức
    while (stream >> token) {
        if (isBigInit(token)) {
            return true; // Nếu tìm thấy số BigInt, trả về true
        }
    }

    return false; // Nếu không tìm thấy số BigInt, trả về false
}

int main() {
    vector<string> expressions = {
        "(5 - 2) * 3",
        "800 / 4 + 20",
        "24 - 9 - (129 + 90 - 1788877888778788887877)",
        "(((-5 + (89 * 6) - 36) * (55 + 5) + 33) * 4 - 10)"
    };

    for (const auto &expr : expressions) {
        try {
            cout << "Biểu thức hiện tại: " << expr << endl;
            string postfix = infixToPostfix(expr);
            cout << "Hàm chuyển đổi hậu tố là: " << postfix << endl;
            if(containsBigInt(postfix)) {
                string result = evaluatePostfixForBigInit(postfix);
                cout << "Kết quả là: " << result << endl << endl;
            }else {
                long long result = evaluatePostfix(postfix);
                cout << "Kết quả là: " << result << endl << endl;
            }
        } catch (const exception &e) {
           e.what();
        }
    }
    return 0;
}
