class Solution {
    public int reverse(int x) {
        int result = 0;
        int magnitude = 10;
        boolean isNegtive = x < 0;
        x = x < 0 ? -x : x;
        while (x != 0) {
            int remains = x % 10;
            x = x / 10;
            int newResult = result * magnitude + remains;
            if ((newResult - remains) / magnitude != result) {
                return 0;
            }
            result = newResult;
        }
        return isNegtive ? -result : result;
    }
}