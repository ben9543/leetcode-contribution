/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // oldList -> newList
        // hm[oldList->random] => [newListNode]
        unordered_map<Node*, Node*> hm;
        Node* dummy = new Node(0);
        Node* newList = dummy;
        Node* endOfList;
        Node* head_cp = head;
        
        
        
        // Generate all nodes linearly + construct hashmap
        while(head_cp)
        {
            Node* newNode = new Node(head_cp->val);
            newList->next = newNode;
            hm[head_cp] = newNode;
            head_cp = head_cp->next;
            newList = newList->next;
        }
        
        // Append NULL to newList
        newList->next = nullptr;
        endOfList = newList->next;
        
        // Now all elements in the old list are respectively pointing to the newList elements
        for(auto h : hm){
            cout << h.first << ":" << h.second <<endl;
        }
        
        // Assign head pointer to head_cp
        head_cp = head;
        
        // Assgin starting pointer of newList to newList2;
        Node* newList2 = dummy->next;
        while(head_cp)
        {
            Node* curr = hm[head_cp];
            if(head_cp->random == nullptr){
                curr->random = endOfList;
            } else {
                curr->random = hm[head_cp->random];
            }
                
            head_cp = head_cp->next;
        }
        return dummy->next;
    }
};