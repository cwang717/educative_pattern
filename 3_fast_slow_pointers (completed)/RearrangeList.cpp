using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class RearrangeList {
 public:
  static void reorder(ListNode *head) {
    // TODO: Write your code here  
    //step 1: find the middle node
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *middle = slow;

    //step 2: reverse the latter part
    ListNode *previous = nullptr;
    ListNode *p = middle;
    ListNode *originalNext;
    do {
        originalNext = p->next;
        p->next = previous;
        previous = p;
        p = originalNext;
    } while (p != nullptr);
    
    ListNode *tail = previous;  

    //step 3: 
    ListNode *forwardP = head;
    ListNode *backwardP = tail;
    previous = head;
    while (forwardP != middle) {
        ListNode *forwardNext = forwardP->next;
        forwardP->next = backwardP;
        ListNode *backwardNext = backwardP->next;
        backwardP->next = forwardNext;
        previous = backwardP;
        
        forwardP = forwardNext;
        backwardP = backwardNext;
    }
    previous->next = backwardP;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}
