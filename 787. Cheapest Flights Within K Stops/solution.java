class Solution {
    
    private int answer = Integer.MAX_VALUE;
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        final Map<Integer, List<Integer[]>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int i = 0; i < flights.length; i++) {
            int source = flights[i][0];
            int destination = flights[i][1];
            int cost = flights[i][2];
            Integer[] val = new Integer[2];
            val[0] = destination;
            val[1] = cost;
            graph.get(source).add(val);
        }
        
        // dfs(graph, src, dst, 0, K + 1);
        // return answer == Integer.MAX_VALUE ? - 1 : answer;
        return bfs(graph, src, dst, K);
    }
    
    public void dfs(Map<Integer, List<Integer[]>> graph, int node, int dest, int cost, int K) {
        if (cost > answer) { return; }
        if (node == dest) {
            answer = Math.min(cost, answer);
            return;
        }
        if (K == 0) { return; }
        
        for (int i = 0; i < graph.get(node).size(); i++) {
            dfs(graph, graph.get(node).get(i)[0], dest, cost + graph.get(node).get(i)[1], K - 1);
        }
    }
    
    static class Node {
        int index;
        int cost;
        int hop;
        public Node(int index, int cost, int hop) {
            this.index = index;
            this.cost = cost;
            this.hop = hop;
        }
    }
    
    public int bfs(Map<Integer, List<Integer[]>> graph, int src, int dest, int k) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(src, 0, k + 1));
        int result = Integer.MAX_VALUE;
        
        while (!q.isEmpty()) {
            Node node = q.poll();

            if (node.hop < 0 || node.cost > result) {
                continue;
            }
            
            if (node.index == dest) {
                result = Math.min(result, node.cost);
                continue;
            }
            
            for (int i = 0; i < graph.get(node.index).size(); i++) {
                q.offer(new Node(graph.get(node.index).get(i)[0], node.cost + graph.get(node.index).get(i)[1], node.hop - 1));
            }
        }
        
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
