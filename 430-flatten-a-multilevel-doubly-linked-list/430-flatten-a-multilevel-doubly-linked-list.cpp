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
            Node* nextNode = root->next;
            /*  ERROR here was:          
            if (root->child){
                merge(root, root->next, root->child);
                root->child = nullptr;
            } 
            root = nextNode; => This made the loop to skip when the input is [1,null,2,null,3,null] (only connected with child)
            */
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
        // The conditional statement is to check next is null or not
        if (next){
            child->next = next; // does not matter if this is outside or not
            next->prev = child;  
        }
    }
};