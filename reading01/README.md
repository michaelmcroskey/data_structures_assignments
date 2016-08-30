Reading 01
==========

Michael McRoskey
----------------

**1) In the context of data structures, why would using a language with templates be advantageous?**
Languages that use templates are advantageous because they allow us to utilize a data structure for several different data types. Thus, we can abstract the structure itself to work with ints, chars, etc. Languages that use templates recognize the type at the point of compilation, meaning we can reuse the same structure for different purposes while letting the language handle the nitty gritty.

**2) Explain what the violation of the *Rule of Three*, why it is problematic, and what you would do to fix it.**
The Rule of Three says that implementing any of the destructor, copy constructor, or copy assignment constructor necessitates defining all three. In this case, a destructor was written in but no copy constructor or copy assignment constructor. I would implement this with the code below:


~~~~
//stack.h
#pragma once
template <class T>
class Stack
{
public:
Stack(int = 10) ;
~Stack() { delete [] stackPtr ; }
Stack& operator=(const Stack& other); // copy assignment operator
Stack (const Stack& other); // copy constructor
int push(const T&);
int pop(T&) ;  // pop an element off the stack
int isEmpty()const { return top == -1 ; }
int isFull() const { return top == size - 1 ; }
private:
int size ;  // Number of elements on Stack
int top ;
T* stackPtr ;
} ;

~~~~

**3) Dynamic Array: What would be the complexity in terms of Big-O for the following operations:**
- Locate an element based on index: **O(1)**
- Insert an element in the front: **O(n)**
- Insert an element in the back:  **O(1)**

**What is the difference between a vector's size and capacity? How do these properties influence the insert operation?**
The vector size is the amount of elements within the vector. The capacity is a lower-level term referring to the array that's actually created for the vector's implementation. It dynamically changes to always be larger than the size.

**4) Linked List: What would be the complexity in terms of Big-O for the following operations:**
- Locate an element based on index: **O(n)**
- Insert an element in the front: **O(1)**
- Insert an element in the back: **O(n)**

**How does using a singly linked list instead of a doubly linked list effect the complexity of these operations?**
A single and doubly linked lists vary in complexity by front/back insertion and deletion: the extra pointer means the front and back are linked in both directions and thus can insert and delete on the order of O(1).
