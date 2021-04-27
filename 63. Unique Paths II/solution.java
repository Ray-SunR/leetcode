class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            if (i - 1 >= 0) {
                dp[i][0] = grid[i][0] == 1 ? 0 : dp[i - 1][0];
            } else {
                dp[i][0] = grid[i][0] == 1 ? 0 : 1;
            }
        }
        
        for (int i = 0; i < grid[0].length; i++) {
            if (i - 1 >= 0) {
                dp[0][i] = grid[0][i] == 1 ? 0 : dp[0][i - 1];
            } else {
                dp[0][i] = grid[0][i] == 1 ? 0 : 1;
            }
        }
        
       
        
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                if (grid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[grid.length - 1][grid[0].length - 1];
    }
}
