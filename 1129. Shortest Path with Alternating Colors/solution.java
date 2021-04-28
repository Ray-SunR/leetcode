class Solution {
    static class EdgeContainer {
        List<Integer> redEdges;
        List<Integer> blueEdges;
        public EdgeContainer() {
            redEdges = new ArrayList<>();
            blueEdges = new ArrayList<>();
        }
    }
    
    static class Node {
        Integer index;
        Integer cost;
        Boolean isRed;
        public Node(Integer index, Integer cost, Boolean isRed) {
            this.index = index;
            this.cost = cost;
            this.isRed = isRed;
        }
    }
    
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        Map<Integer, EdgeContainer> graph = new HashMap<>();
        int[] result = new int[n];
        Arrays.fill(result, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            graph.put(i, new EdgeContainer());
        }
        
        for (int i = 0; i < red_edges.length; i++) {
            int from = red_edges[i][0];
            int to = red_edges[i][1];
            graph.get(from).redEdges.add(to);
        }
        
        for (int i = 0; i < blue_edges.length; i++) {
            int from = blue_edges[i][0];
            int to = blue_edges[i][1];
            graph.get(from).blueEdges.add(to);
        }
        
        boolean[] redVisited = new boolean[n];
        boolean[] blueVisited = new boolean[n];
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, true));
        q.offer(new Node(0, 0, false));
        redVisited[0] = true;
        blueVisited[0] = true;
        while (!q.isEmpty()) {
            Node node = q.poll();
            result[node.index] = Math.min(result[node.index], node.cost);
            
            if (node.isRed) {
                for (int i = 0; i < graph.get(node.index).blueEdges.size(); i++) {
                    if (!blueVisited[graph.get(node.index).blueEdges.get(i)]) {
                        blueVisited[graph.get(node.index).blueEdges.get(i)] = true;
                        q.offer(new Node(graph.get(node.index).blueEdges.get(i), node.cost + 1, false));    
                    }
                }
            } else {
                for (int i = 0; i < graph.get(node.index).redEdges.size(); i++) {
                    if (!redVisited[graph.get(node.index).redEdges.get(i)]) {
                        redVisited[graph.get(node.index).redEdges.get(i)] = true;
                        q.offer(new Node(graph.get(node.index).redEdges.get(i), node.cost + 1, true));    
                    }
                }
            }
        }
        
        for (int i = 0; i < result.length; i++) {
            if (result[i] == Integer.MAX_VALUE) {
                result[i] = -1;
            }
        }

        return result;
    }
}
