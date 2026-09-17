#include <iostream>
#include <stdexcept>

class Deque {
  public:
    Deque(int capacity):
    capacity(capacity),
    start(-1),
    end(0),
    curr_size(0)
    {
      if (capacity > 100 || capacity <= 0)
      throw std::invalid_argument{"invalid capacity"};
    }

    int push_end(int n) {
      if (curr_size == capacity) {
        std::cout << "Can't push anymore elements, capacity exceeded..." << std::endl;
        return -1;
      } else if (curr_size == 0) {
        start += 1;
        array[start] = n;
      } else {
        end = (end + 1) % capacity;
        array[end] = n;
      }
      curr_size += 1;
      return curr_size;
    }

    int push_start(int n) {
      if (curr_size == capacity) {
        std::cout << "Can't push anymore elements, capacity exceeded..." << std::endl;
        return -1;
      } else if (curr_size == 0) {
        start += 1;
        array[start] = n;
      } else {
        move_elements();
        end = (end + 1) % capacity;
        array[start] = n;
      }
      curr_size += 1;
      return curr_size;
    }

    int pop_end() {
      if (curr_size > 0) {
        array[end] = -1;
        end = (end - 1 + capacity) % capacity;
        curr_size -= 1;
        if (curr_size == 0) {
          start = -1;
          end = 0;
        }
        return curr_size;
      }
      std::cout << "error no elements..." << std::endl; 
      return -1;
    }

    int pop_start() {
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
        std::cout << "error no elements..." << std::endl;
        return -1;
    }

    void print_deque() {
        for (int i = 0 ; i < 5; i++) {
          std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    int get_end() {
      return end;
    }

    int get_start() {
      return start;
    }

  private: 
    int array[100];
    int start;
    int end;
    int capacity;
    int curr_size;
    int move_elements() {
      int curr_element = array[start];
      int next_element;
      int i = 0;
      if (curr_size < capacity && curr_size > 0) {
        while(i < curr_size) {
          next_element = array[((start + i) + 1) % capacity];
          array[((start + i) + 1) % capacity] = curr_element;
          curr_element = next_element;
          i++;
        }
      }
      return curr_size;
    }                   

};


int main() {
  Deque dqueue(3);
  dqueue.print_deque();
  dqueue.push_end(1);
  dqueue.print_deque();
  dqueue.push_end(2);
  dqueue.print_deque();
  dqueue.push_end(3);
  dqueue.print_deque();
  dqueue.push_end(4);
  dqueue.print_deque();
  dqueue.pop_end();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;
  dqueue.push_start(4);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;
  dqueue.print_deque();
  dqueue.push_start(5);
  dqueue.print_deque();

  dqueue.pop_end();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.push_start(4);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

    dqueue.push_start(14);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.push_end(10);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

    dqueue.push_end(20);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.push_end(30);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;


  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.push_end(40);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_start();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.push_start(14);
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_end();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;

  dqueue.pop_end();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;


  dqueue.pop_end();
  dqueue.print_deque();
  std::cout << "end: " << dqueue.get_end() << std::endl;
  std::cout << "start: " << dqueue.get_start() << std::endl;
}