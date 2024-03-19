#ifndef SORTEDNUMBERLIST_H
#define SORTEDNUMBERLIST_H
#include "Node.h"

class SortedNumberList {
private:
   // Optional: Add any desired private functions here

public:
   Node* head;
   Node* tail;

   SortedNumberList() {
      head = nullptr;
      tail = nullptr;
   }

   // Inserts the number into the list in the correct position such that the
   // list remains sorted in ascending order.
   void Insert(double number) {
    // Create a new node with the given number value
    //Your code here
    Node* newNode = new Node(number);

    // If the list is empty, set the new node as both head and tail
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // If the new node's value is less than or equal to the current head's value,
    // insert it before the current head and update the head pointer
    if (number <= head->GetData()) {
        newNode->SetNext(head);
        head->SetPrevious(newNode);
        head = newNode;
        return;
    }

    if(number>=tail->GetData()){
        tail->SetNext(newNode);
        newNode->SetPrevious(tail);
        tail=newNode;
        return;
    }

    // Traverse the list to find the correct position to insert the new node
    Node* current = head;
    while (current->GetNext() != nullptr && current->GetNext()->GetData() < number) {
        current = current->GetNext();
    }

    // Insert the new node between the current node and its next node
    newNode->SetNext(current->GetNext());
    if (current->GetNext() != nullptr) {
        current->GetNext()->SetPrevious(newNode);
    }
    current->SetNext(newNode);
    newNode->SetPrevious(current);

    // Update the tail pointer if the new node is inserted at the end of the list
    if (newNode->GetNext() == nullptr) {
        tail = newNode;
    }
}


   // Removes the node with the specified number value from the list. Returns
   // true if the node is found and removed, false otherwise.
   bool Remove(double number) {
      // Your code here
      //If list emty,nothing to remove
      if(head==nullptr){
      return false;
      }
      //If the number to be removed is the head
      if(head->GetData()==number){
        Node* temp=head;
        head=head->GetNext();
        if(head!=nullptr){
            head->SetPrevious(nullptr);

        }
        else{
            tail=nullptr;
        }
        delete temp;
        return true;
      }

      if(tail->GetData()==number){
        Node* temp=tail;
        tail=tail->GetPrevious();
        tail->SetNext(nullptr);
        delete temp;
        return true;
      }

      //Traversing the list to find the node with the specified number value
      Node* current=head;
      while(current!=nullptr && current->GetData()!=number){
        current=current->GetNext();
      }
      //If number not found
      if(current==nullptr){
        return false;
      }
      //Adjusting the pointers to remove the node
      if(current==tail){
        return false;
      }
      current->GetPrevious()->SetNext(current->GetNext());
      current->GetNext()->SetPrevious(current->GetPrevious());
      delete current;
      return true;

   }

   };

#endif
