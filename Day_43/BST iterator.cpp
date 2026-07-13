/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator{
    private:
        stack<TreeNode*> st;

        void pushAll(TreeNode* node)
        {
            for(; node != NULL; st.push(node), node = node->left);
        }
	public:
		BSTIterator(TreeNode* root){
			pushAll(root);
		}
		
		bool hasNext(){
			return !st.empty();
		}
		
		int next(){
            TreeNode* temp = st.top();
            st.pop();

            pushAll(temp->right);
            return temp->data;
		}

};
