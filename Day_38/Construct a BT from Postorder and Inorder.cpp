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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end, int &idx)
    {
        if(start > end)
            return NULL;
        
        int rootVal = postorder[idx];
        int i = start;

        for(;i <= end;i++){
            if(inorder[i] == rootVal)
                break;
        }

        idx--;

        TreeNode* root = new TreeNode(rootVal);
        root->right = solve(postorder, inorder, i + 1,end,idx);
        root->left = solve(postorder, inorder, start,i - 1, idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //your code goes here
        int n = postorder.size();
        int idx = n-1;
        return solve(postorder, inorder,0, n- 1, idx);
    }
};
