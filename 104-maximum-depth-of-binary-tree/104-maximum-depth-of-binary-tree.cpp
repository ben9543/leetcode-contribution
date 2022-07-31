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
    int maxCount = 0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        DFS(root, 0);
        return maxCount;
    }
    
    void DFS(TreeNode* root, int count){
        if(!root){
            // update the maxCount
            maxCount = max(count, maxCount);
        } else {
            count++;
            DFS(root->left, count);
            DFS(root->right, count);
        }
    }
};