// This file contains the 'main' function. Program execution begins and ends there.


#include "HW3QUEUE.h"
#include <iostream>
#include <vector>

using namespace CQ;

int main()
{
    CQ::queue<int> elements; //this creates a queue of integers
    
    elements.push(2);
    elements.push(4);
    elements.push(23);
    elements.push(17);
    elements.push(34);
    elements.push(14);
    elements.push(2);


    std::cout << "UNSORTED" << std::endl;
    elements.display(); //the display function uses only the given functions
    std::cout << "MOVED TO REAR" << std::endl;
    elements.move_to_rear(); //moves first element to the rear
    elements.display();
    std::cout << "SORTED" << std::endl;
    insertion_sort(elements); //SORTS ELEMENTS
    elements.display();

    std::vector<int> items(3,3); // MADE A VECTOR TO SHOW SEARCH
    for (int i = 0; i < 5; i++) {
        items.push_back(i);
    };
    
    printvec(items); //PRINTS THE VECTOR
    std::cout << std::endl;
    int target = 3;
    int last_pos = linear_search(items, target); //searches  vector for target
    std::cout << "The last occurance of TARGET: " << target << " is index " << last_pos << std::endl;

    return 0;
}

