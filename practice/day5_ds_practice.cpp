#include <iostream>

class Queue {
  public:
    Queue(int capacity):
    capacity(capacity),
    start(-1),
    end(0),
    curr_size(0)
    {}

    int push(int n) {
      if (curr_size == 0) {
        start = (start + 1) % capacity;
        array[start] = n;
        curr_size = curr_size + 1;
      } else if (curr_size < capacity) {
        end = (end + 1) % capacity;
        array[end] = n;
        curr_size = curr_size + 1;
      } else {
        end = (end + 1) % capacity;
        start = (start + 1) % capacity;
        array[end] = n;
      }

      return curr_size;
    }

    int pop () {
      if (curr_size > 0) {
        start = (start + 1) % capacity;
        curr_size -= 1;
      } else {
        return -1;
      }

      return curr_size;
    }

    int get_top() {
      if (curr_size > 0) {
      return array[start];
      }
      return -1;
    }

    int get_end() {
      if (curr_size > 0) {
      return array[end];
      }
      return -1;
    }

    int get_size() {
      return curr_size;
    }
  
    


  private: 
    int array[100];
    int capacity;
    int start;
    int end;
    int curr_size;
};

class Conventional_Queue {
  public:
    Conventional_Queue(int capacity):
    capacity(capacity),
    start(-1),
    end(0),
    curr_size(0)
    {}

    int push(int n) {
      if (curr_size == 0) {
        start = (start + 1) % capacity;
        array[start] = n;
        curr_size = curr_size + 1;
      } else if (curr_size < capacity) {
        end = (end + 1) % capacity;
        array[end] = n;
        curr_size = curr_size + 1;
      } else {
        std::cout << "Queue is full remove an element before inserting!!" << std::endl;
      }

      return curr_size;
    }

    int pop () {
      if (curr_size > 0) {
        start = (start + 1) % capacity;
        curr_size -= 1;
      } else {
        return -1;
      }

      return curr_size;
    }

    int get_top() {
      if (curr_size > 0) {
      return array[start];
      }
      return -1;
    }

    int get_end() {
      if (curr_size > 0) {
      return array[end];
      }
      return -1;
    }

    int get_size() {
      return curr_size;
    }
  
    


  private: 
    int array[100];
    int capacity;
    int start;
    int end;
    int curr_size;
};

int main() {

  Conventional_Queue queue(3);
  queue.push(3);
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;

  queue.push(5);
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;

  queue.push(10);
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;

  queue.push(8);
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;
  
  queue.pop();
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;

  queue.pop();
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;

  queue.push(80);
  std::cout << "TOP " << queue.get_top() << std::endl;
  std::cout << "size" << queue.get_size() <<std::endl;
  std::cout << "end" << queue.get_end() << std::endl;


  return 0;
}