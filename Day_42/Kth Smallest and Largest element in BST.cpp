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
    void inorder(TreeNode* root, vector<int> &values)
    {
        if(!root)
            return;
        
        inorder(root->left,values);
        values.push_back(root->data);
        inorder(root->right,values);
    }
public:
	vector<int> kLargesSmall(TreeNode* root,int k){
		//your code goes here
        vector<int> values;
        inorder(root,values);

        int kThSmallest = values[k-1];
        int kThLargest = values[values.size() - k];

        return {kThSmallest, kThLargest};
	}
};
