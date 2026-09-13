#include <iostream>

class CircularQueue {
  public:
    CircularQueue(int capacity):
      curr_size(0),
      start(-1),
      end(0),
      capacity(capacity)
      {};

      int push(int n) {
        if (curr_size >= capacity) {
          return -1;
        } else if(curr_size == 0) {
          start += 1;
          curr_size += 1;
          array[start] = n; 
        } else {
          end = (end + 1) % capacity;
          curr_size += 1;
          array[end] = n;
        }

        return curr_size;
      }

      int get_size() {
        return curr_size;
      }

      int get_top() {
        if (curr_size > 0) {
          return array[start];
        }
        return -1;
      }

      int pop() {
        if (curr_size > 0) {
          array[start] = -1;
          start = (start + 1) % capacity;
          curr_size -= 1;
          if (curr_size == 0) {
            start = -1;
            end = 0;
          }
          return curr_size;
        }

        return -1;
      }

      void print_queue() {
        for (int i = 0; i < capacity; i++) {
          std::cout << array[i] << " " ;
        }
        std::cout << std::endl;
      }

  private:
    int array[100];
    int curr_size;
    int start;
    int end;
    int capacity;
};

class Stack {
  public:
    Stack(int capacity):
      capacity(capacity),
      curr_size(0),
      end(-1)
      {}
    
    int push(int n) {
      if (curr_size < capacity) {
        end += 1;
        array[end] = n;
        curr_size += 1;
        return curr_size;
      }
      return -1;
    }

    int pop() {
      if (curr_size > 0) {
        array[end] = -1;
        end -= 1;
        curr_size -= 1;
        return curr_size;
      }

      return -1;
    }

    void print_stack() {
      for (int i = 0; i < capacity; i++) {
        std::cout << array[i] << " " ;
      }
      std::cout << std::endl;
    }

  private:
    int array[100];
    int capacity;
    int curr_size;
    int end;
};

int main() {

  //Queue
  CircularQueue queue(2);
  queue.push(2);

  queue.push(300);
  queue.print_queue();

  queue.push(400);
  std::cout << "size is : " << queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;

  queue.pop();
  queue.print_queue();

  queue.push(500);
  queue.print_queue();
    std::cout << "size is : " << queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;

  queue.pop();
  queue.pop();
  queue.print_queue();
  std::cout << "size is : " << queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;

  queue.push(2000);
  queue.print_queue();

  std::cout << "STACK IMPL ==============" << std::endl;
  Stack stack(2);
  stack.push(2);
  stack.push(5);
  stack.print_stack();
  stack.pop();
  stack.print_stack();
}


