class Solution {
    private int[] nums;
    private int[] copy;
    private Random random;
    public Solution(int[] nums) {
        this.nums = nums;
        this.copy = copy(nums);
        this.random = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        this.nums = copy(this.copy);
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j < i; j++) {
                int index = random.nextInt(i);
                int val = nums[index];
                nums[index] = nums[j];
                nums[j] = val;
            }
        }
        return nums;
    }
    
    private int[] copy(int[] vals) {
        int[] newNums = new int[vals.length];
        for (int i = 0; i < vals.length; i++) {
            newNums[i] = vals[i];
        }
        return newNums;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
