Reading 02
==========

Michael McRoskey
----------------

---

**1) Given a binary tree with N nodes.**

- **What is the minimum height of the tree?**
    O(log(N))

- **What is the maximum height of the tree?**
    O(N)

**2) Given the  binary tree:**

- **How would you represent the binary tree using an array?**

       0     1     2     3     4     5     6     7     8     9    10    11    12
    [  R  |  O  |  G  |  U  |  E  |     |  O  |  N  |  E  |     |     |     |     ]
    *Note: spaces represent NULL*


- **When would it be better to use an array representation of a binary tree over the traditional node based representation?**
    It might be better to use an array representation when there is limited memory (to store the node pointers) and when the trees themselves are complete or even full and not in some arbitrary shape. It's also a good idea to use them when you're not expecting to insert, delete, or shift nodes, but remain a mostly static structure. You can still accomplish what you want but it's much simpler with a node-based representation.

**3) Given the  binary tree:**

- Record the nodes you would visit if you performed a breadth-first traversal of the binary tree (assume you go left-to-right when crossing a layer). What data structure would you use to perform this traversal? **W | Y | R | D | B | I | O | F | U | L | A | R | A | E | D**
    **I would use a queue to perform this traversal because it it is a FIFO structure, meaning if the root is first to be stored and the first to be deleted. This makes sense in the implementation of an array given the left-to-right top-to-bottom storing of a complete binary tree--this groups the different levels of the tree.**

- Record the nodes you would visit if you performed a depth-first traversal of the binary tree (assume you are using a pre-order approach). What data structure would you use to perform this traversal? **W | Y | D | F | U | B | L | A | R | I | R | A | O | E | D**
    **I would use a stack here because of its LIFO access--it stores all ancestors of a node in the immediate region of memory.**


**4) Modify the struct Node above to use smart pointers:**

    struct Node {
        int          value;
        std::unique_ptr<Node>  left(new Node());
        std::unique_ptr<Node> right(new Node());
    };

**What are the benefits of using smart pointers in this struct Node?**
    Smart pointers here will automatically delete when they become out of scope. This is important to ensure that each node has exactly one pointer to it and no nodes are arbitrarily linked. Thus, it maintains the structure of the binary tree.

