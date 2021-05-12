class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int i = 0; i < prerequisites.length; i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            List<Integer> edges = graph.getOrDefault(from, new ArrayList<>());
            edges.add(to);
            graph.put(from, edges);
        }
        
        int[] arrayResult = new int[numCourses];
        Set<Integer> onStack = new HashSet<>();
        Stack<Integer> reverseResult = new Stack<>();
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !dfs(graph, reverseResult, i, visited, onStack)) {
                return new int[0];
            }
        }
        int i = 0;
        while (!reverseResult.isEmpty()) {
            arrayResult[i++] = reverseResult.pop();
        }
        return arrayResult;
    }
    
    private boolean dfs(Map<Integer, List<Integer>> graph, Stack<Integer> reverseResult, int current, boolean[] visited, Set<Integer> onStack) {
        if (onStack.contains(current)) {
            return false;
        }
        if (visited[current]) { return true; }
        visited[current] = true;
        onStack.add(current);
        
        for (int i = 0; i < graph.get(current).size(); i++) {
            if (!dfs(graph, reverseResult, graph.get(current).get(i), visited, onStack)) {
                return false;
            }
        }
        // System.out.println("current: " + current);
        reverseResult.push(current);
        onStack.remove(current);
        return true;
    }
}
