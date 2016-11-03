Reading 09
==========

Michael McRoskey
----------------

---

**1) Briefly explain what it means for a graph to be:**

**A. Connected:** 

**B. Acyclic:**

**C. Directed:**

**D. Simple:**

**E. Weighted:**


**2) Given the following graphs:**

**A. Adjacency matrices and lists:** 

    Graph 0 - Adjacency Matrix            Graph 0 - Adjacency List

       A B C
    A: 0 1 1                                A: B C
    B: 0 0 0                                B:
    C: 0 1 0                                C: B

	Graph 1 - Adjacency Matrix            Graph 1 - Adjacency List

	   A B C D
	A: 0 1 1 0                              A: B C
	B: 0 0 0 0                              B:
	C: 0 1 0 0                              C: B
	D: 0 0 0 0                              D: 
	
	Graph 2 - Adjacency Matrix            Graph 2 - Adjacency List

	   A B C D
	A: 0 1 1 0                              A: B C
	B: 0 0 0 0                              B:
	C: 0 1 0 0                              C: B
	D: 0 0 0 0                              D: 

	Graph 3 - Adjacency Matrix            Graph 3 - Adjacency List

	   A B C D
	A: 0 1 1 0                              A: B C
	B: 0 0 0 0                              B:
	C: 0 1 0 0                              C: B
	D: 0 0 0 0                              D: 


**B. What is a reason for using an adjacency matrix instead of an adjacency list to represent a graph?**



**C. Conversely, what is a reason for using an adjacency list instead of an adjacency matrix to represent a graph?**



**3) Given the following non-recursive implementation of depth-first search, **

**A. Complete the implementation of depth-first search by filling in the TODO sections with the appropriate C++ code.**

	struct Graph {
		map<string, set<string>> adj; // Adjacency List/Set
	};

	void traversal(Graph &g, const string &s) {
		stack<string> q;
		set<string>   v;

		// TODO

		while (!q.empty()) {
			// TODO
		}
	}


**B. What is the purpose of stack<string> q?**


**C. What is the purpose of set<string> v?**


**D. What would we need to change in the function to perform a breadth-first search instead of depth-first search?**


