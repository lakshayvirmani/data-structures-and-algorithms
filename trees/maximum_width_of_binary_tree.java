/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Integer maxWidth;
    private HashMap<Integer, Integer> levelToFirstIdxMap;
    
    private void DFS(TreeNode node, Integer depth, Integer colIndex)
    {
        if(node == null)
        {
            return;
        }
        
        if(!levelToFirstIdxMap.containsKey(depth))
        {
            levelToFirstIdxMap.put(depth, colIndex);
        }
        
        maxWidth = Math.max(maxWidth, colIndex - levelToFirstIdxMap.get(depth) + 1);
        
        DFS(node.left, depth + 1, colIndex * 2);
        DFS(node.right, depth + 1, colIndex * 2 + 1);
    }
    
    public int widthOfBinaryTree(TreeNode root) {
        maxWidth = 0;
        levelToFirstIdxMap = new HashMap<Integer, Integer>();
        
        DFS(root, 0, 0);
        
        return maxWidth;
    }
}
