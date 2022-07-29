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
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        
        // Getting the mid
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split and reverse the right partition
        // [1->2->3 -> null | () <-  4 <- 5]
        //        s                       p     t
        
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        ListNode* next = nullptr;
        slow->next = nullptr;
        
        // Reverse
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Merge
        ListNode* start = head;
        ListNode* second = prev;
        ListNode* tmp1;
        ListNode* tmp2;
        while(second){
            tmp1 = start->next;
            tmp2 = second->next;
            start->next = second;
            second->next = tmp1;
            start = tmp1;
            second = tmp2;
        }
    }
};