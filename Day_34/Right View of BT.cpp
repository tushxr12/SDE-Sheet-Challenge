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
    void helper(TreeNode* root, int level, vector<int> &ans)
    {
        if(!root)
            return;
        
        if(level == ans.size())
            ans.push_back(root->data);
        helper(root->right, level + 1,ans);
        helper(root->left, level + 1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        //your code goes here
        vector<int> ans;
        helper(root,0,ans);
        return ans;
    }
};
