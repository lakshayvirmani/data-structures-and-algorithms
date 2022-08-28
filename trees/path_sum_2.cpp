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
    void populatePaths(TreeNode* root, int targetSum, vector<int>& cur, vector<vector<int>>& result)
    {
        if(root == NULL)
        {
            return;
        }
        
        cur.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && root->val == targetSum)
        {
            result.push_back(cur);
        }
        
        populatePaths(root->left, targetSum - root->val, cur, result);
        populatePaths(root->right, targetSum - root->val, cur, result);
            
        cur.pop_back();    
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> cur;
        populatePaths(root, targetSum, cur, result);
        return result;
    }
};
