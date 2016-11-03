// Challenge 06: Lowest Common Ancestor
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* FindLCA(Node* root, int a, int b){
    int min, max, curr;

    if (a==b) return root;
    if (a>b){
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    
    while (1){
        curr = root->data;
        if ((curr > min) && (curr > max)){
            root = root->left;
        } else if ((curr < min) && (curr < max)){
            root = root->right;
        } else {
            return root;
        }
    }
    
    return root;
}

Node* Insert(Node *root, char data){
    if(root == NULL){
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    } else if(data <= root->data){
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

void deleteTree(Node* root){
    if(root==NULL) 
        return;
    if(root->left != NULL)
        deleteTree(root->left);
    if(root->right != NULL)
        deleteTree(root->right);
    delete root;
    return;
}

int main (){
    
    int N, P, value, a, b;
    bool first_pass = true;
    vector<int> pairs;
    
    while (cin >> N){
        Node* root = NULL;
        // Exit at sentinel value
        if (N==-1) break;
        
        // Create tree
        for (int i=0; i<N; i++){
            cin >> value;
            root = Insert(root, value);
        }
        
        // Store pairs
        cin >> P;
        for (int i=0; i<P; i++){
            cin >> a >> b;
            pairs.push_back(a);
            pairs.push_back(b);
        }
        
        // Find LCA of each pair
        if(!first_pass)
            cout << endl;
        for (int i=0; i<(2*P); i+=2){
            a = pairs.at(i);
            b = pairs.at(i+1);
            
            cout << FindLCA(root, a, b)->data << endl;
        }
            
        deleteTree(root);
        root = NULL;
        pairs.clear();
        first_pass = false;
    }

}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: