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
    private void pathSumHelper(List<List<Integer>> result, List<Integer> current, TreeNode node, int sum) {
        if (node == null) {
            return;
        }

        current.add(node.val);
        if (node.left == null && node.right == null && node.val == sum) {
            result.add(new ArrayList<>(current));
        } else {
            pathSumHelper(result, current, node.left, sum - node.val);
            pathSumHelper(result, current, node.right, sum - node.val);
        }
        current.remove(current.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        pathSumHelper(result, current, root, sum);
        return result;
    }
}