class MyCalendarThree {
    private TreeMap<Integer, Integer> map;
    
    public MyCalendarThree() {
        map = new TreeMap<>();    
    }
    
    public int book(int start, int end) {
        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        int max = Integer.MIN_VALUE;
        int count = 0;
        for (Integer key : map.keySet()) {
            count += map.get(key);
            max = Math.max(max, count);
        }
        return max;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
