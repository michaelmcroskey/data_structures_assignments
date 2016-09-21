// Challenge 05: BST

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Main Execution

int main() {
   
	int N = 0, tree=1;
	bool bst = false;
	
	while (cin >> N) {
		// initialize array
		int a[N];
		
		// load values into array
		for (int i=0; i<N; i++) {
			cin >> a[i];
		}
		
		for (int i=0; i<N/2; i++) {
			// if blank node, ignore it
			if (a[i] == -1) continue;
			if (a[2*i+1] == -1) continue;
			if ((i!=N/2) && a[2*i+2] == -1) continue;
			
			// check left child
			if (a[2*i+1]>a[i]){
				bst = false;
				break;
			// check right child
			} else if ((i!=N/2) && (a[2*i+2]<a[i])){
				bst = false;
				break;
			// if everything passes, good to go
			} else {
				bst = true;
			}
		}
		
		// output result
		if (bst){
			cout << "Tree " << tree << " is a BST" << endl;
		} else {
			cout << "Tree " << tree << " is not a BST" << endl;
		}
		
	tree++;
	bst = false;
	}

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
