/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
private:
    vector<vector<int>> bfs(TreeNode* root)
    {
        vector<vector<int>> result;
        
        if(root == NULL)
        {
            return result;
        }
        
        queue<TreeNode*> q;
        
        // initialize bfs
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int level_size = q.size();
            
            for(int i = 0; i < level_size; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                level.push_back(cur->val);
                
                if(cur->left != NULL)
                {
                    q.push(cur->left);
                }
                
                if(cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};
