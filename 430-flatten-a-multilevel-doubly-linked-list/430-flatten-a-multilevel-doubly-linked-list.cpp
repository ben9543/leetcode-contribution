/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* root = head;
        while(root){
            // cout << head->val << endl;
            Node* nextNode = root->next;
            if (root->child){
                merge(root, root->next, root->child);
                root->child = nullptr;
            } else {
                root = nextNode;
            }
        }
        return head;
    }
    void merge(Node* curr, Node* next, Node* child){
        
        // Attach curr and child
        curr->next = child;
        child->prev = curr;
        
        while(child->next){
            //cout << child->val << endl;
            if (child->child){
                merge(child, child->next, child->child);
                child->child = nullptr;
            }
            child = child->next;
        }

        // Attach child and next(tail)
        child->next = next;
        if (next){
            next->prev = child;  
        }
    }
};