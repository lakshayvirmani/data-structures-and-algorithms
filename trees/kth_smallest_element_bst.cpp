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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* kthNode = findKthSmallestNode(root, k);
        return kthNode->val;
    }
private:
    TreeNode* findKthSmallestNode(TreeNode* root, int& k)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        TreeNode* result = findKthSmallestNode(root->left, k);
        
        if(result == NULL)
        {
            k--;
            
            if(k == 0)
            {
                result = root;
            }
            else
            {
                result = findKthSmallestNode(root->right, k);
            }
        }
        
        return result;
    }
};
