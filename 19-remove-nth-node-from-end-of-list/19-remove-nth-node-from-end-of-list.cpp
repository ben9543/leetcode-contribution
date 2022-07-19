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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Understanding
        //      Remove the nth node from the behind
        //      Edge case
        // 2. Matching
        // 3. Planning
        //      Brute force O(n)
        //      - Move one pointer by n times
        //      - Move two pointers at the same time until the first pointer reaches to the end
        //      - It is guaranteed that n is at most the length of the list.


        ListNode* start = new ListNode();
        start->next = head;
        ListNode* aptr = start;
        ListNode* bptr = start;
        ListNode* prev = start;
        
        if(head->next == nullptr){
            return nullptr;
        }
        while(n-1){
            aptr = aptr->next;
            n--;
        }
        while(aptr->next){
            prev = bptr;
            aptr = aptr->next;
            bptr = bptr->next;
        }
        // Remove the next node
        ListNode* d = prev->next;
        prev->next = prev->next->next;
        d->next = nullptr;
        ///delete d;
        //prev->next = nullptr;
        //delete start;
        return start->next;
    }
};