class Solution {
    public int myAtoi(String str) {
        if (str.isEmpty()) {
            return 0;
        }
        int index = 0;
        boolean negative = false;
        while (index < str.length() && str.charAt(index) == ' ') { index++; }
        if (index == str.length()) { return 0; }
        if (str.charAt(index) == '-') { negative = true; index++; }
        else if (str.charAt(index) == '+') { index++; }
        int result = 0;
        while (index < str.length() && str.charAt(index) <= '9' && str.charAt(index) >= '0') {
            int val = str.charAt(index) - '0';
            long newResult = (long)result * 10 + val;
            if (negative ? Integer.MIN_VALUE > -newResult : Integer.MAX_VALUE < newResult) {
                return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            result = (int) newResult;
            index++;
        }
        return negative ? -result : result;
    }
}