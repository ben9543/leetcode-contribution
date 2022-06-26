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
    int maxDepthCount = 0;
    int maxDepth(TreeNode* root) {
        
        // 1. Understanding
        // What do we return if the tree is empty? => 0
        // Multiple branches are ignored. We do not need to find every node with maximum depth, only one.
        // 2. Matching
        // Recursion => Can be break down into same sub problems
        // 3. Planning
        //  Check if there is any child (left, right)
        //      If child => Recursive call with the child node
        //      If no child => Update maxDepth
        // 4. Implementing
        if (!root) return 0;
        recur(root, 0);
        return maxDepthCount;
        
    }
    void recur(TreeNode* node, int count){
        count+=1;
        if(node->left)recur(node->left,count);
        if(node->right)recur(node->right, count);
        if(!node->left && !node->right){
            maxDepthCount = max(maxDepthCount, count);
            return;
        };
    }
};