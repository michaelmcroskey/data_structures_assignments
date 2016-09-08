// Challenge 02: Adding List-Based Integers

// Michael McRoskey
// Challenge 02
// solution.cpp

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cassert>

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
    
    ~List();								// Destructor
    List(const List<T> &other);				// Copy Constructor
    List<T>& operator=(List<T> other);		// Assignment Operator
    void swap(List<T> &other);				// Utility
    
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

int main() {
    
    using namespace std;
    
    string line;							// for reading input
    int input_lines = 0;					// # lines entered ()
    List<int> int1, int2;					// LLs to store integers
    
    while (getline(std::cin, line)){		// read input
        if (line.empty()) break;			// end if enter key
        input_lines++;						// increment line count
        
        int word = 1, ascii_shift = 48;		// word 1|2; character shift
        string::iterator it;				// rev. iterator for string
        
        //-------------Gather/Parse Input-------------//
        // start at the end and move toward beginning //
        
        for (it = line.end()-1; it >= line.begin(); it--){
            if (word == 1) {
                if(*it == ' '){				// if space, move to word 2
                    word = 2;
                    it--;
                } else {					// add value to int1 list
                    int1.push_back(*it-ascii_shift);
                }
            }
            if (word == 2) {				// add value to int2 list
                int2.push_back(*it-ascii_shift);
            }
        }
    }
    cout << "exited loop" << endl;
    
    //--------------Adding the Lists--------------//
    // start at the end and move toward beginning //
    
    List<int> sum;

	if (int1.size() > int2.size()) {		// second number bigger
		cout << "int1.size() is bigger" << endl;
		int i=0, digit;
		for (int j=i; j<int2.size(); j++) {
			digit = int1.at(j) + int2.at(j);
			if (digit >= 10) {
				int2.at(j+1) += (int)digit/10;
				digit = digit % 10;
		}
			sum.push_back(digit);
			i=j;
		}
		for (int k=i; k<int1.size()-1; k++) {
			sum.push_back(int1.at(k+1));
			i=k;
		}
		
		// display
	    for (size_t i=0; i<sum.size(); i++) {
	        std::cout << "List at " << i << " " << sum.at(i) << std::endl;
	    }
		
	} else if (int2.size() > int1.size()) {// first number bigger
		cout << "int2.size() is bigger" << endl;
		for (int i=0; i<int1.size(); i++) {
			sum.push_back(int1.at(i) + int2.at(i));
		}
		
	} else {								// equality, node by node
		for (int i=0; i<int1.size(); i++) {
			sum.push_back(int1.at(i) + int2.at(i));
			cout << "sum.at(i) is: " << sum.at(i) << endl;
		}
	}
	
	

//	    if (node) {
//	        return node->data;
//	    } else {
//	        throw std::out_of_range("invalid list index");
//	    }
		
		// %10 mod 10; remainder
    
    
    //--------------Printing Results--------------//
    // start at the end and move toward beginning //
    
/*
    //--------Display Integer 1----------//
    for (size_t i=0; i<int1.size(); i++) {
        std::cout << "List at " << i << " " << int1.at(i) << std::endl;
    }
    
    cout << endl;
    
    //--------Display Integer 1----------//
    for (size_t i=0; i<int2.size(); i++) {
        std::cout << "List at " << i << " " << int2.at(i) << std::endl;
    }
*/
    
    return 0;
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: