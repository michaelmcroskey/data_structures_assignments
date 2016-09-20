// Challenge 05: BST

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <memory>

using namespace std;

// Main Execution

int main() {
   
	int N = 0, tree=1;
	bool bst = false;
	
	while (1) {
		
		int c = std::cin.peek();  // peek character
		if (c == EOF) break;

		cin >> N;
		int a[N];
		
		for (int i=0; i<N; i++) {
			cin >> a[i];
		}
		
		for (int i=0; i<N/2; i++) {
			if (a[i] == -1) continue;
			if (a[2*i+1] == -1) continue;
			if (a[2*i+2] == -1) continue;
			
			if (a[2*i+1]>a[i]){
				bst = false;
				break;
			} else if (a[2*i+2]<a[i]){
				bst = false;
				break;
			} else {
				bst = true;
			}
		}
		
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
