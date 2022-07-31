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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int diff = abs(treeHeight(root->left) - treeHeight(root->right));
        if (diff <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        } else {
            return false;
        }
    }
    
    int treeHeight(TreeNode* root){
        if (!root) return 0;
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }
};