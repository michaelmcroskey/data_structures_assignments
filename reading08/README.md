Reading 08
==========

Michael McRoskey
----------------

---

**1) Generally, how are collisions handled in a hash table that uses open addressing? In particular, briefly explain how linear probing works when there is a collision.**

In hash tables with open addressing, collisions are handled by looking for the next available slot in the array, sometimes a specified distance away. We use linear probing such that the interval between probes is a fixed at a number like 1. So, if we attempt to store a value in bucket 8 but bucket 8 is filled, it might check and see if bucket 9 is available and store the value in there. If bucket 9 is filled, it will move on (even circling to the start of the array), and so on. This has the advantage of having good cache performance but can falter when there are a lot of values in the same bucket.

**2) In the context of hash tables, what is the load factor and how does this statistic impact performance and memory usage?**

The load factor is defined as the ratio of the number of entries over the number of buckets--it's essentially a measurement of how well-used a hash table is. It will explain why performance decreases as the load factor increases (essentially more likely to have collisions). However, this doesn't tell the whole story. For instance, a table of size 100 where all 100 entries are stored in the first bucket is not efficiently used but will have the same load factor as one where all 100 entries are evenly distributed. So in the first case there is perhaps less a chance of collisions (99% open slots, although doubtful probably given the poor prior hashing and poor use of memory) and in the second case the result is more uniform. The load factor just tries to account for performance and memory usage--a lower load factor, but not drastically low (I'm thinking in the range of 0.7 is good) shows a good balance for performance (probably not as many collisions) and memory (some free space, but not a ton).

**3) Starting with an empty hash table using open addressing (and linear probleing with an interval of 1), and using the hash function h(x) = x % 10, show the result of inserting the following values into the table:**

    h(x) = x % 10
    7, 3, 2, 78, 56, 72, 79, 68, 13, 14

| Bucket  | Value      |
|---------|------------|
| 0       | 68         |
| 1       | 14         |
| 2       | 2          |
| 3       | 3          |
| 4       | 72         |
| 5       | 13         |
| 6       | 56         |
| 7       | 7          |
| 8       | 78         |
| 9       | 79         |


**4) For a hash table using open addressing, identify the average and worst case time complexities in terms of Big O for the following set operations:**

| Function | Best | Average | Worst |
|----------|------|---------|-------|
| Search   | O(1) | O(1)    | O(N)  |
| Insert   | O(1) | O(1)    | O(N)  |
| Delete   | O(1) | O(1)    | O(N)  |

If we assume each key gets hashed to a unique bucket, there will be no collisions and no need to probe the entire list to find an open spot (for searching, inserting, or deleting). If, however, every key gets hashed to the same bucket, each insertion will linearlly travel one more space each time...until we reach a blank spot in the array which is getting further and further--up to N spaces away.
