Reading 04
==========

Michael McRoskey
----------------

---

**1) merge sort is the prototypical example of a divide and conquer algorithm. Explain what happens during the divide portion of the algorithm and what happens during the conquer phase.**

Divide: the algorithm finds the midpoint index of the array and divides the array in half to form two sub-arrays, recursively, until each sub-array contains one or no elements. 

Conquer: the algorithm conquers by sorts each element first at the individual level and recursively re-combines the elements in the correct order, combining sub-arrays in the same way they were divided. Each combination combines 2 times more elements in the same way the elements were divided by 2 in the divide phase. Combination sorts the elements.


**2) quick sort is another example of a divide and conquer algorithm. Explain what happens during the partitioning phase of the algorithm and why the choice of a pivot is important for efficiency.**

During partitioning, we select a pivot element such that all elements to the right of it will be greater than it and all elements to the left will be less than it. Thus, we create again two sub-arrays and will recursively create more sub-arrays within these using the same base case as merge sort--until there is just a single element. Choosing a pivot that happens to be either the maximum or minimum number is thus not very efficient since we cannot take advantage of the dual sub-array recursion on either side, instead processing a list in each recursive call just one element less than the one above it.


**3) What does it mean for a sorting algorithm to be stable?**

A sorting algorithm is stable if two elements with the same value are placed in the same respective index orders in the sorted list as in the unsorted list.

- **When would this characteristic useful?**

This is particularly useful when you have to maintain several levels of sorting. For instance (typical example, get ready for it...), if you have a list of first and last names, you could stable sort by first name first and then by last name to have a list of sorted last names. If two people had the same last name, their first names would be sorted in the correct order.

- **For merge sort and quick sort, explain whether or not the algorithm is considered stable.**

Merge sort is considered **stable** since it does nothing when elements of the same value are compared. Quick sort is **not stable** because it's arbitrary about placing elements of the same value.

**4) For merge sort and quick sort, identify the best, average, and worst case complexities of each algorithm in terms of Big O.**

Merge Sort
- Best: O(n log(n))
- Avg: O(n log(n))
- Worst: O(n log(n))

Quick Sort
- Best: O(n log(n))
- Avg: O(n log(n))
- Worst: O(n^2)

- **Considering these complexities, why do most real-world sorting (ie. C++ Sort) implementations use some form of quick sort.**

Most real-world sorting implementations use quick sort because of memory-access improvements (more localized comparisons) and because we can often avoid the worst case complexity by picking a proper pivot (very good chances when picked even at random).
