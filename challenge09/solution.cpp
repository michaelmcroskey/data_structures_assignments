// Challenge 09: Graph Paths
// Michael McRoskey

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

#define UMAP unordered_map<char, unordered_set<char>>

using namespace std;

void print_map(UMAP map){
    for (auto node : map){
        cout << node.first << " :: ";
        for (auto connected_node : node.second){
            cout << connected_node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Inserts every node in path
UMAP expand_nodes(UMAP map){
    for (auto& node : map)
        for (auto connected_node : node.second)
            for (auto i : map[connected_node])
                if (i != node.first)
                    node.second.insert(i);
    return map;
}

bool valid_path(UMAP map, char n1, char n2){
    // Return if n2 is in n1's connected nodes
    return map[n1].count(n2) > 0;
}

// Main Execution

int main(int argc, char *argv[]) {
    
    int NEDGES, NPATHS, graph = 1;
    bool path, first_pass = true;
    
    // Each Graph --------------------------------
    while (cin >> NEDGES){
        
        if (first_pass){
            first_pass = false;
        } else {
            cout << endl;
        }
        
        // Build Graph ---------------------------
        UMAP map;
        char A, B;
        
        for (int i=0; i<NEDGES; i++){
            cin >> A >> B;
            // Element not in graph, insert
            if (map.find(A) == map.end()){
                unordered_set<char> set = {B};
                map.insert({A, set});
                
            // Element in graph, update connected nodes
            } else {
                map.find(A)->second.insert(B);
            }
        }
        
        // Add connected nodes -------------------
        for (size_t i=0; i<map.size(); i++){
            map = expand_nodes(map);
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
