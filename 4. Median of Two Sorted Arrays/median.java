class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if (n2 < n1) { return findMedianSortedArrays(nums2, nums1); }
        int low = 0; int high = 2 * n1;
        while (low <= high) {
            int c1 = low + (high - low) / 2;
            int c2 = n1 + n2 - c1;
            int l1 = c1 == 0 ? Integer.MIN_VALUE : nums1[(c1 - 1) / 2];
            int r1 = c1 == 2 * n1 ? Integer.MAX_VALUE : nums1[c1 / 2];
            int l2 = c2 == 0 ? Integer.MIN_VALUE : nums2[(c2 - 1) / 2];
            int r2 = c2 == 2 * n2 ? Integer.MAX_VALUE : nums2[c2 / 2];
            if (l1 > r2) {
                high = c1 - 1;
            } else if (r1 < l2) {
                low = c1 + 1;
            } else {
                return (Math.max(l1, l2) + Math.min(r1, r2)) / 2.0;
            }
        }
        return -1;
    }
}