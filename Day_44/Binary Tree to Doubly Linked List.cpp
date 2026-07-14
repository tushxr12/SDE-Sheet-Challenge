class Solution {
private:
    TreeNode* prev = NULL, *head = NULL;

    void inorder(TreeNode* node)
    {
        if(!node)
            return;
        
        inorder(node->left);

        if(!prev)
        {
            head = node;
        }
        else
        {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorder(node->right);
    }

public:
    TreeNode* bToDLL(TreeNode* root) {
        // Your code goes here
        prev = NULL;
        head = NULL;
        inorder(root);
        return head;
    }
};
