class Solution {
    private Map<Integer, List<Integer>> data;
    private Random random;
    public Solution(int[] nums) {
        data = new HashMap<>();
        for (int i = 0;i < nums.length; i++) {
            List<Integer> indexes = data.get(nums[i]);
            if (indexes != null) {
                indexes.add(i);
            } else {
                indexes = new ArrayList<>();
                indexes.add(i);
                data.put(nums[i], indexes);
            }
        }
        // data.entrySet().stream().forEach(entry -> System.out.println("key: " + entry.getKey() + " value: " + entry.getValue()));
        random = new Random();
    }
    
    public int pick(int target) {
        List<Integer> indexes = data.get(target);
        return indexes.get(random.nextInt(indexes.size()));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
