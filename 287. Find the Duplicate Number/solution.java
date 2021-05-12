class Solution {
    // public int findDuplicate(int[] nums) {
    //     Set<Integer> set = new HashSet<>();
    //     for (int i = 0; i < nums.length; i++) {
    //         if (set.contains(nums[i])) {
    //             return nums[i];
    //         }
    //         set.add(nums[i]);
    //     }
    //     return -1;
    // }
    
    public int findDuplicate(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] == i + 1) {
                i++;
                continue;
            }
            
            if (nums[nums[i] - 1] == nums[i]) {
                return nums[i];
            } else {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        return -1;
    }

}
