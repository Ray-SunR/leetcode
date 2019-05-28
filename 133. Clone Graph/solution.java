/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {

    public Node cloneGraph(Node node) {
        Map<Node, Node> map = new HashMap<>();
        
        return clone(node, map);
    }
    
    private Node clone(final Node node, final Map<Node, Node> map) {
        if (!map.containsKey(node)) {
            final Node newNode = new Node();
            newNode.val = node.val;
            newNode.neighbors = new ArrayList<>();
            map.put(node, newNode);
            for (final Node adj : node.neighbors) {
                newNode.neighbors.add(clone(adj, map));
            }
            return newNode;
        } else {
            return map.get(node);
        }
    }
}
