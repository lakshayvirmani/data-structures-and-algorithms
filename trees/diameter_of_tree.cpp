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
    int trackHeight(TreeNode* root, int & diameter)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lHeight = trackHeight(root->left, diameter);
        int rHeight = trackHeight(root->right, diameter);
        
        diameter = max(diameter, lHeight + rHeight);
        
        return 1 + max(lHeight, rHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        trackHeight(root, diameter);
        return diameter;
    }
};
