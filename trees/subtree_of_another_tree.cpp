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
    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL && subRoot == NULL)
        {
            return true;
        }
        else if(root == NULL || subRoot == NULL)
        {
            return false;
        }
        else
        {
            return root->val == subRoot->val && isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL)
        {
            return true;
        }
        
        bool found = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && !found)
        {
            root = q.front();
            q.pop();
            
            if(root->val == subRoot->val)
            {
                found = isSameTree(root, subRoot);
            }
            
            if(root->left != NULL)
            {
                q.push(root->left);
            }
            
            if(root->right != NULL)
            {
                q.push(root->right);
            }
        }
        
        return found;
    }
};
