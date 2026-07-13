/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:

    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(!node)
                s.append("#,");
            else
                s.append(to_string(node->data)+',');
            
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
