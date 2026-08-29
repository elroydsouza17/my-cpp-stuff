#include <iostream>

class Stack 
{
    int stack[10];
    int top = -1;

    public:
      int push (int n) {
        if (top < 10) {
          top += 1;
          stack[top] = n;
          return top;
        }

        return -1;
      }

      int getTop()
      {
        if (top == -1) return -1;
        return stack[top];
      }
      
      int pop()
      {
        if(top == -1) return -1;
        top -= 1;
        return top;
      }

      int size()
      {
        return top + 1;
      }

};


int main()
{

    Stack stack;
    std::cout << "Stack size is: " << stack.size() << std::endl;

    stack.push(1);
    std::cout << "Stack size is: " << stack.size() << std::endl;
    std::cout << "top element is: " << stack.getTop() << std::endl;
    stack.push(2);
    stack.push(3);
    std::cout << "Stack size is: " << stack.size() << std::endl;
    std::cout << "top element is: " << stack.getTop() << std::endl;
    stack.pop();
    std::cout << "Stack size is: " << stack.size() << std::endl;
    std::cout << "top element is: " << stack.getTop() << std::endl;
    

    return 0;
}