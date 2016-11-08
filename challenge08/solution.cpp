// Challenge 08: Palindrome Permutation
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Convert to lower
string toLower(string line){
    for (int i=0; i<line.length(); i++){
        line[i] = tolower(line[i]);
    }
    return line;
}

// Lowercase, remove whitespace, punctuation, numbers
string clean(string line){
    line = toLower(line);
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); 
    line.erase(remove_if(line.begin(), line.end(), ::ispunct), line.end()); 
    line.erase(remove_if(line.begin(), line.end(), ::isdigit), line.end());
    return line;
}

// Checks if number is odd
bool isOdd (int n) {
    if (n % 2 == 0) return false;
    else return true;
}

bool is_palindrome(string a){
    
    unordered_map<char, int> counts;
    int size = a.length();
    
    // Create map with counts of each digit
    for (int i=0; i<size; i++){
        bool found = (counts.find(a[i]) != counts.end());
        
        if (found){
            counts.at(a[i]) += 1;
        } else {
            counts.insert({a[i], 1});
        }
    }
    
    // Find how many times a char occurs odd # times
    int oddCount = 0;
    for (auto i : counts){
        if (isOdd(i.second)) oddCount++;
    }
    
    // Odd-length strings allow just 1 occurrence of unique character
    if (oddCount == 1 && isOdd(size)) return true;
    // Even-length strings don't allow unique character
    else if (oddCount == 0 && !isOdd(size)) return true;
    
    // Otherwise, not a palindrome permutation
    return false;
}

// Main Execution

int main(int argc, char *argv[]) {
    
    string line;
    string output = " a palindrome permutation";
    
    while (getline(cin, line)){
        
        string a = clean(line);
        
        if (is_palindrome(a)){
            cout << "\"" << line << "\" is" << output << endl;
        } else {
            cout << "\"" << line << "\" is not" << output << endl;
        }
    }
 
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
