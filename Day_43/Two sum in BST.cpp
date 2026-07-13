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
        void inorder(TreeNode* root, vector<int> &values)
        {
            if(!root)
                return;
            
            inorder(root->left, values);
            values.push_back(root->data);
            inorder(root->right,values);
        }
	public:
		bool twoSumBST(TreeNode* root, int k){
			//your code goes here
            vector<int> values;
            inorder(root, values);
            int left = 0, right = values.size() - 1;

            while(left < right)z
            {
                int currSum = values[left] + values[right];

                if(currSum == k){
                    return true;
                }
                else if(currSum > k){
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return false;
		}
};
