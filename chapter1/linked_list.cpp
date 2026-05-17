#include <iostream>

struct Node {
  int value;
  Node* next;
};

void PrintLinkedList(Node* node) {
  Node* current=node;
  while (current != nullptr) {
    std::cout << current->value << "\n";
    current=current->next;
  }
}

int main() {
  Node head;
  Node middle;
  Node tail;

  head.value=100;
  head.next=&middle;

  middle.value=200;
  middle.next=&tail;

  tail.value=300;
  tail.next=nullptr;

  PrintLinkedList(&head);

  return 0;
}