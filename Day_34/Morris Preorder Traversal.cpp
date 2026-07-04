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
		vector<int> preorder(TreeNode* root){
	       //your code goes here
           vector<int> preorder;
           TreeNode* curr = root;

           while(curr)
           {
                if(curr->left == NULL)
                {
                    preorder.push_back(curr->data);
                    curr = curr->right;
                }
                else
                {
                    TreeNode* prev = curr->left;

                    while(prev->right && prev->right != curr)
                        prev = prev->right;
                    
                    if(prev->right == NULL){
                        prev->right = curr;
                        preorder.push_back(curr->data);
                        curr = curr->left;
                    }
                    else
                    {
                        prev->right = NULL;
                        curr = curr->right;
                    }
                }
           }
           return preorder;
		}
};
