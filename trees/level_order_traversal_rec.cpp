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
        vector<vector<int>> result;
        populateLevelOrder(root, 1, result);
        return result;
    }
private:
    void populateLevelOrder(TreeNode* root, int level, vector<vector<int>>& result)
    {
        if(root == NULL)
        {
            return;
        }
        
        // ensure level exists in result
        while(result.size() < level)
        {
            result.push_back(vector<int>());
        }
        
        // push current root
        result[level - 1].push_back(root->val);
        
        populateLevelOrder(root->left, level + 1, result);
        populateLevelOrder(root->right, level + 1, result);
    }
};
