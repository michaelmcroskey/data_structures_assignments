// Challenge 9 Extra Credit: Graph Partitioning

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
    
    int N;
    bool first_pass = true;
    
    // EACH GRAPH ----------------------------------
    while (cin >> N){
        
        int g[N][N];
        char a[N];
//        vector<pair<int,int>> v;
//        vector<char> non;
        map<int,set<int>> map;
        
        // INPUT DATA ------------------------------
        for (int i=0; i<N; i++)
            cin >> a[i];
        for (int row=0; row<N; row++)
            for (int col=0; col<N; col++)
                cin >> g[row][col];
        
        // PROCESS DATA ----------------------------
        int graph = 0;
        for (int row=0; row<N; row++){
            for (int col=0; col<row; col++){
                if (g[row][col] == 1){
                    
                    bool processed = false;
                    
                    // add row and col to graph that already has them
                    for (auto node : map){
                        bool found_row = node.second.find(row) != node.second.end();
                        bool found_col = node.second.find(col) != node.second.end();
                        if (found_row || found_col){
                            map[node.first].insert(row);
                            map[node.first].insert(col);
                            processed = true;    
                        }
                    }
                    if (!processed){
                        map[graph].insert(row);
                        map[graph].insert(col);
                        graph++;
                    }
                }
            }
        }
        
//        for (auto node : map){
//            cout << node.first << " :: ";
//            for (auto connected_node : node.second){
//                cout << a[connected_node] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        // OUTPUT RESULTS ---------------------------
        
        if (first_pass){
            first_pass = false;
        } else {
            cout << endl;
        }
        
        for (auto node : map){
            
            // HEADER -------------------------------
            for (auto set_item : node.second)
                cout << a[set_item] << " ";
            cout << endl;
            
            // MATRIX -------------------------------
            int size = node.second.size();
            int output[size][size];
            
            for (auto i : node.second){
                for (int row=0; row<N; row++){
                    cout << g[row][i] << " ";
                }
            }
            
            for (int row=0; row<size; row++){
                for (int col=0; col<size; col++){
                    for (auto set_item : node.second){
                        output[row][set_item] = 1;
                        output[set_item][col] = 1;
                    }
                }
            }
            
            for (int row=0; row<size; row++){
                for (int col=0; col<size; col++){
                    cout << output[row][col] << " ";
                }
                cout << endl;
            }
            cout << endl;
            
            
            
//            for (int row=0; row<node.second.size(); row++){
//                for (int col=0; col<node.second.size(); col++){
//                    bool found_row = node.second.find(row) != node.second.end();
//                    bool found_col = node.second.find(col) != node.second.end();
//                    if (found_row || found_col){
//                        cout << "1 ";
//                    } else {
//                        cout << "0 ";
//                    }
//                }
//                cout << endl;
//            }
//            cout << endl;
        }
        
//            cout << a[i.first] << a[i.second] << endl;
//            for (auto x : v){
//                if (i.first == x.first || i.first == x.second){
//                    cout << "here" << endl;
//                }
//                if (i.second == x.first || i.second == x.second){
//                    cout << "not gonna work" << endl;
//                }
//            }
//        }
        
        
        // OUTPUT DATA -----------------------------
        
        
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
//
//    5
//    a b c d e
//    0 1 0 0 0
//    1 0 0 0 0
//    0 0 0 0 1
//    0 0 0 0 0
//    0 0 1 0 0
//
//    a b
//    0 1
//    1 0
//
//    c e
//    0 1
//    1 0
//
//    d
//    0