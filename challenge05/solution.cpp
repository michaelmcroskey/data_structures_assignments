// Challenge 05: BST

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

//bool recursive(vector<int> v, int root, int min, int max){
//	
//	bool bst = false;
//	
//	if (root == (v.size()-1)/2) return true;
//	
//	// left and right indexes
//	int parent = v.at(root);
//	int L = v.at(2*root+1);
//	int R = v.at(2*root+2);
//	
//	return bst;
//}

/* Given a binary tree, print its nodes in inorder*/
bool inorder(vector<int> v, int root, vector<int> ordered){
		
	cout << root << " " << (v.size()/2)-1 << endl;
	if (root == (v.size()/2)-1)
		return false;
		
	// left and right indexes
	int parent = v.at(root);
//	int L = v.at(2*root+1);
//	int R = v.at(2*root+2);

	// create in-order traversed vector
	inorder(v, 2*root+1, ordered);
	ordered.push_back(parent);
	inorder(v, 2*root+2, ordered);
	
	// check if it is sorted
	return std::is_sorted(ordered.begin(), ordered.end());
}

// Main Execution

int main() {
   
	int N = 0, tree=1, temp;
	bool bst = false;
	
	while (cin >> N) {
		// initialize array
		vector<int> v;
		
		// load values into array
		for (int i=0; i<N; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		for (int root=0; root<N/2; root++) {
			// left and right indexes
			int parent = v.at(root);
			int L = v.at(2*root+1);
			int R = v.at(2*root+2);
			
			// if blank node, ignore it
			if (parent == -1) continue;
			if (root!=N/2){
				if (L == -1) continue;
				if (R == -1) continue;
			}
			
			// check left child
			if (L > parent){
				bst = false;
				break;
			// check right child
			} else if ((root != N/2) && (R < parent)){
				bst = false;
				break;
			// if everything passes, good to go
			} else {
				bst = true;
			}
		}
		
		for (int i=0; i<v.size(); i++)
			cout << v.at(i) << " ";
		cout << endl;
		
		if (bst){
			vector <int> ordered;
			bst = inorder(v, 0, ordered);
		}
		
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
