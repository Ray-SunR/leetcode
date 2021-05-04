class Solution {
    public int calculate(String s) {
        s = s.replace(" ", "");
        int i = 0;
        String number = "";
        Stack<Integer> numbers = new Stack<>();
        Stack<Character> operator = new Stack<>();
        while (i < s.length()) {
            if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {
                number += s.charAt(i);
            } else {
                if (!number.isEmpty()) {
                    numbers.push(Integer.parseInt(number));
                    // System.out.println("pushed: " + numbers.peek());
                    number = "";
                }
                if (s.charAt(i) == '(') {
                    operator.push(s.charAt(i));
                } else if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                    if (i - 1 < 0 || s.charAt(i - 1) == '+' || s.charAt(i - 1) == '-' || s.charAt(i - 1) == '(') {
                        // System.out.println("pushed: 0");
                        numbers.push(0);
                    }
                    
                    if (!operator.isEmpty() && operator.peek() != '(') {
                        evaluate(operator, numbers);
                        // continue;
                    }
                    
                    // System.out.println("pushed: " + s.charAt(i));
                    operator.push(s.charAt(i));
                } else if (s.charAt(i) == ')') {
                    while (operator.peek() != '(') {
                       evaluate(operator, numbers);
                    }
                    operator.pop();
                }
            }
            i++;
        }
        if (!number.isEmpty()) {
            numbers.push(Integer.parseInt(number));
        }
        while (!operator.isEmpty()) {
            evaluate(operator, numbers);
        }
        return numbers.peek();
    }
    
    private void evaluate(Stack<Character> operator, Stack<Integer> numbers) {
        Character c = operator.pop();
        Integer num1 = numbers.pop();
        Integer num2 = numbers.pop();
        if (c == '+') {
            // System.out.println("calculate " + num1 + " + " + num2);
            numbers.push(num1 + num2);
        } else {
            // System.out.println("calculate " + num2 + " - " + num1);
            numbers.push(num2 - num1);
        }
    }
}
