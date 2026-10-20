#include <iostream>


  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* dummy = new ListNode();
      ListNode* tail = dummy;

      while(list1 != NULL && list2 != NULL) {
        ListNode* newNode = new ListNode();
        if (list1->val < list2->val) {
          newNode->val = list1->val;
          list1 = list1->next;
        } else {
          newNode->val = list2->val;
          list2 = list2->next;
        }
        tail->next = newNode;
        tail = tail->next;
      }

      if (list1 != NULL) {
        tail->next = list1;
      } 

      if (list2 != NULL) {
        tail->next = list2;
      }

      return dummy->next;

    }
};


int main() {

  struct ListNode l1, l2, l3;
  struct ListNode a1, a2, a3;

  l1.val = 0;
  l1.next = &l2;

  l2.val = 1;
  l2.next = &l3;

  l3.val = 2;
  l3.next = NULL;

  a1.val = 4;
  a1.next = &a2;

  a2.val = 5;
  a2.next = &a3;

  a3.val = 6;
  a3.next = NULL;

  ListNode* head = &l1;
  ListNode* temp_ptr = head;

  std::cout << "LINKED LIST 1" << std::endl;

  while (temp_ptr != NULL) {
    std::cout << temp_ptr->val << std::endl;
    temp_ptr = temp_ptr->next;
  }

  temp_ptr = &a1;

  std::cout << "LINKED LIST 2" << std::endl;

  while (temp_ptr != NULL) {
    std::cout << temp_ptr->val << std::endl;
    temp_ptr = temp_ptr->next;
  }

  Solution solution;
  ListNode* res = solution.mergeTwoLists(&l1, &a1);

    while (res != NULL) {
    std::cout << res->val << std::endl;
    res = res->next;
  }
}