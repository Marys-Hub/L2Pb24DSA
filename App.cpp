#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    testAll();
    testAllExtended();
    std::cout<<"Finished IL Tests!"<<std::endl;
    system("pause");

    // old project
    /*
    Relation r;
    SortedIteratedList list1(r);
    list1.add(1);
    list1.add(3);
    list1.add(5);

    SortedIteratedList list2(r);
    list2.add(2);
    list2.add(4);
    list2.add(6);

    // interclass the two lists into a new list
    SortedIteratedList result = list1.functie_sup(list2); */

}