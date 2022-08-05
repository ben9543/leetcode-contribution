class Solution {
public:
	
	// GLobal variable to keep track of maximum diameter calculated.
    int maxDia = 0;
	
	
    int diameterOfBinaryTree(TreeNode* root)
    {
		// Calling our new modified height of tree function.
		// This function will return height of tree but we are not using it's returned value as we are not intrested in getting height of tree.
        heightModified(root);
        return maxDia-1;
    }
    
	
	// This modified height function will return height of tree like normal height function but will also keep update of maxDia value.
    int heightModified(TreeNode* root)
    {
		// If root is null, Height is zero.
        if(root==NULL)
            return 0;
        
		// Get left subtree height & store it in a variable.
        int leftHt = heightModified(root->left);
		
		// Get right subtree height & store it in a variable.
        int rightHt = heightModified(root->right);
        
		// This is the only extra line added in function of finding height of a tree. 
		// Diameter of tree is left tree height + right tree height + 1 for counting current node in it.
        maxDia = max(maxDia, leftHt + rightHt + 1);
        
		
		// Return max of left & subtree height + 1 to return current node's height.
        return max(leftHt, rightHt) + 1;
    }
};