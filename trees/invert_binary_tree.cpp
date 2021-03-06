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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        
        TreeNode * invertedLeft = invertTree(root -> left);
        TreeNode * invertedRight = invertTree(root -> right);
        
        root -> left = invertedRight;
        root -> right = invertedLeft;
        
        return root;
    }

    TreeNode* invertTreeIterative(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur -> left != NULL)
            {
                q.push(cur -> left);
            }
            
            if(cur -> right != NULL)
            {
                q.push(cur -> right);
            }
            
            TreeNode* tmp = cur -> left;
            cur -> left = cur -> right;
            cur -> right = tmp;
        }
        
        return root;
    }
};
