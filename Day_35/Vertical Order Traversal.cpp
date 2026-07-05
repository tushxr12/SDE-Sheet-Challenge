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
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	//your code goes here
        map<int, map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0, 0}});

        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int verticalOrder = p.second.first;
            int level = p.second.second;

            nodes[verticalOrder][level].insert(node->data);

            if(node->left)
                todo.push({node->left, {verticalOrder - 1, level + 1}});
            if(node->right)
                todo.push({node->right, {verticalOrder + 1, level + 1}});
        }

        vector<vector<int>> ans;
        for(auto &p : nodes){
            vector<int> column;

            for(auto &q: p.second){
                column.insert(end(column), q.second.begin(), q.second.end());
            }

            ans.push_back(column);
        }
        return ans;
    }
};
