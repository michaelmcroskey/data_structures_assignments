// Challenge 07: Linked List Deduplication
// Michael McRoskey

#include <iostream>
#include <memory>
#include <unordered_set>

using namespace std;

// Structures

class MyList{
    
    struct Node{
        int data;
        Node *next;
    };
    
    public:
        MyList(){
            head = nullptr;
        }
        
        ~MyList(){
            Node *next = nullptr;
            for (Node *curr = head; curr != nullptr; curr = next) {
                next = curr->next;
                delete curr;
            }
        }
        
        void insert(int value){
            
            Node *node = new Node;
            node->data = value;
            node->next = nullptr;
            
            if (head == nullptr){    // if first node
                head = node;
            } else {
                Node *curr = head;
                while(curr) {
                    if(curr->next == nullptr) {
                        curr->next = node;
                        return;
                    }
                    curr = curr->next;
                }
            }  
        }
        
        Node* remove(Node *old, Node *before_it){
            if (old == nullptr){
                throw std::out_of_range("invalid iterator");
            }
          
            // remove first node
            if (head == old){
                head = head->next;
                delete old;
                return head;
                
            // remove last node
            } else if (old->next == nullptr) {
                before_it->next = nullptr;
                delete old;
                return before_it;
                
            // remove middle node
            } else {         
                before_it->next = old->next;
                delete old;
                return before_it;
            }

        }
        
        void deduplicate(){
            unordered_set<int> s;
            Node *curr = head;
            Node *before_it = head;
            
            while (curr) {
                
                bool not_in_set = (s.find(curr->data) == s.end());
                
                if (not_in_set){        // not found, so insert to set
                    s.insert(curr->data);    
                } else {                // found, so remove from list
                    curr = remove(curr, before_it);
                }
                
                before_it = curr;
                curr = curr->next;
            }
        }
        
        void display(){
            Node *curr = head;
            bool first_pass = true;
            while(curr != nullptr){
                if (first_pass){
                    cout << curr->data;
                    curr = curr->next;
                    first_pass = false;
                    continue;
                }
                cout << " " << curr->data;
                curr = curr->next;
            }
        }

    private:
        Node *head;
};

// Main Execution

int main(int argc, char *argv[]) {
    
    int N, x;
    bool first_pass = true;
    
    while(cin >> N){
        MyList l;
        for (int i=0; i<N; i++){
            cin >> x;
            l.insert(x);
        }
        l.deduplicate();
        if (first_pass){
            l.display();
            first_pass = false;
        } else {
            cout << endl;
            l.display();
        }
    }
    cout << endl;
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
