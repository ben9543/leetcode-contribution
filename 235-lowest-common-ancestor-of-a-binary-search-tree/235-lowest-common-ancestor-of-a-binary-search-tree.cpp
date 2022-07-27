/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // 1. Understanding
        //  Cases: If p is smaller than root and q is greater than root => the root node will be the answer
        //         If p & q are both smaller than the root => recursive call with left tree
        //         If p & q are both bigger than the root => recursive call with right tree
        //         Since the p & q always exist in the tree this approach will work
        
        TreeNode* smaller = p;
        TreeNode* greater = q;
        
        if(p->val > q->val){
            smaller = q;
            greater = p;
        }
        return helper(root, smaller, greater);
    }
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val > root->val || p->val == root->val || q->val == root->val)
            return root;
        else if(p->val < root->val && q->val < root->val)
            return helper(root->left, p, q);
        else
            return helper(root->right, p, q);
    }
};