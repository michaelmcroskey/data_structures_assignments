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
        struct Node {
            T     data;
            Node *next;
        };

        typedef Node * iterator;

        Node  *head;
        size_t length;

    public:
        List() : head(nullptr), length(0) {}
        iterator front() { return head; };

        ~List();                                    // Destructor
        List(const List<T> &other);		    // Copy Constructor
        List<T>& operator=(List<T> other);	    // Assignment Operator
        void swap(List<T> &other);		    // Utility

        size_t size() const { return length; }
        T& at(const size_t i);
        void insert(iterator it, const T &data);
        void push_back(const T &data);
        void erase(iterator it);
};

//------------List Implementation-------------//

// Post-condition: Clears all nodes from list
template <typename T>
List<T>::~List() {
    Node *next = nullptr;

    // Need next otherwise invalid reads (use valgrind)
    for (Node *curr = head; curr != nullptr; curr = next) {
        next = curr->next;
        delete curr;
    }
}

// Post-condition: Copies all nodes from other
template <typename T>
List<T>::List(const List<T> &other)
    : head(nullptr), length(0) {
    for (Node *curr = other.head; curr != nullptr; curr = curr->next) {
        push_back(curr->data);
    }
}

// Post-condition: Clears existing list and copies all nodes from other
template <typename T>
List<T>& List<T>::operator=(List<T> other) {
    swap(other);
    return *this;
}

template <typename T>
void List<T>::swap(List<T> &other) {
    std::swap(head, other.head);
    std::swap(length, other.length);
}

template <typename T>
T& List<T>::at(const size_t i) {
    Node *node = head;
    size_t   n = 0;

    while (n < i && node != nullptr) {
        node = node->next;
        n++;
    }

    if (node) {
        return node->data;
    } else {
        throw std::out_of_range("invalid list index");
    }
}

template <typename T>
void List<T>::insert(iterator it, const T& data) {
    if (head == nullptr && it == nullptr) {
        head = new Node{data, nullptr};
    } else {
    	Node *node = new Node{data, it->next};
    	it->next   = node;
    }
    length++;
}

template <typename T>
void List<T>::push_back(const T& data) {
    if (head == nullptr) {
        head = new Node{data, nullptr};
    } else {
        Node *curr = head;
        Node *tail = head;

        while (curr) {
            tail = curr;
            curr = curr->next;
        }

        tail->next = new Node{data, nullptr};
    }
    length++;
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

    length--;
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

    // List copy
    std::cout << "**** Copy" << std::endl;
    List<int> copy(list);

    std::cout << "Copy Size: " << copy.size() << std::endl;
    std::cout << "Copy Items:" << std::endl;
    for (size_t i = 0; i < copy.size(); i++) {
        std::cout << "Copy at " << i << " " << copy.at(i) << std::endl;
    }

    // List assignment
    std::cout << "**** Assignment" << std::endl;
    copy.push_back(NITEMS + 4);
    list = copy;
    std::cout << "List Size: " << list.size() << std::endl;
    std::cout << "List Items:" << std::endl;
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << "List at " << i << " " << list.at(i) << std::endl;
    }

    // Erase
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
