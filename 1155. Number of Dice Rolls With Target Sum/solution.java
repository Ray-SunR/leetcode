class Solution {
    int MOD = 1000000000 + 7;

    public int numRollsToTarget(int d, int f, int target) {
        Map<String, Integer> cache = new HashMap<>();
        return dfs(d, f, target, cache);
    }
    
    public int dfs(int d, int f, int target, Map<String, Integer> cache) {
        if (target == 0 && d == 0) {
            return 1;
        }
        
        if (d == 0) {
            return 0;
        }
        
        int result = 0;
        
        String key = Integer.toString(d) + " " + Integer.toString(target);
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        
        for (int i = 1; i <= f; i++) {
            if (i > target) {
                break;
            }
            result += dfs(d - 1, f, target - i, cache);
            result %= MOD;
        } 
        cache.put(key, result);
        return result;
    }
}
