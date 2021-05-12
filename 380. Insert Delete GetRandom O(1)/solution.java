class RandomizedSet {
    private Map<Integer, Integer> valueToIndex;
    private List<Integer> nums;
    private Random random;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        nums = new ArrayList<>();
        valueToIndex = new HashMap<>();
        random = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (valueToIndex.containsKey(val)) {
            return false;
        }
        
        nums.add(val);
        valueToIndex.put(val, nums.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!valueToIndex.containsKey(val)) {
            return false;
        }
        
        int index = valueToIndex.get(val);
        if (index != nums.size() - 1) {
            valueToIndex.put(nums.get(nums.size() - 1), index);
            nums.set(index, nums.get(nums.size() - 1));
        }
        valueToIndex.remove(val);
        nums.remove(nums.size() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return nums.get(random.nextInt(nums.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
