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
    int treeHeight(TreeNode* root, bool &result)
    {
        if(root == NULL || result == false)
        {
            return 0;
        }
        
        int lHeight = treeHeight(root->left, result);
        int rHeight = treeHeight(root->right, result);
        
        if(abs(lHeight - rHeight) > 1)
        {
            result = false;
        }
        
        return 1 + max(lHeight, rHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        bool result = true;
        treeHeight(root, result);
        return result;
    }
};
