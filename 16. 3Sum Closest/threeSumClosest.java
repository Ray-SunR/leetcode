class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int index = 0;
        int min = Integer.MAX_VALUE;
        int result = 0;
        while (index < nums.length) {
            int val = target - nums[index];
            int low = index + 1;
            int high = nums.length - 1;
            while (low < high) {
                if (Math.abs(nums[low] + nums[high] - val) < min) {
                    min = Math.abs(nums[low] + nums[high] - val);
                    result = nums[low] + nums[high] + nums[index];
                }
                if (nums[low] + nums[high] == val) {
                    return result;
                } else if (nums[low] + nums[high] > val) {
                    high--;
                } else {
                    low++;
                }  
            }
            while (index + 1 < nums.length && nums[index + 1] == nums[index]) { index++; }
            index++;
        }
        return result;
    }
}