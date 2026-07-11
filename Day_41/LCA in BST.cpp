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
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        //your code goes here
            if(!root)
                return NULL;
            
            int curr = root->data;

            if(p > curr && q > curr)
            {
                return lca(root->right,p,q);
            }
            if(p < curr && q < curr)
            {
                return lca(root->left,p,q);
            }
            return root;
		}
};
