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

    
    bool isValidBST(TreeNode* root) {
        // The idea for the solution:
        //      Need to set the minimum and maximum boundary
        //      1. Left node cannot be greater than the current node
        //      2. Right node cannot be smaller than the current node
        //      3. If the node is left, maximum boundary will be set up.
        //      4. If the node is right, minimum boundary will be set up.
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long long int minVal, long long int maxVal){
        if(!root)return true;

        // within the range of minval and maxval
        if(root->val <= minVal || root->val >= maxVal)return false;
        
        // root->left => should be less than root->val
        // root->right => should be greater than root->val 
        if(root->left && root->left->val >= root->val) return false;
        if(root->right && root->right->val <= root->val) return false;
         
        // Should update the left node restriction
        return (helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal));
    }
};