class Solution {
    private void generateParenthesis(int numLeft, int numRight, List<String> result, String s) {
        if (numRight == 0) { result.add(s); return; }
        if (numLeft != 0) {
            generateParenthesis(numLeft - 1, numRight, result, s + "(");
        }
        if (numRight > numLeft) {
            generateParenthesis(numLeft, numRight - 1, result, s + ")");
        }
    }
    
    public List<String> generateParenthesis(int n) {
        final List<String> result = new ArrayList<>();
        generateParenthesis(n, n, result, "");
        return result;
    }
}