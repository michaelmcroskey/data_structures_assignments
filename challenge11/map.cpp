// map.cpp: inverted index
// Michael McRoskey

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// FUNCTIONS  ---------------------------------------------
string clean(string s){
    for (int i=0; i<s.length(); i++)
        s[i] = tolower(s[i]);
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end()); 
    s.erase(remove_if(s.begin(), s.end(), ::isdigit), s.end());
    return word;
}

// MAIN EXECUTION  ----------------------------------------
int main(int argc, char *argv[]) {
    
    map<string, int> m;
    int line_number = 1;
    std::string line;
    
    // LINE-BY-LINE --------------------------------------
    while (std::getline(std::cin, line)){
        
        // PARSE INPUT -----------------------------------
        string word;
        stringstream ss(clean(line));
        vector<string> words;
        while (ss >> word)
            words.push_back(word);
        
        // OUTPUT VECTOR ---------------------------------
        for (auto i : words)
            cout << i << "\t" << line_number << endl;
        line_number++;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
