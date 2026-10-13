#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> operands;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                operands.push(std::stoi(tokens[i]));
            } else {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();

                if (tokens[i] == "+") {
                    operands.push(b + a);
                } else if (tokens[i] == "-") {
                    operands.push(b - a);
                } else if (tokens[i] == "*") {
                    operands.push(b * a);
                } else {
                    operands.push(b / a);
                }
            }
        }

        // std::cout << "ELEMENT: " << operands.top() << std::endl;
        return operands.top();
    }
};

int main() {

  std::vector<std::string> s = {"1","2","+","3","*","4","-"};
  Solution solution;
  solution.evalRPN(s);

}