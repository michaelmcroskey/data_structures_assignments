Reading 03
==========

Michael McRoskey
----------------

---

**1) Identify which of the following trees is a maximum binary heap? If a tree is not a maximum binary heap, explain why.**

In order for a binary tree to be a binary heap, it has to be complete (every level filled, except last--but must be left-to-right filled) and fit another condition: max-heaps have to have parent nodes greater than or equal to child nodes while min-heaps must have parent node less than or equal to child nodes.

Thus **A is a maximum binary heap** because:

- It is complete
- All levels filled except the last
- Last level is filled left-to-right
- Every parent node is greater than or equal to child nodes
- 18 > 14; 18 > 11; 14 > 6; ... 

Conversely, **B and C are NOT maximum binary heaps** because:

- In B: the first level right child (17) of the root node (16) is greater than its parent. 
- In C: the first level right child (27) of the root node (19) is greater than its parent.


**2) When inserting an entry into a binary heap, we must perform reheapification. What is the purpose and complexity of this process?**

Reheapification is meant to keep the integrity of the binary heap by ensuring elements get properly placed according to the rules of the binary heap. Reheapification upward occurs when you insert an element--it first gets placed in the first-available spot (lowest level, leftmost open space) and then continually swaps with its parent if it is still larger than its parent. This process has a complexity of **O(log(n))** because the tree is binary and we are moving upwards.

**3) Trace the execution of selection sort for an array containing {9, 6, 0, 0, 7}. That is show the contents of the array after each iteration of the sorting algorithm.**

    **Selection Sort**
    {9, 6, 0, 0, 7}
    {9, 6, 0, 0, 9}
    {7, 6, 0, 0, 9}
    {7, 6, 0, 7, 9}
    {0, 6, 0, 7, 9}
    {0, 6, 6, 7, 9}
    {0, 0, 6, 7, 9}

**4) Trace the execution of insertion sort for an array containing {9, 6, 0, 0, 7}. That is show the contents of the array after each iteration of the sorting algorithm.**

    **Insertion Sort**
    {9, 6, 0, 0, 7}
    {9, 9, 0, 0, 7}
    {6, 9, 0, 0, 7}
    {6, 9, 9, 0, 7}
    {6, 6, 9, 0, 7}
    {0, 6, 9, 0, 7}
    {0, 6, 9, 9, 7}
    {0, 6, 6, 9, 7}
    {0, 0, 6, 9, 7}
    {0, 0, 6, 9, 9}
    {0, 0, 6, 7, 9}
