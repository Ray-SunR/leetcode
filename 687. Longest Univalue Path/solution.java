/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int helper(TreeNode root, int val) {
        if (root == null) {
            return 0;
        }

        return root.val == val ? 1 : 0 + helper(root.left, val) + helper(root.right, val);
    }

    public int longestUnivaluePath(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Math.max(helper(root, root.val), Math.max(longestUnivaluePath(root.left), longestUnivaluePath(root.right)));
    }
}