#include <iostream>
#include <stack>
#include <string>

/* Runtimr: 0 ms, Memory Usage: 6.5 MB */

bool isValid(std::string s)
{
    // ( ( ( { } { } { ( [ ] [ ] ) } ) ) )
    if (s.empty() || s[0] == ')' || s[0] == '}' || s[0] == ']')
        return false;

    std::stack<char> stack;
    for (auto word : s) {
        if (word == '(' || word == '{' || word == '[') {
            stack.push(word);
        } else {
            if (stack.size() == 0)
                return false;
            char top = stack.top();
            if (top == '(') {
                if (word == ')') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (top == '{') {
                if (word == '}') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (top == '[') {
                if (word == ']') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
    }
    if (stack.size() != 0)
        return false;

    return true;
}

int main()
{
    std::cout << isValid("(){}}{") << std::endl;
    return 0;
}