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
    TreeNode* build(vector<int> &preorder,int &index, int bound)
    {
        if(index == preorder.size() || preorder[index] > bound)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, root->data);
        root->right = build(preorder, index, bound);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //your code goes here
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
