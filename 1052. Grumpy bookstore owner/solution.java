// The idea is to calculate the orignal customer volume without applying the seceret. While scanning through the array, calculate the max possible added customer volume. 
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int maxAdded = 0;
        int originalResult = 0;
        int addedResult = 0;
        for (int i = 0; i < customers.length; i++) {
            originalResult += grumpy[i] == 0 ? customers[i] : 0;
            addedResult += grumpy[i] == 1 ? customers[i] : 0;
            if (i - X >= 0) { addedResult -= customers[i - X] * grumpy[i - X]; }
            maxAdded = addedResult > maxAdded ? addedResult : maxAdded;
        }
        return originalResult + maxAdded;
    }
}
