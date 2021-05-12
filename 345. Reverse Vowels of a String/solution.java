class Solution {
    public String reverseVowels(String s) {
        int b = 0;
        int e = s.length() - 1;
        StringBuilder sb = new StringBuilder(s);
        while (b < e) {
            char bChar = s.charAt(b);
            char eChar = s.charAt(e);
            if (isVowels(bChar) && isVowels(eChar)) {
                char temp = bChar;
                sb.setCharAt(b, eChar);
                sb.setCharAt(e, temp);
                b++;
                e--;
            } else if (isVowels(bChar) && !isVowels(eChar)) {
                e--;
            } else if (!isVowels(bChar) && isVowels(eChar)) {
                b++;
            } else {
                b++;
                e--;
            }
        }
        return sb.toString();
    }
    
    private boolean isVowels(char c) {
        return c == 'a' || c =='A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
}
