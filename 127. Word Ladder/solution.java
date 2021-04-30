class Solution {
    class Node {
        String string;
        int length;
        public Node(String string, int length) {
            this.string = string;
            this.length = length;
        }
    }
    
    public int ladderLength(String beginWord, String endWord, List<String> wordList)    {
        Set<String> set = new HashSet<>(wordList);
        int result = Integer.MAX_VALUE;
        Queue<Node> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer(new Node(beginWord, 1));
        visited.add(beginWord);
        while (!q.isEmpty()) {
            Node node = q.poll();
            // System.out.println(node.string);
            if (node.string.equals(endWord)) {
                result = Math.min(result, node.length);
                continue;
            }
            
            String word = node.string;
            for (int i = 0; i < word.length(); i++) {
                StringBuilder newString = new StringBuilder(word);
                for (int j = 0; j < 26; j++) {
                    newString.setCharAt(i, (char) ('a' + j));
                    String newWord = newString.toString();
                    if (!visited.contains(newWord) && set.contains(newWord)) {
                        q.offer(new Node(newWord, node.length + 1));
                        visited.add(newWord);
                    }
                }
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result;
    }
}
