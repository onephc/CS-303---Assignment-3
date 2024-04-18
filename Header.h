#pragma once

template <typename Item_Type>
class Single_Linked_List {
private:
	struct Node {
		Item_Type data;
		Node* next; //points to next node for list

		//constructor for Node
		Node(const Item_Type& data_item, Node* nxt_ptr = NULL) : data(data_item), next(nxt_ptr) {}
	};
	Node* head; //first
	Node* tail; //last
	size_t num_items;

public:
	Single_Linked_List() { //constructor for Single_Linked_List
		head = NULL;
		tail = NULL;
		num_items = 0;
	}

	void push(const Item_Type& item) {  // ADD TO THE FRONT
		head = new Node(item, head);
		if (tail == NULL) tail = head;
		++num_items; //Increment numitems
	}

	void push_back(const Item_Type& item) { //add to the back
		if (tail == NULL)
		{
			head = tail = new Node(item); //if there is only 1 node, make tail also head
		}
		else {
			tail->next = new Node(item); //add the new node to the list then updates tail
			tail = tail->next;
		}
		++num_items;
	}

	void insertion_sort() {  
		if (!head || !head->next)
			return;

		Node* sorted = nullptr;
		Node* key = head;

		while (key) {
			Node* nextNode = key->next;

			if (!sorted || sorted->data >= key->data) {
				key->next = sorted;
				sorted = key;
			}
			else {
				Node* temp = sorted;
				while (temp->next && temp->next->data < key->data) {
					temp = temp->next;
				}
				key->next = temp->next;
				temp->next = key;
			}

			key = nextNode;
		} 

		head = sorted;
	}

	void printList() {
		while (head) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}

	void pop_front() { //removes top/head entry
		if (head != NULL) {
			Node* temp = head;
			head = head->next; //set a new head
			delete temp;
			--num_items; //decrementg num items
			if (num_items == 0) tail = NULL;
		}
		else
		{
			std::cout << "Can not pop. Vector is empty." << std::endl;
		}
	}

	void pop_back() { //removes bottom/tail entry
		if (head == NULL) return; //empty list
		if (head == tail) { //only one element
			delete head;
			head = tail = NULL;
			--num_items;
			return;
		}
		Node* temp = head; //temp holder for head value
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = NULL;
		--num_items;
	}

	Item_Type front() { //returns the top/head element
		if (head != NULL)
			return head->data;
		else
			throw std::out_of_range("List is empty");
	}

	Item_Type back() { //returns the bottom/tail element
		if (tail != NULL)
			return tail->data;
		else
			throw std::out_of_range("List is empty");
	}

	bool empty() { //checks if empty
		return num_items == 0;
	}

	void insert(size_t index, const Item_Type& item) { //for inserting anywhere in the list
		if (index == 0) { //if empty, just pushes to front
			push_front(item);
		}
		else {
			Node* temp = head;
			size_t i = 0;
			while (temp != NULL && i < index - 1) { //iterates through list to move entries
				temp = temp->next;
				++i;
			}
			if (temp != NULL) {
				temp->next = new Node(item, temp->next);
				if (temp == tail) tail = temp->next;
				++num_items;
			}
		}
	}

	bool remove(size_t index) { //for removing anywhere in the list and returning if it was successful
		if (index >= num_items) return false; //out of range
		if (index == 0) { //if head entry
			pop_front();
			return true;
		}
		Node* temp = head;
		size_t i = 0;
		while (temp != NULL && i < index - 1) { //if not head entry, finds index to remove
			temp = temp->next;
			++i;
		}
		if (temp != NULL && temp->next != NULL) { //if not the tail
			Node* temp = temp->next;
			temp->next = temp->next;
			if (temp == tail) tail = temp; //sets the new tail
			delete temp;
			--num_items;//decrement num items
			return true;
		}
		return false;
	}

	size_t find(const Item_Type& item) { //to find which index contains passed value
		Node* temp = head;
		size_t index = 0;
		while (temp != NULL) {
			if (temp->data == item) {
				return index;
			}
			temp = temp->next;
			++index;
		}
		return num_items;
	}
};