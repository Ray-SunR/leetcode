class LFUCache {
    static class Node {
        int value;
        int key;
        int freq;
        long time;
        @Override
        public boolean equals(Object other) {
            if (other == this) {
                return true;
            }
            
            Node otherNode = (Node) other;
            return otherNode.key == this.key;
        }
        
        public Node(int value, int key, int time) {
            this.value = value;
            this.key = key;
            this.freq = 0;
            this.time = time;
        }
    }
    
    class Compare implements Comparator<Node> {
        public int compare(Node n1, Node n2) {
            if (n1.freq == n2.freq) {
                return (int) (n1.time - n2.time);
            }
            return n1.freq - n2.freq;
        }
    }
    
    private PriorityQueue<Node> pq;
    private Map<Integer, Node> data;
    private int capacity;
    private int size;
    private int time;

    public LFUCache(int capacity) {
        this.pq = new PriorityQueue<>(new Compare());
        data = new HashMap<>();
        this.capacity = capacity;
        this.size = 0;
        this.time = 0;
    }
    
    public int get(int key) {
        // System.out.println("getting key: " + key);
        ++time;
        if (data.containsKey(key)) {
            Node n = data.get(key);
            n.freq++;
            n.time = time;
            pq.remove(n);
            pq.offer(n);
            return n.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        // System.out.println("put key: " + key + " value: " + value);
        ++time;
        if (capacity == 0) {
            return;
        }
        if (data.containsKey(key)) {
            Node n = data.get(key);
            n.value = value;
            n.freq++;
            n.time = time;
            pq.remove(n);
            pq.offer(n);
            // System.out.println("contains key: " + key + " updated freq to: " + n.freq);
        } else if (size < capacity) {
            Node n = new Node(value, key, time);
            n.freq++;
            data.put(key, n);
            pq.offer(n);
            size++;
            // System.out.println("within capacity add new node with ky: " + key + " updated freq to: " + n.freq);
        } else {
            Node n = pq.poll();
            data.remove(n.key);
            // System.out.println("exceed capacity remove node with key: " + n.key);

            Node newNode = new Node(value, key, time);
            newNode.freq++;
            data.put(key, newNode);
            pq.offer(newNode);
            // System.out.println("adding new node with key: " + newNode.key);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
