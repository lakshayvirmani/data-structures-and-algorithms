/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* suc = NULL;
        
        while(root != NULL)
        {
            if(root->val == p->val)
            {
                if(root->right != NULL)
                {
                    suc = root->right;
                    while(suc->left != NULL)
                    {
                        suc = suc->left;
                    }
                }
                break;
            }
            else if(p->val < root->val)
            {
                suc = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        
        return suc;
    }
};
