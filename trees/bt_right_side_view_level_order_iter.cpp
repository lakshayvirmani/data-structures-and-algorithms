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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        TreeNode* cur = NULL, * prev = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            
            if(cur == NULL && prev != NULL)
            {
                result.push_back(prev->val);
                q.push(NULL);
            }
            
            if(cur != NULL)
            {
                if(cur->left != NULL)
                {
                    q.push(cur->left);
                }

                if(cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
            
            prev = cur;
        }
        
        return result;
    }
};
