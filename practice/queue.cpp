#include <iostream>

class QueueImpln {
  public:
    QueueImpln(int queue_capacity) {
      capacity = queue_capacity;
      start = -1;
      end = -1;
      curr_size = 0;      
    }

    int push(int n) {
      if (curr_size == 0) {
        start += 1;
      }
      
      if (curr_size == capacity) {
        start = (start + 1) % capacity;
      }
      
      if (curr_size < capacity) {
        curr_size = curr_size + 1;
      }


      end = (end + 1) % capacity;
      arr[end] = n;

      return curr_size;
    }

    int pop() {
      start = (start + 1) % capacity;
      curr_size = curr_size - 1;
      if (curr_size == 0) {
        start = -1;
        end = -1;
        return -1;
      }
  
      return curr_size;
    }

    int get_size() {
      return curr_size;
    }

    int get_start() {
      return start;
    }

    int get_end() {
      return end;
    }

    int get_top() {
      if (curr_size > 0) {
      return arr[start];
      }
      return -1;
    }

  private:
    int capacity;
    int curr_size;
    int start;
    int end;
    int arr[100];
    
};

int main() {
  QueueImpln queue(3);
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  queue.push(1);
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
   queue.push(2);
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  queue.push(3);
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  queue.push(4);
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  std::cout << "start is: " <<  queue.get_start() << std::endl;
  std::cout << "end is : " << queue.get_end() << std::endl;
  queue.pop();
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  std::cout << "start is: " <<  queue.get_start() << std::endl;
  std::cout << "end is : " << queue.get_end() << std::endl;
  queue.pop();
  std::cout << "size is: " <<  queue.get_size() << std::endl;
  std::cout << "top is : " << queue.get_top() << std::endl;
  std::cout << "start is: " <<  queue.get_start() << std::endl;
  std::cout << "end is : " << queue.get_end() << std::endl;
  return 0;
  
}