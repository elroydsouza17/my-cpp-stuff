#include <iostream>

class LinkedList {
  public:
    LinkedList() {
      head = NULL;
      size = 0;
      temporary_ptr = NULL;
    }

    int insert_tail (int n) {
      list* new_node = new list;
      if (size == 0) {
      head = new_node;
      temporary_ptr = new_node;
      head->value = n;
      head->next = NULL;
      temporary_ptr->next = NULL;
      } else {
        temporary_ptr->next = new_node;
        temporary_ptr = new_node;
        temporary_ptr->value = n;
        temporary_ptr->next = NULL;
      }
      size++;
      return size;
    }

    int insert_head(int n) {
      list* new_node = new list;
      new_node->value = n;
      if (size == 0) {
      new_node->next = NULL;
      head = new_node;
      temporary_ptr = new_node;
      } else {
        new_node->next = head;
        head = new_node;
      }
      size++;
      return size;
    }

    int remove_head() {
      if (size == 0) {
        return -1;
      } else {
        list* temp_ptr = head;
        head = head->next;
        temp_ptr->next = NULL;
        size--;
        if(size == 0) {
          temp_ptr = NULL;
        }

        delete temp_ptr;
        return size;
    }
    }

    int get_head() {
      return head->value;
    }

    int get_tail() {
      return temporary_ptr->value;
    }

  private:
    struct list {
      int value;
      list* next;
    };
    list* temporary_ptr;
    list* head;
    int size;


};

int main() {
  LinkedList linked_list;
  linked_list.insert_tail(1);
  linked_list.insert_tail(2);
  linked_list.insert_tail(5);
  std::cout << linked_list.get_head() << std::endl;
  std::cout << linked_list.get_tail() << std::endl;
  linked_list.insert_tail(6);
  std::cout << linked_list.get_head() << std::endl;
  std::cout << linked_list.get_tail() << std::endl;
  linked_list.insert_head(7);
  std::cout << linked_list.get_head() << std::endl;
  std::cout << linked_list.get_tail() << std::endl;
  linked_list.insert_head(8);
  linked_list.remove_head();
  std::cout << linked_list.get_head() << std::endl;
}