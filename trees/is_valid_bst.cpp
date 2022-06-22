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
    bool isValidBST(TreeNode* root) {
        return checkValidity(root, NULL, NULL);
    }
private:
    bool checkValidity(TreeNode* root, TreeNode* lo, TreeNode* hi)
    {
        if(root == NULL)
        {
            return true;
        }
        else if((lo != NULL && root->val <= lo->val) || (hi != NULL && root->val >= hi->val))
        {
            return false;
        }
        else
        {
            return checkValidity(root->left, lo, root) && checkValidity(root->right, root, hi);
        }
    }
};
