class Solution {
    
    class Node {
        int freq;
        Character c;
        public Node(Character c, int freq) {
            this.c = c;
            this.freq = freq;
        }
    }
    class Compare implements Comparator<Node> {
        public int compare(Node n1, Node n2) {
            return n2.freq - n1.freq;
        }
    }
    
    public String reorganizeString(String s) {
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Node> pq = new PriorityQueue<>(new Compare());
        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            freq.put(s.charAt(i), freq.getOrDefault(s.charAt(i), 0) + 1);
        }
        freq.forEach((key, value) -> {
            pq.offer(new Node(key, value));
        });
        
        while (!pq.isEmpty()) {
            Node n = pq.poll();
            sb.append(n.c);
            n.freq--;
            
            if (pq.isEmpty()) {
                if (sb.length() == s.length()) {
                    return sb.toString();
                } else {
                    return "";
                }
            }
            
            Node newNode = pq.poll();
            sb.append(newNode.c);
            newNode.freq--;
            
            if (n.freq > 0) {
                pq.offer(n);
            }
            if (newNode.freq > 0) {
                pq.offer(newNode);
            }
        }
        if (sb.length() == s.length()) {
            return sb.toString();
        } else {
            return "";
        }
    }
}
