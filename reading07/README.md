Reading 07
==========

Michael McRoskey
----------------

---

**1) In the context of hash tables, what is the purpose of a hash function? That is, what is is used for?**

A hash function is used to quickly compute an array index of the location of a specific value stored in the array. It elegantly maps a key value to a position. The array itself can of course hold objects or pointers to linked lists. A hash function can be as simple as using a primary operator on an integer value or performing complex calculations on a string of characters. It's important that a hash function attempts to avoid creating collisions, however, when two keys map to the same value. Also, the best hash functions avoid the worst case scenario of every key mapping to the same value by accomplishing a uniform distribution.

**2) In the context of hash tables, what exactly is a collision? How are collisions handled in a hash table that uses separate chaining?**

Collisions occur when two keys hash to the same index. For instance, in a primative hash function that stores each word in a book to an index based on the letter of the alphabet each word starts with, "bob" and "burger" would of course be hashed to the same array value, data[1]...assuming a -> data[0]. Thus a collision occurs since two values have the same key. The more elegant appraoch to resolving collisions is to implement separate chaining, where each array element is actually the head pointer to a linked list. Thus, in my example, data[1] would actually point to a B-letter linked list where each node stores a b-word. To find a value, you would have to cycle through the list though.

**3) In the context of hash tables, what constitutes a good hash function? That is, what sort of properties would we want in the hash function used in our implementation of a hash table?**

A good hash function must always generate the same value for a specific input, so in most cases shouldn't rely on a random seed like time, for instance. It should also map inputs uniformly across an output range (and so reduce the chance of collisions). An added feature might be data normalization, where you standardize phone number input or capitalization, for example. There are pretty stark differences between the hash functions that are useful to programmers and cryptographic hash functions but something else that's important to us is an equal liklihood that slightly differing inputs will get separate values. Finally for cryptographic functions, it's important to have a more or less "one-way function" so that it's practically non-invertible (think cracking passwords).

**4) For a hash table using separate chaining (ie. with lists for buckets), identify the average and worst case time complexities in terms of Big O for the following set operations. If the average and worst case time complexities are different, then explain the reason for the difference.**

	| Function | Best | Average | Worst |
	|----------|------|---------|-------|
	| Search   | O(1) | O(1)    | O(N)  |
	| Insert   | O(1) | O(1)    | O(1)  |
	| Delete   | O(1) | O(1)    | O(N)  |
	
	The average and worst differ because the worst case assumes every key hashes to the same location in the table, i.e. the same linked list, and the function has to traverse the list. In the search case, it might finally find the value at the very last element in that list. In the insert case, I assumed we could insert a node at the front of the list for a total complexity of O(1). Finally, deleting by value means first finding the value, which might be the last element in a linked list.
	