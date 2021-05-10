class Solution {
//     class Node {
//         int x;
//         int y;
//         int dist;
//         public Node(int x, int y, int dist) {
//             this.x = x;
//             this.y = y;
//             this.dist = dist;
//         }
//     }
//     public int minFallingPathSum(int[][] matrix) {
//         Queue<Node> q = new LinkedList<>();
//         int min = Integer.MAX_VALUE;
//         for (int i = 0; i < matrix[0].length; i++) {
//             q.add(new Node(0, i, matrix[0][i]));
//         }
        
//         while (!q.isEmpty()) {
//             Node node = q.poll();
//             if (node.x == matrix.length - 1) {
//                 min = Math.min(node.dist, min);
//                 continue;
//             }
            
//             // diag left
//             if (node.x + 1 < matrix.length && node.y - 1 >= 0 && node.dist + matrix[node.x + 1][node.y - 1] < min) {
//                 q.add(new Node(node.x + 1, node.y - 1, node.dist + matrix[node.x + 1][node.y - 1]));
//             }
            
//             // bottom
//             if (node.x + 1 < matrix.length && node.dist + matrix[node.x + 1][node.y] < min) {
//                 q.add(new Node(node.x + 1, node.y, node.dist + matrix[node.x +1][node.y]));
//             }
//             // diag right
//             if (node.x + 1 < matrix.length && node.y + 1 < matrix[node.x].length && node.dist + matrix[node.x + 1][node.y + 1] < min) {
//                 q.add(new Node(node.x + 1, node.y + 1, node.dist + matrix[node.x + 1][node.y + 1]));
//             }
//         }
        
//         return min;
//     }
        public int minFallingPathSum(int[][] matrix) {
            int[][] dp = new int[matrix.length][matrix[0].length];
            for (int i = 0; i < dp.length; i++) {
                Arrays.fill(dp[i], Integer.MAX_VALUE);
            }
            
            for (int i = 0; i < matrix[0].length; i++) {
                dp[0][i] = matrix[0][i];
            }
            int result = Integer.MAX_VALUE;
            for (int i = 1; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    // top left
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] = Math.min(dp[i - 1][j - 1] + matrix[i][j], dp[i][j]);
                    }
                    // top
                    if (i - 1 >= 0) {
                        dp[i][j] = Math.min(dp[i - 1][j] + matrix[i][j], dp[i][j]);
                    }
                    // top right
                    if (i - 1 >= 0 && j + 1 < matrix[i].length) {
                        dp[i][j] = Math.min(dp[i - 1][j + 1] + matrix[i][j], dp[i][j]);
                    }
                }
            }
            
            for (int i = 0; i < dp[0].length; i++) {
                result = Math.min(result, dp[dp.length -1][i]);   
            }
            return result;
        }
}
