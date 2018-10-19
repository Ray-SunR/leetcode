class Solution {
    public int[] twoSum(int[] nums, int target) {
        final int[] results = new int[2];
        final Map<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            hash.put(nums[i], i);
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (hash.containsKey(target - nums[i])) {
                int index = hash.get(target - nums[i]);
                if (index == i) {
                    continue;
                }
                results[0] = i;
                results[1] = index;
                break;
            }
        }
        return results;
    }
}