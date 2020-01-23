/*
* AJ Stein
* Ohio University CS3610 Project 1
* 1-16-20
* We are to write a program that takes some numbers from the command line, and then print them, add to them, delete them, or reverse the order
*/
#ifndef LINKEDL
#define LINKEDL

template<class T>
class LinkedList {
  public:
    LinkedList() : head(NULL) {} // this is the same as head = NULL;
    ~LinkedList();

    void push_front(const T data);
    void pop_front();
    void reverse();
    void print() const;

  private:
    struct ListNode {
      ListNode(const T data) : data(data), next(NULL) {}

      T data; 
      ListNode* next; 
  };

  ListNode* head;
};
#include "LL.template"
#endif