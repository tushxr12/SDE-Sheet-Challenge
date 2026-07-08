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
    bool check(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)
            return true;
        
        if(!left || !right)
            return false;

        if(left->data != right->data){
            return false;
        }

        return check(left->left,right->right) && check(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        //your code goes here😒

        if(!root)
            return true;
        
        return check(root->left, root->right);
    }
};
