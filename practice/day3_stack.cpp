#include <iostream>

class Stack_impl {

  public: 
    int Stack_impl(int stack_capacity) {
      if (capacity > 100) {
        capacity = 100;
      }
      capacity = stack_capacity;
      size = 0;
      top = -1;
      return capacity;
    }

    int push(int n) {
      if(size == capacity) {
        return -1;
      }
      top =  top + 1;
      size = size + 1;
      arr[top] = n;
      return top;
    }

    int pop() {
      if (size == 0) {
        return -1;
    }

      top = top - 1;
      size = size - 1;
      return arr[top + 1];
    }

    int get_size() {
      return size;
    }

    int get_top() {
      if (top < 0) {
        return top;
      } 
      return arr[top];
    }

  private:
    int arr[100];
    int capacity;
    int size;
    int top;
};

int main() {

  Stack_impl stack(1000);

  std::cout << "pushing elements to stack...." << std::endl;
  stack.push(1);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(2);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(3);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(4);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(5);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(6);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(7);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(8);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(9);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.push(10);
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  std::cout << stack.push(11) << std::endl;
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;  

  std::cout << "popping elements from stack...." << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();
  std::cout << stack.get_size() << std::endl;
  std::cout << stack.get_top() << std::endl;
  stack.pop();

  return 0;
}