#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>
//Komplexitat Theta(1)
SortedIteratedList::SortedIteratedList(Relation r) {
    //TODO - Implementation
    rel = r;
    //this->rel=r;
    this->head = nullptr;
    this->tail = nullptr;
}
// Theta(n)
int SortedIteratedList::size() const {
    //TODO - Implementation
    int count = 0;
    for(ListIterator it = first(); it.valid();it.next()){
        count++;
    }
    return count;
}
//Theta(1)
bool SortedIteratedList::isEmpty() const {
    //TODO - Implementation
    return head == nullptr;
    return false;
}
//Theta(1)
ListIterator SortedIteratedList::first() const {
    //TODO - Implementation
    return ListIterator(*this ); // been initialised with head
}
//Theta(1)
TComp SortedIteratedList::getElement(ListIterator poz) const {
    //TODO - Implementation
    if(poz.valid()){
        return poz.getCurrent();
    }else
        throw exception();
    return NULL_TCOMP;
}
//worst case:Theta(n) best case:Theta(1) general: O(n)
TComp SortedIteratedList::remove(ListIterator& poz) {
    //TODO - Implementation
    if(!poz.valid()){
        throw exception();
    }
    // Get the node to remove
    Node* nodeToRemove = reinterpret_cast<Node *>(poz.current);
    // Update the position to point to the next node in the list
    poz.next();
    // Check if the node to remove is the head of the list
    if (nodeToRemove == head) {
        head = nodeToRemove->next;
    }  else {
        // Update the previous node's next pointer to skip over the node to remove
        nodeToRemove->prev->next = nodeToRemove->next;
    }
    // Check if the node to remove is the tail of the list
    if (nodeToRemove == tail) {
        tail = nodeToRemove->prev;
    } else {
        // Update the next node's prev pointer to skip over the node to remove
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    // Save the value of the node to remove
    TComp removedValue = nodeToRemove->value;
    delete nodeToRemove;

    // Return the removed value
    return removedValue;

    return NULL_TCOMP;
}
//worst case:Theta(n) best case:Theta(1) general: O(n)
ListIterator SortedIteratedList::search(TComp e) const{
    //TODO - Implementation
    // iterate through list
    for(ListIterator it = first();it.valid();it.next()){
        if(it.getCurrent() == e){
            return it;
        }
    }
    return ListIterator(nullptr);
}
//worst case:Theta(n) best case:Theta(1) general: O(n)
void SortedIteratedList::add(TComp e) {
    //TODO - Implementation

    Node* elem = new Node;
    elem->value = e;
    //check if list is empty, if so, first elem is put into list
    if (head == NULL)
    {
        elem->prev = NULL;
        elem->next = NULL;
        head = elem;
        tail = elem;
    }
    else
    {   //start looking and keeping the previous node for changes
        Node* curent = head;
        Node* previous = NULL;
        //iterate and check rel until current is either NULL or somewhere in list to be added
        while (curent != NULL && rel(curent->value, e))
        {
            previous = curent;
            curent = curent->next;
        }
        //bind the node against my list, NUSH DACA E correct
        elem->prev = previous;
        elem->next = curent;
        //current didnt meke it til the end
        if (curent != NULL)
        {
            curent->prev = elem;
            //previous->next = elem; nu aici ca imi intra in loop
        }
        else  //when curent is NULL and elem is outside the list
        {
            tail = elem; // set tail with elem as the last elem
        }
        if (previous != NULL)
        {
            //to update also the step from the first case
            previous->next = elem;
        }
        else
        {
            //here previous is as in the bning so the elem needs to be the head, added on the first poz
            head = elem;
        }

    }
}

SortedIteratedList SortedIteratedList::functie_sup(SortedIteratedList& l1, SortedIteratedList& l2) {
  //TODO implementation
  // AR TREBUI CA liste initializate cu head
    Relation r;
    SortedIteratedList result(r); // copy constructor;
    Node* it1 = l1.head, *it2 = l2.head;
    while (it1 != NULL && it2 != NULL) {
        //it1->value <= it2->value
        if (rel(it1->value, it2->value)) {
            result.add(it1->value);
            it1 = it1->next;
        }
        else {
            result.add(it2->value);
            it2 = it2->next;
        }
    }

    while (it1 != NULL) {
        result.add(it1->value);
        it1 = it1->next;
    }

    while (it2 != NULL) {
        result.add(it2->value);
        it2 = it2->next;
    }

    return result;
}


//worst case:Theta(n) best case:Theta(1) general: O(n)
SortedIteratedList::~SortedIteratedList() {
    //TODO - Implementation
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current; }
}
