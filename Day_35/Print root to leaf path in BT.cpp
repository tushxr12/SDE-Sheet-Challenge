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
        void dfs(TreeNode* node, vector<int> &currPath, vector<vector<int>> &allPaths)
        {
            if(!node)
                return;
            
            currPath.push_back(node->data);

            if(!node->left && !node->right)
                allPaths.push_back(currPath);
            else
            {
                dfs(node->left, currPath, allPaths);
                dfs(node->right, currPath, allPaths);
            }

            currPath.pop_back();
        }
	public:
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>> ans;
            vector<int> currPath;

            dfs(root, currPath, ans);
            return ans;
		}
};
