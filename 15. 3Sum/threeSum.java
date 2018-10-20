class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        final List<List<Integer>> results = new ArrayList<>();
        int i = 0;
        while (i < nums.length) {
            int target = -nums[i];
            int low = i + 1;
            int high = nums.length - 1;
            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    final List<Integer> result = new ArrayList<>();
                    result.add(nums[low]); result.add(nums[high]); result.add(nums[i]);
                    results.add(result);
                    while (high - 1 >= 0 && nums[high - 1] == nums[high]) { high--; }
                    while (low + 1 < nums.length && nums[low + 1] == nums[low]) { low++; }
                    high--;
                    low++;
                } else  if (nums[low] + nums[high] > target) {
                    high--;
                } else {
                    low++;
                }
            }
            while (i + 1 < nums.length && nums[i + 1] == nums[i]) { i++; }
            i++;
        }
        return results;
    }
}