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
        vector<ListNode*> stack;
        // 1. Understanding
        //      Testcase: [1,2,3,4,5,6,7,8] => [1, 8, 2, 7]
        // 2. Planning
        //      Use stack 
        //
        int count = 0;
        ListNode* tmp1 = head;
        while(tmp1){
            stack.push_back(tmp1);
            tmp1 = tmp1->next;
            count++;
        }
        count = floor(count/2);
        ListNode* tmp2 = head;
        while(count){
            ListNode* next = tmp2->next;
            tmp2->next = stack.back();
            cout << stack.back()->val << endl;
            stack.back()->next = next;
            tmp2 = next;
            stack.pop_back();
            count--;
        }
        tmp2->next = nullptr;
    }
};