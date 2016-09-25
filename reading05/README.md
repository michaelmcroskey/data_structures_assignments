Reading 05
==========

Michael McRoskey
----------------

---

**1) What is the difference between a binary heap and a binary search tree? Can a binary tree consisting of at least two nodes be both a binary heap and a binary search tree? Explain.**

Binary heaps are binary trees such that the parent nodes are greater than or equal to child nodes (or less than or equal to child nodes for min-heaps). This ensures the max element is at the top and lesser elements below, giving finding a max or min value a complexity of O(1). On the other hand, binary search trees actually order the elements based on direction (left or right child nodes), allowing you to search for a specific element--it's more sorted. This search for a specific element is O(logN).

A binary tree consisting of at least two nodes can be both a binary heap and a binary search tree. If the root node is say 5 and the left child is 4, this is a valid case--there are at least two nodes, the tree is complete, all levels are filled except the last, the last level is filled left-to-right, every parent node is greater than or equal to child nodes (max-heap), AND left-children are less than their parents.


**2) A binary search tree is considered an ordered or sorted binary tree. Given a binary search tree, explain how you would print out all of the values in the binary tree in sorted order. What is the complexity of this process in terms of Big O?**

Since the tree is sorted, we would want to traverse it such that left-child nodes get processed before parent nodes before right child nodes. This can be implemented recursively through an in-order traversal. The algorithm is simple: first check if the current node is empty or null, keep recursively traversing the left subtree to its furthest point and display the value, then traverse the right subtree recursively and display values. The complexity of this search on a BST is O(n) since each node is visited. 


**3) A binary search trees is often used to implement the set and map abstract data types. Identify the average and worst case time complexities in terms of Big O for the following set operations:**

- **Search: ** Avg: O(logN)   Worst: O(n)

- **Insert: ** Avg: O(logN)   Worst: O(n)

- **Remove: ** Avg: O(logN)   Worst: O(n)

**Why are the average and worst case time complexities different?**

Worst case complexities assume an inordinately unbalanced tree and thus traverse down N nodes where the action occurs at the last node. Average case understands that trees are binary and thus have two child nodes for each parent and can halve the number of node possibilites with each step, assuming the tree is somewhat built how it should be (with the median value for instance at the root--well-balanced).


**4) B-Trees are often used in databases such as CouchDB, SQL Server, MongoDB, and SQLite. Explain how B-Tree is different from a binary search tree and how these differences make it an attractive data structure for implement large data storage systems.**

B-trees can have more than one child node and maintain self-balancing. It is similar to binary search trees in that it keeps elements in a sorted order for sequential traversal. B-trees were designed for larger yet slower data-access applications--on-disk data. A major advantage is that while a BST needs two pointers for each record, a B-tree needs just one. B-tree memory blocks are only partially full however, but usually about 75%. Keys and pointers are clustered in memory, offering better cache behavior. This also means the amount of comparisons required to reach a key is low, which is important for speed when accessing slow on-disk data.
