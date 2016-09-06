// Challenge 02: Adding List-Based Integers

// Michael McRoskey
// Challenge 02
// solution.cpp

#include <cstdlib>
#include <iostream>
#include <stdexcept>

const int NITEMS = 10;

//------------List Declaration-------------//

template <typename T>
class List {
    protected:
        struct Node {   // Why struct instead of class?
            T     data;
            Node *next;
        };

        typedef Node * iterator;// What is this?

        Node *head;

    public:
        List() : head(nullptr) {}  // Leave out and it segfaults
        iterator front() { return head; }; // Need iterator method b/c internals are protected

        size_t size() const;
        T& at(const size_t i);
        void insert(iterator it, const T &data);
        void push_back(const T &data);
        void erase(iterator it);
};

//------------List Implementation-------------//

template <typename T>
size_t List<T>::size() const {
    size_t size = 0;

    // Condition can also just be node
    for (Node *node = head; node != nullptr; node = node->next) {
        size++;
    }

    return size;
}

template <typename T>
T& List<T>::at(const size_t i) {
    Node *node = head;
    size_t   n = 0;

    while (n < i && node != nullptr) {
        node = node->next;
        n++;
    }

    if (node != nullptr) {
        return node->data;
    } else {
        throw std::out_of_range("invalid list index");
    }
}

// Post-Condition: New Node is created with specified data value and placed
// after the iterator it.
template <typename T>
void List<T>::insert(iterator it, const T& data) {
    // Handle empty list
    if (head == nullptr && it == nullptr) {
        head = new Node{data, nullptr};
        return;
    }

    if (it == nullptr) {
        throw std::out_of_range("invalid iterator");
    }

    it->next = new Node{data, it->next};
}

// Post-Condition: New Node is create with specified data value and placed at
// the end of the list.
template <typename T>
void List<T>::push_back(const T& data) {
    // Handle empty list
    if (head == nullptr) {
        head = new Node{data, nullptr};
        return;
    }

    Node *curr = head;
    Node *tail = head;

    while (curr) {
        tail = curr;
        curr = curr->next;
    }

    tail->next = new Node{data, nullptr};
}

template <typename T>
void List<T>::erase(iterator it) {
    if (it == nullptr) {
        throw std::out_of_range("invalid iterator");
    }

    if (head == it) {
        head = head->next;
        delete it;
    } else {
        Node *node = head;

        while (node != nullptr && node->next != it) {
            node = node->next;
        }

        if (node == nullptr) {
            throw std::out_of_range("invalid iterator");
        }

        node->next = it->next;
		delete it;
	}
}

//------------Main Execution-------------//

int main(int argc, char *argv[]) {
	List<int> list;

	std::cout << "List Size: " << list.size() << std::endl;

	for (int i = 0; i < NITEMS; i++) {
		list.push_back(i);
	}

	std::cout << "List Size: " << list.size() << std::endl;
	std::cout << "List Items:" << std::endl;
	for (size_t i = 0; i < list.size(); i++) {
		std::cout << "List at " << i << " " << list.at(i) << std::endl;
	}

	std::cout << "**** Insert" << std::endl; 
	auto head = list.front();
	list.insert(head, NITEMS + 1);
	list.insert(head, NITEMS + 2);
	list.insert(head->next->next, NITEMS + 3);

	std::cout << "List Size: " << list.size() << std::endl;
	std::cout << "List Items:" << std::endl;
	for (size_t i = 0; i < list.size(); i++) {
		std::cout << "List at " << i << " " << list.at(i) << std::endl;
	}

	std::cout << "**** Erase" << std::endl; 
	list.erase(list.front());
	list.erase(list.front()->next);
	std::cout << "List Size: " << list.size() << std::endl;
	std::cout << "List Items:" << std::endl;
	for (size_t i = 0; i < list.size(); i++) {
		std::cout << "List at " << i << " " << list.at(i) << std::endl;
	}

	return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
