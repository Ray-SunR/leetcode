class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Map for mapping char and char index
        final Map<Character, Integer> hash = new HashMap<>();
        int begin = 0;
        int index = 0;
        int max = 0;
        while (index < s.length()) {
            if (hash.containsKey(s.charAt(index))) {
                int lastRepeatedIndex = hash.get(s.charAt(index));
                max = index - begin > max ? index - begin : max;
                begin = begin < lastRepeatedIndex + 1 ? lastRepeatedIndex + 1 : begin;
            }
            hash.put(s.charAt(index), index);
            index++;
        }
        return index - begin > max ? index - begin : max;
    }
}

// The below solution has an idea of:
// "abcda", this is a typical repeated string, as soon as we see the second 'a', we know, it's time
// to calculate the length, thus, 'begin' pointer always points to the first repeated substring
// thus, in hashset, we remove that char.
// class Solution {
//     public int lengthOfLongestSubstring(String s) {
//         final HashSet<Character> hash = new HashSet<>();
//         int result = 0;
        
//         int begin = 0;
//         int index = 0;
//         while (index < s.length()) {
//             if (!hash.contains(s.charAt(index))) {
//                 hash.add(s.charAt(index++));
//                 result = hash.size() > result ? hash.size() : result;
//             } else {
//                 hash.remove(s.charAt(begin++));
//             }
//         }
//         return result;
//     }
// }