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
    int res;
    int maxPathSum(TreeNode* root) {
        // check left sum
        // check right sum
        // check left + right sum
        //      => Try this to every node in the tree 
        
        // How to deal with the negative => Set the lower bound check as zero   
        if(root)
            res = root->val;
        else
            return 0;
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root){
        if(!root)return 0;
        
        int leftSum = max(dfs(root->left), 0);
        int rightSum = max(dfs(root->right), 0);
        
        // root->val + leftSum + rightSum 
        // => If we stop at the current node, 
        //    this is the maximum we can get
        res = max(res, root->val + leftSum + rightSum);
        
        // We cannot do leftSum + rightSum because path cannot have two ways
        return root->val + max(leftSum, rightSum);
    }
};