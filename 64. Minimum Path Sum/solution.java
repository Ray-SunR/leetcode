class Solution {
    public int minPathSum(int[][] grid) {
        // int result = Integer.MAX_VALUE;
        // result = Math.min(dfs(grid, 0, 0, 0, result), result);
        // return result;
        return dp(grid);
    }
    
    private int dfs(int[][] grid, int i, int j, int cost, int result) {
        if (grid[i][j] + cost > result) {
            return result;
        }
        
        if (i == grid.length - 1 && j == grid[i].length - 1) {
            result = Math.min(result, grid[i][j] + cost);
            return result;
        }
        
        // right
        if (j + 1 < grid[i].length) {
            result = Math.min(dfs(grid, i, j + 1, grid[i][j] + cost, result), result);
        }
        
        // bottom
        if (i + 1 < grid.length) {
            result = Math.min(dfs(grid, i + 1, j, grid[i][j] + cost, result), result);
        }
        
        return result;
    }
    
    private int dp(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.length; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < grid[0].length; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        
        return dp[grid.length - 1][grid[0].length - 1];
    }
}
