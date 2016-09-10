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
void write_vector(const vector<T>& V){
    for(int i=0; i < V.size()-1; i++)
        cout << V[i] << " ";
    cout << V[V.size()-1]<< endl;
}

int main()
{
    vector<int> values, closest, i_closest, signs;
    bool firstline = true;
    string line;
    int N;
    
    //-------------Gather/Parse Input-------------//
    //      push_back values into int vector      //
    while (getline(std::cin, line)){
        if (line.empty()) continue;
        
        if (firstline) {
            N = stoi(line);
            firstline = false;
            continue;
        }
        
        istringstream iss(line);
        copy(istream_iterator<int>(iss),
             istream_iterator<int>(),
             back_inserter(values));
        
        // duplicate values for later
        signs = values;
        
        //-------------Sort Vector/Array--------------//
        //   first convert to abs-val and then sort   //
        
//        for (size_t i=0; i != values.size(); ++i){
//            values[i] = abs(values[i]);
//        }
        
        sort(values.begin(), values.end());
        
        //------------Find Closest Numbers------------//
        // compute each difference and store indexes  //
        int min = values[values.size()-1], diff;
        
        // Find the minimum difference
        for (size_t i=0; i < values.size()-1; i++){
            diff = values[i+1] - values[i];
            if (diff <= min){
                min = diff;
            }
        }
        
        // Store indexes of numbers with min differences
        for (size_t i=0; i < values.size(); i++)
            if (values[i+1] - values[i] == min)
                i_closest.push_back(i);
        
        // Populate vector with all closest numbers
        for (size_t i=0; i < i_closest.size(); i++){
            closest.push_back(values[i_closest[i]]);
            closest.push_back(values[i_closest[i]+1]);
        }
        
        //-------------Account for Signs--------------//
        //   check each element for the proper sign   //
        
        for (size_t i=0; i < closest.size()-1; i+=2){
            for (size_t j=0; j < closest.size()-1; ++j){
                if (closest[i] == signs[j] || closest[i] == abs(signs[j])){
                    closest[i] = signs[j];
                }
                if (closest[i+1] == signs[j] || closest[i+1] == abs(signs[j])){
                    closest[i+1] = signs[j];
                }
            }
        }
        
        //--------------Display Results---------------//
        //     display results in closest vector      //
        
        sort(closest.begin(), closest.end());
        write_vector(closest);
        
        signs.clear();
        values.clear();
        i_closest.clear();
        closest.clear();
        firstline = true;
        line.clear();
        N=0;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: