#ifndef VM_H
#define VM_H

#include <vector>
#include <string>
#include <stack>

class VM {
public:
    void execute(const std::string& script);
    int get_result() const;

private:
    std::stack<int> stack;
};

#endif