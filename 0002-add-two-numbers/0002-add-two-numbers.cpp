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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* res = head;
        int carry = 0;
        while(l1 || l2){
            int sum = 0;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=carry;
            if(sum >= 10){
                carry = 1;
                sum = sum%10;
            } else {
                carry = 0;
            }
            if(l1 || l2 || carry)
                res->next = new ListNode();
            res->val = sum;
            res = res->next;
        }
        if(carry){
            res->val = carry;
        }
        return head;
    }
};