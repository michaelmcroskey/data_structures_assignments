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
            
            if (head == nullptr){
                Node *first = new Node;
                first->data = value;
                first->next = nullptr;
                head = first;
            } else {
                Node *newNode = new Node;
                newNode->data = value;
                newNode->next = nullptr;

                Node *curr = head;
                while(curr) {
                    if(curr->next == nullptr) {
                        curr->next = newNode;
                        return;
                    }
                    curr = curr->next;
                }
            }  
        }
        
        void remove(Node *old){
            
            if (old == nullptr){
                throw std::out_of_range("invalid iterator");
            }      
//            Node *curr = head;
            
            // If first node
            // if (old == head){} // irrelevant in this problem
            if (head == old){
                head = head->next;
                delete old;
            } else {
                Node *node = head;
                while (node != nullptr && node->next != old) {
                    node = node->next;
                }
                
                if (node == nullptr) {
                    throw std::out_of_range("invalid iterator");
                }
                
                node->next = old->next;
                delete old;
            }
//            // If last node
//            if (old->next == nullptr){
//                while (curr){
//                    if (curr->next == old){
//                        curr->next = nullptr;
//                        delete old;
//                        continue;
//                    }
//                    curr = curr->next;
//                }
//            } else {
//                Node *next = old->next;
//                while (curr){
//                    if (curr->next == old){
//                        curr->next = next;
//                        delete old;
//                        break;
//                    }
//                    curr = curr->next;
//                }
//            }
        }
        
        void deduplicate(){
            unordered_set<int> s;
            Node *curr = head;

                while (curr) {
                    bool not_in_set = (s.find(curr->data) == s.end());
                    if (not_in_set){     // not found, so insert to set
                        s.insert(curr->data);                        
                    } else {                // found, so remove from list
                        remove(curr);
                    }
                    curr = curr->next;      // increment curr to next node
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
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
