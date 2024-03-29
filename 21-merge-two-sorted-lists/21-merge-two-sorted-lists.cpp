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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode();
        ListNode* head = prev;
        while(list1 && list2)
        {
            // If two values are the same => Insert
            if(list1->val == list2->val){
                head->next = new ListNode(list1->val);
                head = head->next;
                head->next = new ListNode(list2->val);
                head = head->next;
                list1 = list1->next;
                list2 = list2->next;
                
            // If list1 < list2 => Insert
            } else if(list1->val < list2->val){
                head->next = new ListNode(list1->val);
                head = head->next;
                list1 = list1->next;
            } else {
                head->next = new ListNode(list2->val);
                head = head->next;
                list2 = list2->next;
            }
        }
        while(list1)
        {
                head->next = new ListNode(list1->val);
                head = head->next;
                list1 = list1->next;
        }
        while(list2)
        {
                head->next = new ListNode(list2->val);
                head = head->next;
                list2 = list2->next;
        }
        return prev->next;
    }
};