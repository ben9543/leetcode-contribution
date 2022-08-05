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
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        
        if(!root)return vector<int>();
        
        while(!q.empty())
        {
            // Instead of using another queue, we can use for loop 
            TreeNode* rightMost = nullptr;
            int qLen = q.size();
            for(int i = 0; i < qLen; i++)
            {
                rightMost = q.front();
                q.pop();
                if(rightMost->left)
                    q.push(rightMost->left);
                if(rightMost->right)
                    q.push(rightMost->right);
            }
            if(rightMost)
                res.push_back(rightMost->val);
            
        }
        return res;
    }
};