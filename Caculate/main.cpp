#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "Constant/Common.h"
#include "Model/Calculation/Calculations.h"
#include "Model/File/File.h"

using namespace std;


int main() {
    vector<string> expressions = loadCalculations(INPUT_PATH);
    vector<string> results;
    for (const auto &expr : expressions) {
        try {
            cout << "Biểu thức hiện tại: " << expr << endl;
            string postfix = infixToPostfix(expr);
            cout << "Hàm chuyển đổi hậu tố là: " << postfix << endl;
            string result = evaluatePostfix(postfix);
            cout << "Kết quả là: " << result << endl << endl;
            results.push_back(result);
        } catch (const exception &e) {
            cout << "Lỗi: " << e.what() << endl;
            results.emplace_back(e.what());
        }
    }
    saveOutPutCalculations(OUTPUT_PATH, results);
    return 0;
}
