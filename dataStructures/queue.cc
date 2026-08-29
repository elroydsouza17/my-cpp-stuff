#include <iostream>

class Queue {

    int start = -1;
    int end = -1;
    int queue[10];
    int currSize = 0;

    public:
      int push(int n){

        if(currSize == 0){
            start = 0;
            end = 0;
        } else{
          end = (end + 1) % 10;
        }

        currSize++;
        queue[end] = n;
        return end;
      }

      int pop(){       
        if(currSize == 0) return -1;
        if(currSize == 1){
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % 10;
        }
        currSize--;
        return start - 1;
      }

      int top(){
        return queue[start];
      }

      int size()
      {
        return currSize; 
      }
};

int main()
{
    Queue queue;
    std::cout << "size is : " << queue.size() << std::endl;

    queue.push(1);
    std::cout << "size is : " << queue.size() << std::endl;

    queue.push(2);
    std::cout << "size is : " << queue.size() << std::endl;

    queue.push(3);
    std::cout << "size is : " << queue.size() << std::endl;
    std::cout << "top element is: " << queue.top() << std::endl;

    queue.pop();
    std::cout << "size is : " << queue.size() << std::endl;
    std::cout << "top element is: " << queue.top() << std::endl;

    return 0;
}