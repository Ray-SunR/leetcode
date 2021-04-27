class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    result = Math.max(result, dfs(grid, visited, i, j, 1));
                }
            }
        }
        return result == Integer.MIN_VALUE ? 0 : result;
    }
    
    private int dfs(int[][] grid, boolean[][] visited, int i, int j, int size) {
        visited[i][j] = true;
        // System.out.println("i: " + i + " j: " + j + " size: " + size);
        // top
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
            size = dfs(grid, visited, i - 1, j, size + 1);
        }
        
        // left
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
            size = dfs(grid, visited, i, j - 1, size + 1);
        }
        
        // right
        if (j + 1 < grid[i].length && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
            size = dfs(grid, visited, i, j + 1, size + 1);
        }
        
        // bottom
        if (i + 1 < grid.length && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
            size = dfs(grid, visited, i + 1, j, size + 1);
        }
        
        return size;
    }
}
