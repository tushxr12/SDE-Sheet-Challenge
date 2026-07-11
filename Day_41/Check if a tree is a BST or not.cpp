/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    private:
        bool isValid(TreeNode* root, long long mini, long long maxi)
        {
            if(!root)
                return true;
            
            if(root->data >= maxi || root->data <= mini)
                return false;
            
            return (isValid(root->left, mini, root->data) && isValid(root->right, root->data, maxi));
        }
	public:
		bool isBST(TreeNode* root){
			//your code goes here
            return isValid(root, LLONG_MIN, LLONG_MAX);
		}
};
