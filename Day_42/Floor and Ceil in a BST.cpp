/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            vector<int> ans;
            int floor = -1, ceil = -1;
            TreeNode* temp = root;

            while(root)
            {
                if(key == root->data)
                {
                    floor = root->data;
                    break;
                }
                if(key > root->data)
                {
                    floor = root->data;
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }

            // Finding ceil
            root = temp;

            while(root)
            {
                if(key == root->data)
                {
                    ceil = root->data;
                    break;
                }

                if(key > root->data)
                {
                    root = root->right;
                }
                else
                {
                    ceil = root->data;
                    root = root->left;
                }
            }

            ans.push_back(floor);
            ans.push_back(ceil);

            return ans;
		}
};
