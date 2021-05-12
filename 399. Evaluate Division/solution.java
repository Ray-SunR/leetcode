class Solution {
    class Node {
        String c;
        double value;
        public Node(String c, double value) {
            this.c = c;
            this.value = value;
        }
    }
    
    private void printGraph(Map<String, Map<String, Node>> graph) {
        for (String from : graph.keySet()) {
            System.out.println("from: " + from);
            for (String to : graph.get(from).keySet()) {
                System.out.println("to: " + to);
            }
        }
        System.out.println("");
    }
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Node>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String from = equations.get(i).get(0);
            String to = equations.get(i).get(1);
            Map<String, Node> fromEdges = graph.getOrDefault(from, new HashMap<>());
            Map<String, Node> toEdges = graph.getOrDefault(to, new HashMap<>());
            
            fromEdges.put(to, new Node(to, values[i]));
            toEdges.put(from, new Node(from, 1.0 / values[i]));
            graph.put(from, fromEdges);
            graph.put(to, toEdges);
        }
        // printGraph(graph);
        
        double[] results = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            Set<String> visited = new HashSet<>();
            results[i] = dfs(graph, visited, queries.get(i).get(0), queries.get(i).get(1), 1);
        }
        return results;
    }
    
    public double dfs(Map<String, Map<String, Node>> graph, Set<String> visited, String current, String dest, double result) {
        if (!graph.containsKey(current)) {
            return -1;
        }
        
        if (current.equals(dest)) {
            return result;
        }
        
        visited.add(current);
        
        Map<String, Node> edges = graph.get(current);
        for (String key : edges.keySet()) {
            if (!visited.contains(key)) {
                double ret = dfs(graph, visited, key, dest, result * edges.get(key).value);
                if (ret != -1) {
                    return ret;
                }
            }
        }
        
        return -1;
    }
}
