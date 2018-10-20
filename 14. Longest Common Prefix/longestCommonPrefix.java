class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) { return ""; }
        String result = strs[0];
        int index = 1;
        while (index < strs.length) {
            if (!strs[index].startsWith(result)) {
                if (result.length() == 1) { return ""; }
                result = result.substring(0, result.length() - 1);
            } else {
                index++;
            }
        }
        return result;
    }
}