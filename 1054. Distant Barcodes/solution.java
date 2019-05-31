import java.util.PriorityQueue;

class Solution {
    private class Key {
        int val;
        int freq;
    }
    public int[] rearrangeBarcodes(int[] barcodes) {
        PriorityQueue<Key> pq = new PriorityQueue<>(10000, (a, b) -> b.freq - a.freq);
        
        final int[] freqMap = new int[10001];
        for (int i = 0; i < barcodes.length; i++) {
            freqMap[barcodes[i]]++;
        }
        
        for (int i = 0; i < 10001; i++) {
            if (freqMap[i] != 0) {
                final Key key = new Key(); key.val = i; key.freq = freqMap[i];
                pq.add(key);
            }
        }
        
        final int[] result = new int[barcodes.length];
        int index = 0;
        Key prev = new Key(); prev.freq = -1;
        while (!pq.isEmpty()) {
            final Key removed = pq.remove();
            result[index++] = removed.val;
            
            if (prev.freq > 0) {
                pq.add(prev);
            }
            
            removed.freq--;
            prev = removed;
        }
        
        return result;
    }
}
