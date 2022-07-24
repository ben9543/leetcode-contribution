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
    vector<double> averageOfLevels(TreeNode* root) {
        
        // Initial set up
        queue<TreeNode*> mainQ;
        vector<double> res;
        mainQ.push(root);
        
        while(!mainQ.empty()){
            
            // Poll everything in mainQ
            queue<TreeNode*> subQ;
            long long int sum = 0;
            int count = 0;
            double avg = 0;
            while(!mainQ.empty()){
                
                // Poll
                TreeNode* curr = mainQ.front();
                mainQ.pop();
                
                // Get sum
                sum += curr->val;
                
                // Increase count
                count++;
                
                // Push all nodes in the next level
                if(curr->left)subQ.push(curr->left);
                if(curr->right)subQ.push(curr->right);
            }
            
            // Get the average
            avg = ((double)sum/count);
            res.push_back(avg);
            
            // Update the mainQ
            mainQ = subQ;
        }
        
        return res;
    }
};