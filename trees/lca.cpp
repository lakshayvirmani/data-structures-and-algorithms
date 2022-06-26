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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;
        findLCA(root, p, q, false, false, lca);
        return lca;
    }
private:
    vector<bool> findLCA(TreeNode* root, TreeNode*& p, TreeNode*& q, bool foundP, bool foundQ, TreeNode*& lca)
    {
        if(root == NULL || lca != NULL || (foundP && foundQ))
        {
            return {foundP, foundQ};
        }
        
        foundP = (root == p);
        foundQ = (root == q);
        
        vector<bool> leftResult = findLCA(root->left, p, q, foundP, foundQ, lca);
        checkAndPopulateResult(leftResult, foundP, foundQ, root, lca);
        
        vector<bool> rightResult = findLCA(root->right, p, q, foundP, foundQ, lca);
        checkAndPopulateResult(rightResult, foundP, foundQ, root, lca);
        
        return {foundP, foundQ};
    }
    
    void checkAndPopulateResult(vector<bool>& result, bool& foundP, bool& foundQ, TreeNode*& root, TreeNode*& lca)
    {
        foundP = foundP || result[0];
        foundQ = foundQ || result[1];
        
        if(foundP && foundQ && lca == NULL)
        {
            lca = root;
        }
    }
};
