class Solution { 
    private List<String> generate(final Character c, final List<String> combinations) {
        final List<String> KEYBOARD_2 = new ArrayList<String>() {{
        add(""); add("abc"); add("def"); add("ghi"); add("jkl"); add("mno"); add("pqrs"); add("tuv"); add("wxyz");
        }};
        final String chars = KEYBOARD_2.get(c - '1');
        if (combinations.isEmpty()) {
            final List<String> result = new ArrayList<>();
            for (char ch : chars.toCharArray()) {
                result.add(Character.toString(ch));
            }
            return result;
        }
        
        final List<String> result = new ArrayList<>();
        for (char ch : chars.toCharArray()) {
            for (final String s : combinations) {
                result.add(s + Character.toString(ch));
            }
        }
        return result;
    }

    public List<String> letterCombinations(String digits) {
        List<String> combinations = new ArrayList<>();
        for (int i = 0; i < digits.length(); i++) {
            combinations = generate(digits.charAt(i), combinations);
        }
        return combinations;
    }
}
