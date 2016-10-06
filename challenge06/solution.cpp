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

Node* FindMin(Node* root){
    while(root->left != NULL) root = root->left;
    return root;
}

Node* FindLCA(Node* root, int a, int b){
    int min, max, curr;
    bool again = true;
    if (a==b) return root;
    if (a>b){
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }
    
    while (again){
        curr = root->data;
        if ((curr > min) && (curr > max)){
            root = root->left;
            again = true;
        } else if ((curr < min) && (curr < max)){
            root = root->right;
            again = true;
        } else {
            return root;
            //if ((curr < min) && (curr < max))
        }
    }
    
    return root;
}

struct Node* Delete(struct Node *root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        // Case 1: No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        // Case 2: one child
        } else if(root->left == NULL){
            struct Node *temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL){
            struct Node *temp = root;
            root = root->left;
            delete temp;
        } else{
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(Node *root){
    if(root == NULL) return;
    Inorder(root->left);
    cout << " "<< root->data;
    Inorder(root->right);
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

int main (){
    
    int N, P, value, a, b;
    vector<int> pairs;
    Node* root = NULL;
    
    while (cin >> N){
        // Exit at sentinel value
        if (N==-1) break;
        
        // Create Tree
        for (int i=0; i<N; i++){
            cin >> value;
            root = Insert(root, value);
            //cout << "Inserted " << value << endl;
        }
        
        // Pairs
        cin >> P;
        for (int i=0; i<P; i++){
            cin >> a >> b;
            pairs.push_back(a);
            pairs.push_back(b);
        }
    }
    
    for (int i=0; i<(2*P); i+=2){
        a = pairs.at(i);
        b = pairs.at(i+1);
        
        cout << FindLCA(root, a, b)->data << endl;
    }
    
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp: