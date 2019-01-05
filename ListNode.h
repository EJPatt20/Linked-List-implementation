
#ifndef LISTNODE_H
#define LISTNODE_H
 
#include <iostream>
 
// next line needed because NULL is part of std namespace
using namespace std;
 
class ListNode {
public:
    ListNode();                 // Constructor
 
private:
    int value;
    ListNode *next, *previous;  // for doubly linked lists
 
    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class List;
 
    // ListItr needs to access/change ListNode as well
    friend class ListItr;
 
};
 
#endif
