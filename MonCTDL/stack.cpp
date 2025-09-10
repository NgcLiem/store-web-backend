#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> myStack;

    // Thêm dữ liệu vào stack
    myStack.push("First");
    myStack.push("Second");
    myStack.push("Third");

    // Duyệt từ đỉnh đến đáy stack và hiển thị các phần tử
    while (!myStack.empty()) {
        std::cout << myStack.top() << std::endl;
        myStack.pop(); // Loại bỏ phần tử ở đỉnh stack
    }

    return 0;
}
