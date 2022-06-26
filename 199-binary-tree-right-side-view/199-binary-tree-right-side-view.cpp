/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 1. Understanding
        // Input: root node contains left and right child
        // Output: array of integers that are value of nodes.
        // Constraints: 
        //          input null => empty array
        //          input contains no child => return the element
        // Testcases:
        // 2. Matching
        //          Tree traversal problems
        //          Which one to use? DFS? BFS?
        // 3. Planning
        //          BFS: Check only the current level. Scan from left to right, and find out the right-most node of the level
        
        
        queue<queue<TreeNode*>> mainQueue;
        vector<int> arr;
        
        // BaseCase
        if(!root)return arr;
        
        // Initialize the mainQueue
        queue<TreeNode*> tq;
        tq.push(root);
        mainQueue.push(tq);
        
        // Initializing the arr
        arr.push_back(root->val);
        
        // BFS: Searches from left to right => 
        //          keep update the node until reaches the end of each level. 
        //          The logic will automatically pick the rightmost node for the level.
        while(!mainQueue.empty()){
            queue<TreeNode*> polledQueue = mainQueue.front();
            queue<TreeNode*> nextQueue;
            int rightMostVal = 0;
            bool hasChild = false;
            mainQueue.pop();
            
            while(!polledQueue.empty()){
                TreeNode* node = polledQueue.front();
                polledQueue.pop();
                
                // Look up for the left node first. The order matters
                if (node->left) {
                    hasChild = true;
                    nextQueue.push(node->left);
                    rightMostVal = node->left->val;
                }
                if (node->right) {
                    hasChild = true;
                    nextQueue.push(node->right);
                    rightMostVal = node->right->val;
                }
            }
            
            // Push nextQueue
            // I am not pushing an empty queue. 
            // So if all nodes on the same level are null, the loop will not run and rightMostVal will not be pushed to arr.
            if (!nextQueue.empty()) mainQueue.push(nextQueue);
            
            // Update the rightmost value for the current level
            if (hasChild){
                arr.push_back(rightMostVal);
            }
            hasChild = false;
        }
        return arr;
    }
};