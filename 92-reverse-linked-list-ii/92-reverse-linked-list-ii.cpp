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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        
        ListNode *currNode = head, *startNode = head, *nextNode;
        
        // Node number start from 1
        int currentPos = 1;
        
        while (currentPos < left){
            startNode = currNode;
            currNode = currNode->next;
            currentPos++;
        }
        ListNode *newList, *tail = currNode;
        
        while (currentPos >= left && currentPos <= right){

            nextNode = currNode->next;
            currNode->next = newList;
            newList = currNode;
            currNode = nextNode;
            
            currentPos++;
        }
        
        startNode->next = newList;
        tail->next = currNode;
        
        if (left > 1)
            return head;
        else
            return newList;
    }
};