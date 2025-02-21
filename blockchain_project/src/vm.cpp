#include "vm.hpp"

void VM::execute(const std::string& script) {
    for (char op : script) {
        if (isdigit(op)) {
            stack.push(op - '0');
        } else if (op == '+') {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(a + b);
        } else if (op == '-') {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b - a);
        }
    }
}

int VM::get_result() const {
    return stack.top();
}