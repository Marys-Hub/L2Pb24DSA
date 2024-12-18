#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>


using namespace std;
//Theta(1)
ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
    //TODO - Implementation
    //this->list = list;
    //current = list.head scris mai jos
    current = reinterpret_cast<Node *>(list.head);
}
//Theta(1)
void ListIterator::first(){
    //TODO - Implementation
    //current = list.head;
    current = reinterpret_cast<Node *>(list.head);
}
//Theta(1)
void ListIterator::next(){
    //TODO - Implementation
    if (valid()) {
        current = current->next;
    }else
        throw exception();

}
//Theta(1)
bool ListIterator::valid() const{
    //TODO - Implementation
    return current != nullptr;
    return false;
}
//Theta(1)
TComp ListIterator::getCurrent() const{
    //TODO - Implementation
    if (valid()) {
        return current->value;
    } else
        throw exception();

    return NULL_TCOMP;
}


