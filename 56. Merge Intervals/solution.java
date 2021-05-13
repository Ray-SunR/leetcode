class Solution {
    class Compare implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return a[0] - b[0];
        }
    }
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Compare());
        int i = 0;
        int probe = i;
        List<Integer[]> listResult = new ArrayList<>();
        while (probe < intervals.length) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (probe < intervals.length && intervals[probe][0] <= end) {
                start = Math.min(start, intervals[probe][0]);
                end = Math.max(end, intervals[probe][1]);
                probe++;
            }
            
            Integer[] newInterval = new Integer[2];
            newInterval[0] = start;
            newInterval[1] = end;
            // System.out.println("start: " + start + " end: " + end);
            listResult.add(newInterval);
            // result[resultIndex++] = newInterval;
            i = probe;
        }
        int resultIndex = 0;
        int[][] result = new int[listResult.size()][2];
        while (resultIndex < listResult.size()) {
            result[resultIndex][0] = listResult.get(resultIndex)[0];
            result[resultIndex][1] = listResult.get(resultIndex)[1];
            resultIndex++;
        }
        return result;
    }
}
