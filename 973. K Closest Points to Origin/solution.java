class Solution {
    class Compare implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return -(a[0] * a[0] + a[1] * a[1]) + (b[0] * b[0] + b[1] * b[1]);
        }
    } 
    
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Compare());
        for (int i = 0; i < points.length; i++) {
            pq.add(points[i]);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        int[][] results = new int[k][2];
        int i = 0;
        while (!pq.isEmpty()) {
            int[] point = pq.poll();
            results[i++] = point;
        }
        return results;
    }
}
