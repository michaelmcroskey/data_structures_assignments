Reading 06
==========

Michael McRoskey
----------------

---

**1) Red-Black Trees utilize rotation operations to keep the trees balanced. Explain what happens during a left rotation.**

In a left rotation, the parent node becomes a left child node of the original right child. The original right child becomes a parent node. Thus, the nodes are swaping positions in a sense, but also shifting sides. Additionally, to ensure no violations are made, each respective node must swap its color from red to black or black to red.

**2) The nodes in Red-Black Trees are colored red and black. What three invariants must Red-Black trees maintain in regards to these markings.**

- The root node must always be a black node
- You cannot have two red nodes in a row on the same path (e.g. a red parent and red child)
- Every path down the tree must have the same number of black nodes

**3) Explain how Treaps are both binary search trees and binary heaps by describing what happens when a value gets inserted into the data structure.**

Each node in a treap contains both a keys and priority value, which are used to make it this binary search tree / binary heap hybrid. Essentially, the keys follow binary search rules and the priority values follow binary heap rules. In terms of insertion, we might first insert the node based on the key value. This means we ensure it is placed to the right of nodes it is greater than and to the left of nodes it is less than as you would in a binary search tree. This often means that the heap ordering property is violated so we have to perform a rotation operation--this will still maintain the bst properties but properly move up or down nodes based on their priotiry value.

**4) For both Red-Black Trees and Treaps, identify the average and worst case time complexities in terms of Big O for the following set operations:**

Red-Black Trees

| Operation | Average  | Worst   |
|-----------|----------|---------|
| Search    | O(logN)  | O(logN) |
| Insert    | O(logN)  | O(logN) |
| Remove    | O(logN)  | O(logN) |

Treaps

| Operation | Average  | Worst   |
|-----------|----------|---------|
| Search    | O(logN)  | O(N)    |
| Insert    | O(logN)  | O(N)    |
| Remove    | O(logN)  | O(N)    |

The difference in complexity between the average and worst cases for Treaps is due to the possibility of its height being proportional to the number of keys rather than the much more likely *logarithm* of number of keys. This randomization cannot gurantee O(logN) but is usually very close.