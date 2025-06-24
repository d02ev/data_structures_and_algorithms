#include <iostream>

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
  Node *HEAD = nullptr, *TAIL = nullptr;
  int length = 0;

  public:
    // insertions
    // at the start
    Node* insertAtStart(int val) {
      Node* new_node = new Node(val);
      ++length;

      if (HEAD == nullptr) {
        HEAD = new_node;
        TAIL = HEAD;
      } else {
        new_node -> next = HEAD;
        HEAD = new_node;
      }

      return HEAD;
    }

  // at the end
  Node* insertAtEnd(int val) {
    Node* new_node = new Node(val);
    ++length;

    if (HEAD == nullptr) {
      HEAD = new_node;
      TAIL = HEAD;
    } else {
      TAIL -> next = new_node;
      TAIL = new_node;
    }

    return HEAD;
  }

  // at a specific position
  Node* insertAt(int n, int val) {
    Node* new_node = new Node(val);

    if (n == 0) {
      HEAD = insertAtStart(val);
    }
    else if (n == length - 1) {
      HEAD = insertAtEnd(val);
    }
    else if (n >= length || n < 0) {
      std::cout << "Invalid position" << std::endl;
      return nullptr;
    }
    else {
      Node* temp = HEAD;
      for (int i = 0; i < n - 1; ++i) {
        temp = temp -> next;
      }

      new_node -> next = temp -> next;
      temp -> next = new_node;
      ++length;
    }

    return HEAD;
  }

  // deletions
  // from the start
  Node* deleteFromStart() {
    if (HEAD == nullptr) {
      std::cout << "List is empty" << std::endl;
      return nullptr;
    }

    --length;

    Node* temp = HEAD;
    HEAD = HEAD -> next;

    delete temp;
    return HEAD;
  }

  // from the end
  Node* deleteFromEnd() {
    if (HEAD == nullptr) {
      std::cout << "List is empty" << std::endl;
      return nullptr;
    }

    --length;

    Node *temp1 = HEAD, *temp2 = nullptr;
    while (temp1 -> next -> next != nullptr) {
      temp1 = temp1 -> next;
    }

    TAIL = temp1;
    temp2 = temp1 -> next;
    temp1 -> next = nullptr;

    delete temp2;
    return HEAD;
  }

  // from a specific position
  Node* deleteFrom(int n) {
    if (n == 0) {
      HEAD = deleteFromStart();
    }
    else if (n == length - 1) {
      HEAD = deleteFromEnd();
    }
    else if (n >= length || n < 0) {
      std::cout << "Invalid position" << std::endl;
      return nullptr;
    }
    else {
      --length;

      Node *temp1 = HEAD, *temp2 = nullptr;
      for (int i = 0; i < n - 1; ++i) {
        temp1 = temp1 -> next;
      }

      temp2 = temp1 -> next;
      temp1 -> next = temp2 -> next;

      delete temp2;
    }

    return HEAD;
  }

  // printing
  // iterative
  void printIterative() {
    if (HEAD == nullptr) {
      std::cout << "List is empty" << std::endl;
      return;
    }

    Node* temp = HEAD;
    while (temp != nullptr) {
      std::cout << temp -> data << " ";
      temp = temp -> next;
    }

    std::cout << std::endl;
  }

  // recursive
  void printRecursive(Node*& head) {
    if (head == nullptr) {
      std::cout << std::endl;
      return;
    }

    std::cout << head -> data << " ";
    printRecursive(head -> next);
  }

  // reverse
  void printReverse(Node*& head) {
    if (head == nullptr) return;

    printReverse(head -> next);
    std::cout << head -> data << " ";
  }

  // size
  int size() {
    return length;
  }

  // first element
  int front() {
    return HEAD -> data;
  }

  // last element
  int back() {
    return TAIL -> data;
  }

  // reverse the list
  // iterative
  Node* reverseListIterative() {
    if (HEAD == nullptr || HEAD -> next == nullptr) return HEAD;

    Node *curr = HEAD, *prev = nullptr, *front = nullptr;
    TAIL = HEAD;
    while (curr != nullptr) {
      front = curr -> next;
      curr -> next = prev;
      prev = curr;
      curr = front;
    }

    HEAD = prev;
    return HEAD;
  }

  // recursive
  Node* reverseListRecursive(Node*& head) {
    if (HEAD == nullptr || HEAD -> next == nullptr) return HEAD;

    Node* new_head = reverseListRecursive(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;

    return new_head;
  }
};

int main(int argc, char* argv[]) {
  LinkedList* ll = new LinkedList();
  Node* head = nullptr;

  for (int i = 1; i <= 5; ++i) {
    // head = ll -> insertAtStart(i);
    head = ll -> insertAtEnd(i);
  }

  std::cout << ll -> size() << std::endl;

  head = ll -> insertAt(0, -1);
  std::cout << ll -> size() << std::endl;
  head = ll -> insertAt(5, -1);
  std::cout << ll -> size() << std::endl;
  head = ll -> insertAt(3, - 1);
  std::cout << ll -> size() << std::endl;

  ll -> printIterative();

  // head = ll -> deleteFromStart();
  // head = ll -> deleteFromEnd();
  head = ll -> deleteFrom(0);
  std::cout << ll -> size() << std::endl;
  head = ll -> deleteFrom(6);
  std::cout << ll -> size() << std::endl;
  head = ll -> deleteFrom(3);
  std::cout << ll -> size() << std::endl;

  std::cout << ll -> front() << " " << ll -> back() << std::endl;


  // ll -> printIterative();
  ll -> printRecursive(head);

  head = ll -> reverseListIterative();

  std::cout << ll -> front() << " " << ll -> back() << std::endl;

  ll -> printRecursive(head);

  // ll -> printReverse(head);
  // std::cout << std::endl;

  return 0;
}