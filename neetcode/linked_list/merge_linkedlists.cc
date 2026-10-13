#include <iostream>

struct ListNode {
  int value;
  ListNode* next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = list1;
        ListNode* curr_node = list1;
        ListNode* curr_node_next = curr_node->next;
        ListNode* next_node = list2;

        while(next_node != NULL) {
          curr_node->next = next_node;
          curr_node = next_node;
        if (curr_node_next == NULL) {
            break;
          }
          next_node = curr_node_next;
          curr_node_next = curr_node->next;
        }



        return head;

    }
};

int main() {

  struct ListNode l1, l2, l3;
  struct ListNode a1, a2, a3;

  l1.value = 0;
  l1.next = &l2;

  l2.value = 1;
  l2.next = &l3;

  l3.value = 2;
  l3.next = NULL;

  a1.value = 4;
  a1.next = &a2;

  a2.value = 5;
  a2.next = &a3;

  a3.value = 6;
  a3.next = NULL;

  ListNode* head = &l1;
  ListNode* temp_ptr = head;

  std::cout << "LINKED LIST 1" << std::endl;

  while (temp_ptr != NULL) {
    std::cout << temp_ptr->value << std::endl;
    temp_ptr = temp_ptr->next;
  }

  temp_ptr = &a1;

  std::cout << "LINKED LIST 2" << std::endl;

  while (temp_ptr != NULL) {
    std::cout << temp_ptr->value << std::endl;
    temp_ptr = temp_ptr->next;
  }

  Solution solution;
  ListNode* res = solution.mergeTwoLists(&l1, &a1);

  temp_ptr = res;

  std::cout << "=============== MERGING BOTH LISTS ====================" << std::endl;

  while (temp_ptr != NULL) {
  std::cout << temp_ptr->value << std::endl;
  temp_ptr = temp_ptr->next;
  }

}