class MyCalendarTwo {
    private TreeMap<Integer, Integer> map;

    public MyCalendarTwo() {
        map = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        // System.out.println("start: " + start + " end: " + end + " startCount: " + map.get(start));
        int count = 0;
        for (Map.Entry<Integer ,Integer> entry : map.entrySet()) {
            // System.out.println("key: " + entry.getKey() + " count: " + entry.getValue());
            count += entry.getValue();
            if (count > 2) {
                map.put(start, map.get(start) - 1);
                map.put(end, map.get(end) + 1);
                return false;
            }
            if (end < entry.getKey()) {
                break;
            }
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
