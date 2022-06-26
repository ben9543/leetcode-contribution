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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        queue<queue<TreeNode*>> q;
        
        if (!root) return result;
        
        // Pushing the root to the queue
        queue<TreeNode*> tt;
        tt.push(root);
        q.push(tt);
        
        // Pushing to integer values to the result.
        vector<int> tv = {root->val};
        result.push_back(tv);
        
        // Using BFS
        while(!q.empty()){
            vector<int> temp;
            queue<TreeNode*> currLevel = q.front();
            queue<TreeNode*> nextLevel;
            q.pop();
            while(!currLevel.empty()){
                TreeNode* n = currLevel.front();
                currLevel.pop();
                if (n->left){
                    nextLevel.push(n->left);
                    temp.push_back(n->left->val);
                }
                if (n->right){
                    nextLevel.push(n->right);
                    temp.push_back(n->right->val);
                };
            }
            
            if (!nextLevel.empty())
                q.push(nextLevel);
            if (!temp.empty())
                result.push_back(temp);
            
        }
        return result;
    }
};