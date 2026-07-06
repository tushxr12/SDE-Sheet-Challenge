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
private:
    int height(TreeNode* root, int &diam)
    {
        if(!root)
            return 0;
        
        int lh = height(root->left, diam);
        int rh = height(root->right, diam);

        diam = max(diam, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
        int diam = 0;
        height(root, diam);
        return diam;
    }
};
