// Challenge 03: Closest Numbers

// Michael McRoskey
// Challenge 02
// solution.cpp

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	vector<int> values, closest, i_closest;
	bool firstline = true;
	string line;
	int N;
	
	//-------------Gather/Parse Input-------------//
	//      push_back values into int vector      //	
	while (getline(std::cin, line)){
		if (line.empty()) break;
		
		if (firstline) {
			N = stoi(line);
			firstline = false;
			continue;
		}
		
		istringstream iss(line);
		copy(istream_iterator<int>(iss),
		     istream_iterator<int>(),
		     back_inserter(values));
	}
	
	vector<int> signs = values;
	
	//-------------Sort Vector/Array--------------//
	//   first convert to abs-val and then sort   //
	
	for (size_t i=0; i != values.size(); ++i){
		if (values[i] < 0){
			sign.push_back(-1);
		} else {
			sign.push_back(1);
		}
		values[i] = abs(values[i]);
	}
	
	sort(values.begin(), values.end());
	
	//------------Find Closest Numbers------------//
	// compute each difference and store indexes  //	
	int min = values[values.size()];
	int diff, index;
	
	for (size_t i=0; i != values.size()-1; ++i){
		diff = values[i+1] - values[i];
		if (diff <= min){
			min = diff;
		}
	}
	
	for (size_t i=0; i != values.size()-1; ++i)
		if (min == values[i+1] - values[i])
			i_closest.push_back(i);
	
	//-------------Account for Signs--------------//
	//   check each element for the proper sign   //
	
	
	for (size_t i=0; i < i_closest.size(); ++i){
		closest.push_back(values[i_closest[i]]);
		closest.push_back(values[i_closest[i]+1])
	}
		
	for (size_t i=0; i < closest.size(); i+=2){
		for (size_t j=0; j < closest.size(); ++j){
			if (closest[i] == signs[j] || closest[i] == abs(signs[j])){
				closest[i] = signs[j];
			}
			if (closest[i+1] == signs[j] || closest[i+1] == abs(signs[j])){
				closest[i+1] = signs[j];
			}
		}
	}
	
	//--------------Display Results---------------//
	//   display results close #1 and close #2    //	
	cout << close1 << " " << close2 << endl;
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: