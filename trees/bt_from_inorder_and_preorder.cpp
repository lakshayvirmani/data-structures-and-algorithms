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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), preIdx = 0;
        
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[inorder[i]] = i;
        }
        
        return constructTree(preIdx, 0, n - 1, preorder, m);
    }
private:
    TreeNode* constructTree(int& preIdx, int inorderLo, int inorderHi, vector<int>& preorder, unordered_map<int, int>& inorderMap)
    {
        if(inorderLo > inorderHi)
        {
            return NULL;
        }
        
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        
        int mid = inorderMap[val];
        
        root->left = constructTree(preIdx, inorderLo, mid - 1, preorder, inorderMap);
        root->right = constructTree(preIdx, mid + 1, inorderHi, preorder, inorderMap);
        
        return root;
    }
};
