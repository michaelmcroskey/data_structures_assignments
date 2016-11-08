Reading 09
==========

Michael McRoskey
----------------

---

**1) Briefly explain what it means for a graph to be:**

**A. Connected:** A connected graph is one where you can get to any node via a path, in other words, there are no nodes sititng out in the middle of nowhere. There's a path between every pair of nodes.

**B. Acyclic:** An acyclic graph has no cycles, meaning you cannot cross the same node twice. Often but not always these take the form of trees.

**C. Directed:** A directed graph has edges that have a direction (one node toward another), as opposed to a simple relationhip of connection.

**D. Simple:** In a simple graph, only single, undirected edges are allowed and no loops are allowed (when a node points to itself).

**E. Weighted:** Weighted graphs give value to node edges, which is useful for finding say the fastest way to get from node A to node D (where the weight is the speed limit).


**2) Given the following graphs:**

**A. Adjacency matrices and lists:** 

    Graph 0 - Adjacency Matrix            Graph 0 - Adjacency List

       A B C
    A: 0 1 1                                A: B C
    B: 0 0 0                                B:
    C: 0 1 0                                C: B

	Graph 1 - Adjacency Matrix            Graph 1 - Adjacency List

	   A B C D
	A: 0 1 0 1                              A: B D
	B: 1 0 0 0                              B: A
	C: 1 0 0 0                              C: A
	D: 0 1 1 1                              D: B C D
	
	Graph 2 - Adjacency Matrix            Graph 2 - Adjacency List

	   A B C D
	A: 0 1 1 1                              A: B C D
	B: 1 0 1 1                              B: A C D
	C: 1 1 0 1                              C: A B D
	D: 1 1 1 0                              D: A B C

	Graph 3 - Adjacency Matrix            Graph 3 - Adjacency List

	   A B C D
	A: 0 0 0 0                              A:
	B: 0 0 0 1                              B: D
	C: 0 0 0 1                              C: D
	D: 0 1 1 0                              D: B C


**B. What is a reason for using an adjacency matrix instead of an adjacency list to represent a graph?**

An adjacency matrix is useful to find if a certain edge exists or not because it has information saying yes or no. This can lead to fast lookup times, unless you have to iterate over every edge. However, they may take up more memory as they require N^2 space complexity for N nodes regardless of if a node is connected or not. Additionally, some algorithms need to compute the eiganvalues of the adjacency matrix to compute a value.

**C. Conversely, what is a reason for using an adjacency list instead of an adjacency matrix to represent a graph?**

Adjacency lists are great if the graph is sparse, meaning it has few edges compared to nodes--it more efficiently uses memory, only holding what edges are in existence. Therefore, it's pretty quick to iterate over every edge but might have O(N) lookup for a particular edge.

**3) Given the following non-recursive implementation of depth-first search, **

**A. Complete the implementation of depth-first search by filling in the TODO sections with the appropriate C++ code.**

	struct Graph {
		map<string, set<string>> adj; // Adjacency List/Set
	};
	
	void traversal(Graph &g, const string &s) {
		stack<string> q;
		set<string>   v;
		
		string x = s;
		q.push(x);
		
		while (!q.empty()) {
			x = q.top();
			q.pop();
			if (v.find(x) != v.end())
				continue;
			cout << x << endl;
			v.insert(x);
			for (auto node : g.adj[x])
				q.push(node);
		}
	}


**B. What is the purpose of stack<string> q?**

The stack is necessary to ensure that we've processed each node we need to. Thus the while loop ends on the condition that the stack is empty. We try to process nodes last in first out becuase we are doing depth-first traversals. Thus pushing further nodes means those should be processed first.

**C. What is the purpose of set<string> v?**

The string is important to make sure we visit each node just once. As items are visited, they are put in the set. If an item has already been visited, it will not print or look for adjacent nodes. If it hasn't been visited, it will print, insert itself into the set (so that it can't be visited again), and push adjacent nodes to the stack.

**D. What would we need to change in the function to perform a breadth-first search instead of depth-first search?**

A breadth-first search would involve simply redefining q as a queue! This means nodes are processed first in first out which is exactly what we want to achieve in a breadth-first search. That way, nodes that are added are processed in the order that they are traversed.
