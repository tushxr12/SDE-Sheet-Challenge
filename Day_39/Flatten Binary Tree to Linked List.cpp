/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        // Your code goes here
        if (!root) return;

        // Recursively flatten right subtree first
        flatten(root->right);

        // Recursively flatten left subtree
        flatten(root->left);

        // Rearrange pointers
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
