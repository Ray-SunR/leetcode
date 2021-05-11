class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> data = new HashMap<>();
        for (int i = 0; i < stones.length; i++) {
            data.put(stones[i], new HashSet<>());
        }
        
        data.get(0).add(1);
        for (int i = 0; i < stones.length; i++) {
            Set<Integer> steps = data.get(stones[i]);
            for (Integer step : steps) {
                if (stones[i] + step == stones[stones.length - 1]) {
                    return true;
                }
                
                Set<Integer> newSteps = data.get(stones[i] + step);
                if (newSteps != null) {
                    newSteps.add(step);
                    if (step - 1 > 0) {
                        newSteps.add(step - 1);
                    }
                    newSteps.add(step + 1);
                }
            }
        }
        return false;
    }
}
