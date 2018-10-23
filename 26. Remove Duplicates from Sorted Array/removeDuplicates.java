class Solution {
    public int removeDuplicates(int[] nums) {
        int newLength = nums.length;
        int p1 = 0;
        int p2 = p1 + 1;
        while (p2 < nums.length) {
            while (p2 < nums.length && nums[p1] == nums[p2]) {
                p2++;
                newLength--;
            }
            p1++;
            if (p2 == nums.length) {
                return newLength;
            } else {
                nums[p1] = nums[p2++];
            }
        }

        return newLength;
    }
}