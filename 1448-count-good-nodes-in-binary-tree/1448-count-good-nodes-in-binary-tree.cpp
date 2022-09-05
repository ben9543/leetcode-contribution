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
    int count = 0;
    int goodNodes(TreeNode* root) {
        // Edge cases:
        //  num of nodes = 1 : return 1
        //  Root is always good node
        helper(root, root->val);
        return count;
    }
    
    void helper(TreeNode* root, int maxVal){
        if(!root)return;
        
        if(maxVal <= root->val) count++;
        maxVal = max(maxVal, root->val);
        
        helper(root->right, maxVal);
        helper(root->left, maxVal);
    }
};