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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx)
    {
        if(start > end)
            return NULL;
        
        int rootVal = preorder[idx];
        int i = start;

        for(;i <= end;i++){
            if(inorder[i] == rootVal)
                break;
        }

        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start,i - 1, idx);
        root->right = solve(preorder, inorder, i + 1,end,idx);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder,0, n- 1, idx);
    }
};
