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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // Base case
        if (!root) return false;
        if (!subRoot) return true;
        
        if(isSameTree(root, subRoot))return true;
        else return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(root && subRoot && root->val == subRoot->val)
        {
            return (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right) );
        }
        return false;
    }
};