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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    // TODO: Write your code here
    bool result = true;
    //step 1: find the middle node
    ListNode *slow = head;
    ListNode *fast = head;
    int count = 0;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        count++;
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

    //step 3: compare 
    ListNode *forwardP = head;
    ListNode *backwardP = tail;
    for (int i=0; i<count; i++) {
        if (forwardP->value != backwardP->value) {
            result = false;
            break;
        }
        forwardP = forwardP->next;
        backwardP = backwardP->next;
    }

    //step 4: reverse the latter part
    originalNext = nullptr;
    p = tail;
    do {
        previous = p->next;
        p->next = originalNext;
        originalNext = p;
        p = previous;
    } while (previous != nullptr);

    return result;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}