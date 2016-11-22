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
        
        bool first_pass = true;
        
        for (auto j : i.second){
            if (first_pass){
                first_pass = false;
            } else {
                cout << " ";
            }
            cout << j;
        }
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
