// Challenge 10: Minimum Spanning Tree
// Michael McRoskey

#include <iostream>
#include <queue>
#include <map>

using namespace std;

// FUNCTIONS ----------------------------------------

char to_char(int array_index){ return (char)(array_index+321);}
int to_int(char character){ return (int)(character-321); }

struct Edge{
    int cost;
    char name;
    char prev;
};

struct EdgeCost{
    bool operator()(const Edge& lhs, const Edge& rhs) const{
        return lhs.cost < rhs.cost;
    }
};

// MAIN EXECUTION -----------------------------------

int main(int argc, char *argv[]) {
    
    // -1 = NONE
    
    int NVERTICES;
    
    // EACH GRAPH -----------------------------------
    while (cin >> NVERTICES){
        
        int g[26][26];
        
        // LOAD VERTICES ----------------------------
        for (int i=0; i<NVERTICES; i++)
            for (int j=0; j<NVERTICES; j++)
                cin >> g[i][j];
        
        // int total_weight;
        
        priority_queue<int, std::vector<Edge>, EdgeCost> frontier;
        map<char, char> marked;
        
        int a = g[0][0];
        size_t i = 1;
        cout << a << " "<< to_char(a) << endl;
        while (a == -1){
            cout << "i::" << i << endl;
            a = g[0][i];
            i++;
            cout << "LOOP " << a << " " << to_char(a) << endl;
        }
        
        cout << "END " << a << " " << to_char(a) << endl;
        
        //frontier.push({0, a, a});
//        
//        while (!frontier.empty()){
//            auto v = frontier.top();
//            frontier.pop();
//            
//            if (marked.find(v.name) != marked.end())
//                continue;
//           
//            marked[v.name] = v.prev;
//            for (auto u : g)
//                frontier.push({u.cost, u.name, v.name});
//            
//        }

//            while not frontier.empty():
//                v = frontier.pop()
//
//                if v.name in marked:
//                    continue
//
//                marked[v.name] = v.prev
//                for u in g.edges[v.name]:
//                    frontier.push((u.cost, u.name, v.name)) 

        
        
        // OUTPUT (DEBUG) ----------------------------
        for (int i=0; i<NVERTICES; i++)
            cout << to_char(i) << "  ";
        cout << endl;
        
        for (int i=0; i<NVERTICES; i++){
            cout << to_char(i) << " ";
            for (int j=0; j<NVERTICES; j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
