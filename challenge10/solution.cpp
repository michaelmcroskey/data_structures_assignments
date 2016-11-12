// Challenge 10: Minimum Spanning Tree
// Michael McRoskey

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// FUNCTIONS ------------------------------------------------------
char to_char(int array_index){ return (char)(array_index+65);}
int to_int(char character){ return (int)(character-65); }

struct Edge{
    int cost;
    char name;
    char prev;
};

struct EdgeCost{
    bool operator()(const Edge& lhs, const Edge& rhs) const{
        return lhs.cost > rhs.cost;
    }
};

// MAIN EXECUTION -------------------------------------------------
int main(int argc, char *argv[]) {
    
    bool first_pass = true;
    int NVERTICES;
    
    // EACH GRAPH -------------------------------------------------
    while (cin >> NVERTICES){
        
        map<char, int> g[26];
        
        // LOAD VERTICES ------------------------------------------
        for (int i=0; i<NVERTICES; i++){
            for (int j=0; j<NVERTICES; j++){
                int cost;
                cin >> cost;
                if (cost>0){
                    g[i][to_char(j)] = cost;
                    g[j][to_char(i)] = cost;
                }
            }
        }

        int total_weight = 0;
        
        priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
        map<char, char> marked;
        
        // STARTING NODE -----------------------------------------
        frontier.push({0, 'A', 'A'});
        
        // PRIM ALGORITHM -----------------------------------------
        while (!frontier.empty()){
            Edge v = frontier.top();
            frontier.pop();
        
            if (marked.find(v.name) != marked.end())
                continue;
           
            marked[v.name] = v.prev;
            total_weight += v.cost;
            
            for (auto u : g[to_int(v.name)])
                frontier.push({u.second, u.first, v.name});
        }
           
        marked.erase(marked.find('A'));
        
        // SORT RESULTS -------------------------------------------
        vector<pair<char, char>> results;
        for (auto key : marked){
            char A = key.first, B = key.second;
            if (A<B){
                results.push_back({A,B});
            } else {
                results.push_back({B,A});
            }
        }
            
        sort(results.begin(), results.end());
        
        // OUTPUT RESULT ------------------------------------------
        if (first_pass){
            first_pass = false;
        } else {
            cout << endl;
        }
        
        cout << total_weight << endl;
        for (auto i : results)
            cout << i.first << i.second << endl;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: