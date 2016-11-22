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
    if (!isalnum(s.front())) s.erase(0,1);
    if (!isalnum(s.back())) s.pop_back();
    return s;
}

void stripUnicode(string &s) {
    auto invalid = [] (int c) {return !(c>=0 && c<128);};
    s.erase(remove_if(s.begin(),s.end(), invalid), s.end());  
}

// MAIN EXECUTION  ----------------------------------------
int main(int argc, char *argv[]) {
    
    int line_number = 1;
    std::string line;
    
    // LINE-BY-LINE --------------------------------------
    while (getline(cin, line)){
        
        stripUnicode(line);
        
        // PARSE INPUT -----------------------------------
        string word;
        vector<string> words;
        stringstream ss(line);
        while (ss >> word)
            words.push_back(clean(word));
        
        // OUTPUT VECTOR ---------------------------------
        for (auto i : words)
            cout << i << "\t" << line_number << endl;
        line_number++;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
