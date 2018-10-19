class Solution {
    public boolean isPalindrome(int x) {
        if (x == 0) { return true; }
        if (x < 0 || x % 10 == 0) { return false;}
        int result = 0;
        while (x != 0) {
            int remains = x % 10;
            result = result * 10 + remains;
            if (result == x || result == x / 10) {
                return true;
            } else if (result / x > 10) {
                return false;
            }
            x = x / 10;
        }
        return false;
    }
    
    private boolean isPalindrome(final String str) {
        int left = (str.length() - 1) / 2;
        int right = (str.length()) / 2;
        while (left >=0 && right < str.length() && str.charAt(left) == str.charAt(right)) {
            left--;
            right++;
        }
        return left == -1 && right == str.length();
    }
}
