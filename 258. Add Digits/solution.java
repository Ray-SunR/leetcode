class Solution {
    public int addDigits(int num) {
        String s = Integer.toString(num);
        if (s.length() == 1) {
            return num;
        }
        
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result += s.charAt(i) - '0';
        }
        return addDigits(result);
    }
}
