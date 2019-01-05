#include "List.h"
 
using namespace std;
 
List::List(){                                //constructor
 head = new ListNode; 
 tail = new ListNode;
  count = 0;
  head ->next =tail;
  tail -> previous = head;
   
  }
 
List:: ~List(){                               //destructor
  makeEmpty();
  delete(head);
  delete(tail);
     
  }
   
  List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
 
 List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
 };
 
bool List::isEmpty() const{
    if(count == 0){
      return true;
    }
    else{
      return false;
    }
}
 
void List::makeEmpty(){
  ListItr position  = first();
  while(position.isPastEnd() == false){
   int temp =  position.retrieve();
    position.moveForward();
    remove(temp);
  }
  count = 0;
}
 
ListItr List::first(){
  ListItr position(head->next);
  return position;
}
 
ListItr List::last(){
  ListItr position(tail->previous);
  return position;
}
 
void List::remove(int x){
  ListItr position = find(x);
  position.current->previous->next = position.current->next;
  position.current->next->previous = position.current->previous;
  delete(position.current);
  count--;
}
 
ListItr List::find(int x ){
  ListItr position = first();
  while( position.isPastEnd() == false){
    if( position.current->value ==x){
      return position;
    }
    position.moveForward();
  }
  return ListItr(head->next);
}
 
void List::insertBefore(int x, ListItr position ){
  ListNode* node = new ListNode();
  node->value = x;
  node -> next = position.current;
  node -> previous  = position.current-> next;
  position.current->previous->next = node;
  position.current-> previous = node;
  count++;
}
 
void List::insertAfter(int x, ListItr position){
  ListNode* node = new ListNode();
  node->value = x;
  node -> next = position.current->next;
  node -> previous = position.current;
  position.current->next = node;
  position.current->next->previous = node;
  count++;
}
 
void List::insertAtTail(int x){
  ListNode* node = new ListNode();
  ListNode* prev = tail->previous;
  node-> next = tail;
  node -> previous = prev;
  prev ->next = node;
  tail -> previous = node;
  node->value =x;
  count++;
  
}
 
int List:: size() const {
  return count; 
}
