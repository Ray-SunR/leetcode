class Solution {
    public int removeElement(int[] nums, int val) {
        int p1 = 0;
        int p2 = 0;
        int length = nums.length;
        while (p2 < nums.length) {
            if (nums[p2] != val) { nums[p1++] = nums[p2]; }
            else { length--; }
            p2++;
        }
        return length;
    }
}