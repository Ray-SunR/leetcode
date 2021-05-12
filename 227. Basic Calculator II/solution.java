class Solution {
    public int calculate(String s) {
        Stack<Integer> nums = new Stack<>();
        Stack<Character> operators = new Stack<>();
        String num = "";
        s = s.replace(" ", "");
        int i = 0;
        boolean isPositive = true;
        while (i < s.length()) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                num += s.charAt(i);
            } else {
                if (!num.isEmpty()) {
                    nums.push(isPositive ? Integer.parseInt(num) : -Integer.parseInt(num));
                    num = "";
                    isPositive = true;
                }
                
                if (s.charAt(i) == '+') {
                    isPositive = true;
                    if (!operators.isEmpty() && (operators.peek() == '*' || operators.peek() == '/')) {
                        evaluate(nums, operators);
                    }
                    operators.push(s.charAt(i));
                } else if (s.charAt(i) == '-') {
                    isPositive = isPositive ? false : true;
                    if (!operators.isEmpty() && (operators.peek() == '*' || operators.peek() == '/')) {
                        evaluate(nums, operators);
                    }
                    operators.push(s.charAt(i));
                } else if (s.charAt(i) == '*' || s.charAt(i) == '/') {
                    if (!operators.isEmpty() && (operators.peek() == '*' || operators.peek() == '/')) {
                        evaluate(nums, operators);
                    }
                    operators.push(s.charAt(i));
                }
            }
            i++;
        }
        if (!num.isEmpty()) {
            nums.push(isPositive ? Integer.parseInt(num) : -Integer.parseInt(num));
        }
        while (!operators.isEmpty()) {
            evaluate(nums, operators);
        }
        return nums.pop();
    }
    
    private void evaluate(Stack<Integer> nums, Stack<Character> operators) {
        Character c = operators.pop();
        Integer num1 = nums.pop();
        Integer num2 = nums.pop();
        System.out.println("num1: " + num1 + "num2: " + num2 + " operator: " + c);
        if (c == '*') {
            nums.push(num1 * num2);
        } else if (c == '+' || c == '-') {
            nums.push(num1 + num2);
        // } else if (c == '-') {
            // nums.push(num2 - num1);
        } else if (c == '/') {
            nums.push(num2 / num1);
        }
    }
}
