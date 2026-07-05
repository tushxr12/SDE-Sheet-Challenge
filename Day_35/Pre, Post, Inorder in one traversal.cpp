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
		vector<vector<int>> treeTraversal(TreeNode* root){
			//your code goes here
            vector<vector<int>> ans;
            vector<int> pre, in, post;
            stack<pair<TreeNode*, int>> st;

            if(!root)
                return {in, pre, post};

            st.push({root, 1});

            while(!st.empty())
            {
                auto it = st.top();
                st.pop();

                if(it.second == 1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->left){
                        st.push({it.first->left, 1});
                    }
                }
                else if(it.second == 2){
                    in.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->right){
                        st.push({it.first->right, 1});
                    }
                }
                else
                {
                    post.push_back(it.first->data);
                }
            }
            return {in ,pre, post};
		}
};
