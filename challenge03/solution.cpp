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

template <typename T>
void write_vector(const vector<T>& V)
{
    for(int i=0; i < V.size(); i++)
        cout << V[i] << " ";
}

int main()
{
	bool firstline = true;
	string line;
	int N;
	
	while (getline(std::cin, line)){		// read input
		if (line.empty()) break;
		
		if (firstline) {
			N = stoi(line);
			firstline = false;
			continue;
		}
		
		//string input = "-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854";
		istringstream iss(line);
		vector<string> tokens{istream_iterator<string>{iss},
	                      istream_iterator<string>{}};
	
	write_vector(tokens); // fix this scope issue
	}
	
	
    
    return EXIT_SUCCESS;
}

//------------Main Execution-------------//

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: