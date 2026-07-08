/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {	
public:
    int func(TreeNode* root, int &maxi)
    {
        if(!root)
            return 0;
        
        int leftSum = max(0,func(root->left, maxi));
        int rightSum = max(0,func(root->right, maxi));

        maxi = max(maxi, leftSum + rightSum + root->data);

        return (root->data + max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        //your code goes here
        int maxi = INT_MIN;
        func(root, maxi);
        return maxi;
    }
};	
