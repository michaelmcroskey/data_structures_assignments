// Challenge 09: Graph Paths
// Michael McRoskey

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

using namespace std;

bool valid_path(unordered_map<char, unordered_set<char>> map, char n1, char n2){
    return map[n1].count(n2) > 0;
}

// Main Execution

int main(int argc, char *argv[]) {
    
    int NEDGES, NPATHS, graph = 1;
    bool path;
    
    // Each Graph --------------------------------
    while (cin >> NEDGES){
        
        // Build Graph ---------------------------
        unordered_map<char, unordered_set<char>> map;
        char A, B;
        
        for (int i=0; i<NEDGES; i++){
            cin >> A >> B;
            // Element not in graph, insert
            if (map.find(A) == map.end()){
                unordered_set<char> set;
                set.insert(B);
                map.insert({A, set});
                
            // Element in graph, update connected nodes
            } else {
                map.find(A)->second.insert(B);
            }
            
            // Recursively add connected nodes
            for (auto node : map){
                for (auto connected_node : node.second){
                    
                    // Should be a set?
                    auto myset = map.find(connected_node)->second;
                    
                    for (auto i : myset){
                        node.second.insert(i);
                    }
                    // For each node, add connected nodes
                    //node.second.insert(myset.begin(), myset.end());

                    //cout << typeid(map.find(connected_node)->second).name() << endl;
                    //(map.find(node.first)->second).insert(map.find(connected_node)->second);
                }
            }
        }
        
        // Store Paths ---------------------------
        cin >> NPATHS;

        for (int i=0; i<NPATHS; i++){
            string not_path = " no";
            char n1, n2;
            cin >> n1 >> n2;
            
            // Check Valid Paths -----------------
            path = valid_path(map, n1, n2);
            
            // Output Results --------------------
            if (path) not_path = " a";
            
            cout << "In Graph " << graph << " there is"
                << not_path << " path from " << n1
                << " to " << n2 << endl;
        }
        
        graph++;
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
