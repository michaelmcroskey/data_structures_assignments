// reduce.cpp: inverted index

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// MAIN EXECUTION  ------------------------
int main(int argc, char *argv[]) {
    
    map<string, set<int>> m;
    string word;
    int line;
    
    // LINE-BY-LINE------------------------
    while (cin >> word >> line)
        m[word].insert(line);
    
    // OUTPUT RESULTS ---------------------
    for (auto i : m){
        cout << i.first << "\t";
        
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
