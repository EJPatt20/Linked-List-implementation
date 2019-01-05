#include "ListItr.h"
 
 
using namespace std;
 
ListItr::ListItr(){
  current = new ListNode;
}
 
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}
 
bool ListItr::isPastEnd() const{
  if(current->next == NULL){
    return true;
  }
  return false;
}
 
bool ListItr::isPastBeginning() const{
  if(current->previous == NULL){
    return true;
  }
  return false;
}
 
void ListItr::moveForward(){
  current = current->next;
   
}
 
void ListItr::moveBackward(){
  current= current->previous;
 
}
 
int ListItr::retrieve() const{
  return current->value;
}
 
void printList(List& theList,bool forward){
  if(forward == true){
    ListItr itr = theList.first();
    while(itr.isPastEnd() == false){
     int x =  itr.retrieve();
     cout << x << endl;
     itr.moveForward();
    }
  }
    if(forward == false){
      ListItr itr = theList.last();
      while(itr.isPastBeginning() == false){
    int x = itr.retrieve();
    cout << x << endl;
    itr.moveBackward();
      }
    }
}
