#include "IntList.h"

#include <iostream>
#include <exception>

using namespace std;

#include <iostream>
// output list to stream using overloaded operator <<
ostream & operator<<(ostream &out, const IntList &rhs) {
  IntNode * curr = rhs.dummyHead.next;
  while (curr != &rhs.dummyTail) {  // iterates until curr is tail --> if empty curr->next = nullptr --> curr = tail
    out << curr->data;
    if (curr != rhs.dummyTail.prev) { // space after everything except at end
      out << ' ';
    }
    curr = curr->next;
  }
  return out;
}

// delete list
IntList::~IntList() {
  while (!empty()) {  // iterate through list
    pop_front();  // will have end tests, etc. already
  }
}

// add node to front of list
void IntList::push_front(int value) {
  IntNode * newNode = new IntNode(value);
  newNode->next = dummyHead.next;
  newNode->prev = &dummyHead;
  dummyHead.next->prev = newNode;
  dummyHead.next = newNode;
}

// remove node from front of list
void IntList::pop_front() {
  if (empty()) {  // throw error if empty
    throw runtime_error("List is empty");
  }
  IntNode * remove = dummyHead.next;
  dummyHead.next = remove->next;
  remove->next->prev = &dummyHead;
  delete remove;
}

// add node to back of list
void IntList::push_back(int value) {
  IntNode * newNode = new IntNode(value);
  newNode->next = &dummyTail;
  newNode->prev = dummyTail.prev;
  dummyTail.prev->next = newNode;
  dummyTail.prev = newNode;
}

// remove node from back of list
void IntList::pop_back() {
  if (empty()) {  // throw error if empty
    throw runtime_error("List is empty");
  }
  IntNode * remove = dummyTail.prev;
  dummyTail.prev = remove->prev;
  remove->prev->next = &dummyTail;
  delete remove;
}

// verify if list is empty
bool IntList::empty() const {
  return !(dummyHead.next->next); // empty if dummyHead's next points to dummyTail, which would point to nullptr
}

// output list backwards
void IntList::printReverse() const {
  IntNode * curr = dummyTail.prev;
  while (curr->prev) {  // iterate through list
    cout << curr->data;
    curr = curr->prev;
    if (curr->prev) {
      cout << ' ';
    }
  }
}