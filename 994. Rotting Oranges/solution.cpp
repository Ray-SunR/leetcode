class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        
        while (true) {
            vector<pair<int, int>> rottens;
            for (int x = 0; x < grid.size(); x++) {
                for (int y = 0; y < grid[0].size(); y++) {
                    if (grid[x][y] == 2) {
                       rottens.push_back(pair(x, y));
                    }
                }
            }
            
            bool changed = false;
            for (int i = 0; i < rottens.size(); i++) {
                if (helper(grid, rottens[i].first, rottens[i].second) != -1) {
                    changed = true;
                }
            }
            
            if (changed) { result++; }
            else { break; }
        }
        
        
         for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    return -1;
                }
            }
        }
        
        return result;
    }
    
    int helper(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0 || grid[x][y] == 1) {
            return - 1;
        }
        
        bool modified = false;
        if (grid[x][y] == 2) {
            // left
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                modified = true;
            }
            // top
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                modified = true;
            }
            // right
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                modified = true;
            }
            // bottom
            if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                modified = true;
            }
        }
        
        return modified ? 0 : -1;
    }
};
