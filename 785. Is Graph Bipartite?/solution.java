class Solution {
    public boolean isBipartite(int[][] graph) {
	    // arrays for saving vertices colors
        final boolean[] colors = new boolean[graph.length];
        final boolean[] visited = new boolean[graph.length];
        for (int v = 0; v < graph.length; v++) {
            if (!visited[v]) {
                if (!dfs(graph, v, colors, visited, false)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private boolean dfs(int[][] graph, int v, boolean[] colors, boolean[] visited, boolean adjColor) {
        if (!visited[v]) {
            visited[v] = true;
            colors[v] = !adjColor; // We color the current vertex with an opposite color of its adjacent vertex.
            for (int index = 0; index < graph[v].length; index++) {
                if (!dfs(graph, graph[v][index], colors, visited, !adjColor)) {
                    return false;
                }
            }
		// if we encounter a vertex who is already colored, if that's the same color as color of the vertex that's currently being visited, then this graph is not bipartite.	
        } else if (colors[v] == adjColor) {
            return false;
        }
        
        return true;
    }
}
