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
    ListNode* reverseList(ListNode* head) {
        
        // currNode points wherever the current node we are working on.
        // prevNode will be the linkedlist we are going to build up.
        // nextNode is simply a storage to hold the next pointer of currNode,
        //          so that we do not lose the connection to the given  linkedlist.
        ListNode* nextNode, *prevNode = nullptr, *currNode = head;
        
        while (currNode){
            
            // 1. Move nextNode to currNode's next before we lose the connection.
            nextNode = currNode->next;
            
            // 2. Now detach currNode from nextNode, attach it to prevNode
            currNode->next = prevNode;
            
            // 3. Since currNode is now attached to prevNode, 
            // we can simply move the prevNode to its starting point, which is currNode.
            // And currNode need to be updated as nextNode for the next loop (nextNode = currNode->next)
            // The location of nextNode is not important at the point.
            // 
            // 
            //       prev   curr    next   
            //  () <- () <- ()      ()
            //
            //             prev  curr&next   
            //  () <- () <- ()      ()
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};