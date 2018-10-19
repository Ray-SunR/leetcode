class Solution {
    public String longestPalindrome(String s) {
    	if (s.isEmpty()) {
    		return "";
    	} else if (s.length() == 1) {
    		return s;
    	}

    	int maxBeginIndex = 0;
    	int maxEndIndex = 0;
        for (int size = 1; size <= 2 * s.length() + 1; size++) {
        	final Result result = expandPalindrome(s, (size - 1) / 2, size / 2);
        	if (result.endIndex - result.beginIndex > maxEndIndex - maxBeginIndex) {
        		maxBeginIndex = result.beginIndex;
        		maxEndIndex = result.endIndex;
        	}
        }
        return s.substring(maxBeginIndex, maxEndIndex + 1);
    }
    
    private Result expandPalindrome(String s, int l, int r) {
        while (l >=0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--; r++;
        }
        
        final Result result = new Result();
        result.beginIndex = l + 1;
        result.endIndex = r - 1;
        return result;
    }
    
    private class Result {
        int beginIndex;
        int endIndex;
    }
}