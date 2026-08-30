#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

int main()
{

    std::string s = "{([]())}";
    std::unordered_map<char,char> brackets;
    std::stack<char> stack;
    
    // Create a hashmap for closing brackets to match with opening
    brackets[')'] = '(';
    brackets['}'] = '{';
    brackets[']'] = '[';

    // If it's an opening bracket you push to stack , if its a closing bracket you check hashmap and pop corresponding opening from the stack.
    for (int i = 0;  i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
            // stack.size() > 0 , to handle if close brackets come first in the input
        } else if (stack.size() > 0 && brackets[s[i]] == stack.top()) {
            stack.pop();
        } else {
            std::cout << "Incorrect order " << std::endl;
            return 1;
        }
    }
    
    if(stack.size() == 0){
    std::cout << "Brackets are in correct order!!!!" << std::endl;
    } else {
        std::cout << "Incorrect order " << std::endl;
    }
    return 0;
}