// Challenge 01: Rotating Arrays

// Michael McRoskey
// Challenge 01
// solution.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {	
	
	vector<int> array;					// create array as vector
	int n, r, val;
	char d;
	
	for (k=0; k<100; k++) {
	
		//------------Gather Input-------------//
		
		cin >> n;							// number of values
		cin >> r;							// number of rotations
		cin >> d;							// direction (R/L)
		
		// Store array
		for (int i=0; i<n; i++){
			cin >> val;
			array.push_back(val);
		}
		
		//------------Perform Shift------------//
		
		if (d=='R' || d=='r') {				// right shift
		
			for (int i=0; i<r; i++) {		// run for r rotations
				for (int j=n; j>0; j--)		// start with last element
					array[j] = array[j-1];	
				array[0] = array[n];		// replace first element
			}
			
		} else if (d=='L' || d=='l') {		// left shift
		
			for (int i=0; i<r; i++) {
				array[n] = array[0];		// replace last element
				for (int j=0; j<n; j++)		// start with first element
					array[j] = array[j+1];
			}
			
		} else {
			cout << "Error: not a valid direction." << endl;
		}
		
		//-----------Display Vector-----------//
		
		for (int i=0; i<n; i++)
			cout << array[i] << ' ';
		
	}

	return 0;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
