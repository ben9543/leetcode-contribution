/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. Reverse the nodes as slow pointer moves forward
        //      edge case: What if the node has odd number of nodes
        //      [1,2,3,4,5]
        //      The way to figure out if the number of nodes is odd or even 
        //          => If fast pointer's next exists => even
        //          => If fast pointer's next does not exists => odd
        //      edge case: when the list has only one node => true (2 does not matter)
        
        ListNode* dummy = new ListNode();
        ListNode* slowPrev = dummy, *slow = head, *slowNext = slow, *fast = head;
        dummy->next = head;
        bool isOdd = false;
        
        while(fast){
            
            // Move fast forward
            if(fast->next){
                fast = fast->next->next;
            }else{
                fast = fast->next;
                isOdd = true;
            }

            // Reverse slow
            slowNext = slow->next;
            slow->next = slowPrev;
            slowPrev = slow;
            slow = slowNext;
        }
        
        // Detach dummy node
        head->next = nullptr;
        delete dummy;
    
        if(isOdd){
            slowPrev = slowPrev->next;
        }

        while(slowPrev && slow){
            if (slow->val != slowPrev->val) return false;
            slowPrev = slowPrev->next;
            slow = slow->next;
        }
        

        return true;
    }
};