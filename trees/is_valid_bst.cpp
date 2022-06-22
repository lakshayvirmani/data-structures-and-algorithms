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
    bool checkValidity(TreeNode* root, int* min, int* max)
    {
        if(root == NULL)
        {
            return true;
        }
        else if((min != NULL && root->val <= *min) || (max != NULL && root->val >= *max))
        {
            return false;
        }
        else
        {
            return checkValidity(root->left, min, &root->val) && checkValidity(root->right, &root->val, max);
        }
    }
};
