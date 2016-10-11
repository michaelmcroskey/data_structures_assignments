// Challenge 05: BST

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <math.h>

using namespace std;

bool recursive(vector<int> v, int root, int min = -1, int max = -1){
	
	// initialize bst
	bool bst = false;
	
	// don't go out of bounds
	if (root >= v.size()) return !bst;
	
	// parent index
	int parent = v.at(root);
	// skip null nodes
	if (parent < 0) return !bst;
	
	//-------Verify BST----------//
	// ensure minimums and maxes are correct
	bool badMin = (parent <= min && min > 0);
	bool badMax = (parent > max && max > 0);
	
	if (badMin || badMax) return bst;
	
	// L/R indexes
	int L = 2*root+1;
	int R = 2*root+2;
	
	// Left: keep current min and set max to parent
	bool recurseLeft = recursive(v, L, min, parent);
	
	// Right: keep current max and set min to parent
	bool recurseRight = recursive(v, R, parent, max);
	
	// make sure both conditions are true
	bst = recurseLeft && recurseRight;
	
	return bst;
}

// Main Execution

int main() {
   
	int N=0, tree=1, temp, root=0;
	bool bst = false;
	
	while (cin >> N) {
		// initialize array
		vector<int> v;
		
		// load values into array
		for (int i=0; i<N; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		// Fill out rest of tree with empty nodes
//		for (int i=0; i<N; i++)
//			v.push_back(-1);
		
		// 1st attempt: iterative
		// 2nd attempt: recursive
		bst = recursive(v, root);
		
		// output result
		if (bst){
			cout << "Tree " << tree << " is a BST" << endl;
		} else {
			cout << "Tree " << tree << " is not a BST" << endl;
		}
		
	tree++;
	bst = false;
	v.clear();
	}

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
