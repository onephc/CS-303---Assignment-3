#pragma once

#include <iostream>
#include <vector>



//linear search section

template <typename Item_Type>
size_t linear_search(const std::vector<Item_Type>& items, const Item_Type& target, size_t pos) {
	if (pos == -1) { // Base case: no more elements to search
		return -1;
	}
	if (items[pos] == target) {
		return pos;  // Found the target, return its position
	}
	else {
		return linear_search(items, target, pos - 1);  // Search in the previous sections for element
	}
}

template <typename Item_Type>
size_t linear_search(const std::vector<Item_Type>& items, const Item_Type& target) { //overload the function to call recursively based on variables
	return linear_search(items, target, items.size() - 1);
}

template <typename Item_Type>
void printvec(std::vector <Item_Type>& items) {
	for (int i = 0; i < items.size(); i++) //PRINTS THE VECTOR AGAIN
	{
		std::cout << items[i];
	};
}

namespace CQ {

  template<typename Item_Type>
  class queue {
  private:
    struct Node {
      Item_Type data;
      Node* next; //points to next node for list

      //constructor for Node
      Node(const Item_Type& data_item, Node* nxt_ptr = nullptr) : data(data_item), next(nxt_ptr) {}
    };
    Node* head; //first
    Node* tail; //last
    size_t num_items;

  public:
    queue() { //constructor
      head = nullptr;
      tail = nullptr;
      num_items = 0;
    }

    ~queue() { //destructor
      while (!empty()) {
        pop();
      }
    }

    void push(const Item_Type& data) { //adds an element to the back of the queue
      Node* newNode = new Node(data);
      if (empty()) {
        head = tail = newNode;
      }
      else {
        tail->next = newNode;
        tail = newNode;
      }
      ++num_items;
    };

    void pop() { //removes the first element of the queue
      if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --num_items;
      }
    };

    Item_Type front() { //returns the top/head element
      if (!empty()) {
        return head->data;
      }
    };

    bool empty() { //checks if empty
      return num_items == 0;
    };

    size_t size() { //RETURNS THE SIZE OF THE VECTOR
      return num_items;
    };

    void move_to_rear() { //Moves the first element in the queue to the rear
      Item_Type temp = head->data;
      if (!empty()) {
        pop();
        push(temp);
      }
    };

    void display() { //display using only push pop front size functions
      int iter = 0;
      while (iter < size()) {
        Item_Type temp = head->data;
        std::cout << front() << " ";
        pop();
        push(temp);
        ++iter;
      }
      std::cout << std::endl;
    };


  };
};

template <typename Item_Type>
void insertion_sort(CQ::queue<Item_Type>& num) { 
	for (int j = 1; j < num.size(); j++) { 
		int key = num.front();
		num.pop();

		int i = j - 1;
		// Find the position where the key should be inserted
		while (i >= 0 && key > num.front()) {
			num.move_to_rear(); // push the smaller values to the back to find its place
			i--;
		}
		// Insert the key at its correct position
		num.push(key);
	}
}

