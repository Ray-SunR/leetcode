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
    private void levelOrder(List<Integer> result, TreeNode node, int level) {
        if (node == null) {
            return;
        }
        
        if (level == 1) {
            result.add(node.val);
            return;
        }
        levelOrder(result, node.left, level - 1);
        levelOrder(result, node.right, level - 1);
    }

    private int level(TreeNode root, int count) {
        if (root == null) {
            return count;
        }
        return Math.max(level(root.left, count + 1), level(root.right, count + 1));
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        // List<List<Integer>> result = new ArrayList<>();
        // int level = level(root, 0);
        // for (int i = 1; i <= level; i++) {
        //     List<Integer> levelResult = new ArrayList<>();
        //     result.add(levelResult);
        //     levelOrder(levelResult, root, i);
        // }
        // return result;
        return levelOrder2(root);
    }

    private void levelOrder2(List<List<Integer>> result, TreeNode node, int level) {
        if (node == null) {
            return;
        }

        if (level < result.size() + 1) {
            result.get(level - 1).add(node.val);
        } else {
            List<Integer> levelResult = new ArrayList<>();
            levelResult.add(node.val);
            result.add(levelResult);
        }

        levelOrder2(result, node.left, level + 1);
        levelOrder2(result, node.right, level + 1);
    }

    public List<List<Integer>> levelOrder2(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        levelOrder2(result, root, 1);
        return result;
    }
}