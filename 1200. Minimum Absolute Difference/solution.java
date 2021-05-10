class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        int e = 1;
        List<List<Integer>> results = new ArrayList<>(); 
        while (e < arr.length) {
            if (arr[e] - arr[e - 1] < min) {
                results = new ArrayList<>();
                List<Integer> found = new ArrayList<>();
                found.add(arr[e - 1]);
                found.add(arr[e]);
                results.add(found);
                min = arr[e] - arr[e - 1];
            } else if (arr[e] - arr[e - 1] == min) {
                List<Integer> found = new ArrayList<>();
                found.add(arr[e - 1]);
                found.add(arr[e]);
                results.add(found);
            }
            e++;
        }
        return results;
    }
}
