// HW3TAKE3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Header.h"


int main()
{

    Single_Linked_List<int> list;
    list.push(2);
    list.push(1);
    list.push(3);
    list.push(23);
    list.push(87);
    list.push(45);
    list.push(4);

    std::cout << "Sorted List: ";
   
    list.insertion_sort();

    list.printList();


}
