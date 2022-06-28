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
        TreeNode* childNode = NULL;
        bool foundOne = false;
        
        // stack containing a pointer to a tree node and the number of children visited
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        
        while(!stk.empty())
        {
            auto cur = stk.top();
            TreeNode* parent = cur.first;
            int numChildrenVisited = cur.second;
            
            if(numChildrenVisited != 2)
            {
                if(numChildrenVisited == 0)
                {
                    if(parent == p || parent == q)
                    {
                        if(foundOne == true)
                        {
                            return lca;
                        }
                        else
                        {
                            foundOne = true;
                            lca = parent;
                        }
                    }

                    childNode = parent->left;
                }
                else
                {
                    childNode = parent->right;
                }
                
                stk.pop();
                stk.push({parent, numChildrenVisited + 1});
                
                if(childNode != NULL)
                {
                    stk.push({childNode, 0});
                }
            }
            else
            {
                stk.pop();
                if(lca == parent && foundOne)
                {
                    lca = stk.top().first;
                }
            }
        }
        
        return lca;
    }
};
