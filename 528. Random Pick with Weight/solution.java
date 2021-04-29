class Solution {
    private int[] sum;
    private Random random;
    private Map<Integer, Integer> map;
    public Solution(int[] w) {
        sum = new int[w.length];
        for (int i = 0; i < w.length; i++) {
            sum[i] = w[i] + (i == 0 ? 0 : sum[i - 1]);
        }

        // map = new HashMap<>();
        // int prev = 1;
        // for (int i = 0; i < sum.length; i++) {
        //     int val = sum[i];
        //     for (int j = prev; j <= val; j++) {
        //         // System.out.println("key: " + j + " value: " + i);
        //         map.put(j, i);
        //     }
        //     prev = val + 1;
        // }
        
        random = new Random();
    }
    
    public int pickIndex() {
        // [1, sum[sum.length - 1]]
        int index = random.nextInt(sum[sum.length - 1]) + 1;
        int b = 0; int e = sum.length - 1;
        while (b < e) {
            int mid = b + (e - b) / 2;
            if (sum[mid] == index) {
                return mid;
            } else if (sum[mid] < index) {
                b = mid + 1;
            } else {
                e = mid;
            }
        }
        return b;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
