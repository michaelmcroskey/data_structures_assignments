Reading 10
==========

Michael McRoskey
----------------

---

**1) What exactly is:**

A. A Topological Sorting? What is a real world application of this?

Topological sorting is essentially a traversal of a graph bounded by certain constraints on the node order and edge weight in a directed acyclic graph. It tells us what order we can complete tasks for instance, so a Makefile is a great example of this. There are usually multiple dependencies in a Makefile (calling on library functions or certain object files that have to be created before executables, for instance). A more banal example might be a graph for the laundry cycle where washing, drying, and ironing are respective nodes--dependent on completion of the prior.

B. A Single-Source Shortest Path? What is a real world application of this?

A single-source shortest path is the shortest path from a specified node ("single-source") to every other node in a graph. It seeks to minimize the "cost" or distance traveled in the graph from that node to every other node. This is particularly relevant any time we get directions on our phones. Given our current location and that we're looking to get to a urologist, the app might compute the distance and/or time from our current location to every nearby urologist. Single-source shortest paths save lives.

C. A Minimum Spanning Tree? What is a real world application of this?

A minimum spanning tree is the undirected subgraph that touches each node in a graph with the minimum total weight possible. This might be useful for a new budget airline company trying to come up with the most cost-effective routes connecting their target cities across the nation. They might factor the cost of landing fees at each airport into edge cost and subsequently find that it's cheaper to fly LA-Austin-New York than LA-New York. Thus consumers are screwed with more layovers because it's "cheaper" to fly for the company but instead of protesting or boycotting the airline, what do the consumers do? They freaking buy the tickets! Cuz they're cheap. Indeed, minimum spanning trees are just one of the many tools in their toolbox.

**2) Given a graph, is it possible to have more than one:**

A. Topological Sorting?

Yes. The topological sort depends on the specific constraints on the sort (ie. alphabetical node ordering)

B. Single-Source Shortest Path?

Yes. If taking highway 10 and taking Broadway both take the same amount of time, then we can't really rule one out. 

C. Minimum Spanning Tree?

Yes. There can be more than one if some edges have the same weight. Thus two routes might be equally minimum.

**3) For each graph:**

A. Use Kahn's Algorithm to compute a topological sort of the nodes.

| GRAPH   | TOPOLOGICAL SORT ORDER |
|---------|------------------------|
| 0       | A, C, B, E, D, F       |
| 1       | B, D, E, C, A          |
| 2       | A, C, B, D, E, F       |
| 3       | A, C, D, B, E          |

B. Use Dijkstra's Algorithm to compute the shortest path from A to every other node.

GRAPH 0:
--------
(A, C)
(C, B)
(C, E)
(D, F)
(E, D)

GRAPH 1: (undirected)
--------
(A, B)
(B, C)
(B, D)
(D, E)

GRAPH 2: (undirected)
--------
(A, B)
(B, C)
(C, D)
(D, F)
(D, E)

GRAPH 3: (undirected)
--------
(A, B)
(B, C)
(C, E)
(E, D)

C. Use Prim's Algorithm to compute the minimum spanning tree (assume the edges are undirected).

GRAPH 0:
--------
(A, C)
(B, C)
(C, E)
(D, E)
(D, F)


GRAPH 1:
--------
(A, B)
(B, D)
(D, E)
(E, C)

GRAPH 2:
--------
(A, B)
(B, C)
(C, D)
(D, F)
(D, E)

GRAPH 3:
--------
(A, B)
(B, C)
(C, E)
(E, D)
