class Solution {
    public void duplicateZeros(int[] arr) {
        int size = arr.length;
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 0) {
                count++;
            }
        }
        if (count == 0) { return; }
        
        int newPos = size - 1 + count;
        int pos = size - 1;
        
        while (pos >= 0) {
            if (arr[pos] == 0) {
                if (newPos <= size - 1) {
                    arr[newPos--] = 0;
                } else {
                    newPos--;
                }
                if (newPos <= size - 1) {
                    arr[newPos--] = 0;
                } else {
                    newPos--;
                }
            } else {
                if (newPos <= size - 1) {
                    arr[newPos--] = arr[pos];
                } else {
                    newPos--;
                }
            }
            pos--;
        }
    }
}