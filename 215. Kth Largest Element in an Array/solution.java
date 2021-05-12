class Solution {
    class Compare implements Comparator<Integer> {
        public int compare(Integer num1, Integer num2) {
            return num1 - num2;
        }
    }
    
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Compare());
        for (int i = 0; i < nums.length; i++) {
            pq.offer(nums[i]);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        
        return pq.peek();
    }
    
}
