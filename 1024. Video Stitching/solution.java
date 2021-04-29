class Solution {
    static class Compare implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return a[0] - b[0];
        }
    }
    public int videoStitching(int[][] clips, int T) {
        if (T == 0) { return 0;}
        Arrays.sort(clips, new Compare());
        int s = 0;
        int e = 0;
        int i = 0;
        int res = 0;
        while (i < clips.length && s < T) {
            boolean hasChanged = false;
            while (i < clips.length && clips[i][0] <= s) {
                e = Math.max(e, clips[i++][1]);
                hasChanged = true;
            }
            
            if (!hasChanged) {
                return -1;
            }
            // System.out.println("s: " + s + " e: " + e);
            res++;
            s = e;
        }
        return s >= T ? res : -1;
    }
}
