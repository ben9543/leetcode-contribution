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
    int kthSmallest(TreeNode* root, int k) {
        // Understanding
        // left node is strictly less than its parent
        // As the root move to the left node, 
        
        // We can create a min heap
        // Since the default is maxheap, we are going to multiply -1 for each element
        priority_queue<int> pq;
        DFS(root, pq);
        while(k-1){
            cout << pq.top() * (-1) <<endl;
            pq.pop();
            k--;
        }
        return pq.top() * (-1);
    }
    void DFS(TreeNode* root, priority_queue<int>& pq){
        if(!root)return;
        DFS(root->left, pq);
        pq.push(root->val * (-1) );
        DFS(root->right, pq);
    }
};