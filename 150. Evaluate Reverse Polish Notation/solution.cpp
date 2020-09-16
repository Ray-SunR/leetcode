class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (int i = 0; i < tokens.size(); i++) {
            // cout << "i: " << i << endl;
            // cout << "size: " << stk.size() << endl;
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stk.push(stoi(tokens[i]));
            } else if (tokens[i] == "+") {
                int val1 = stk.top(); stk.pop(); 
                int val2 = stk.top(); stk.pop();
                
                stk.push(val1 + val2);
            } else if (tokens[i] == "-") {
                int val1 = stk.top(); stk.pop(); 
                int val2 = stk.top(); stk.pop();
                
                stk.push(val2 - val1);
            } else if (tokens[i] == "*") {
                int val1 = stk.top(); stk.pop(); 
                int val2 = stk.top(); stk.pop();
                
                stk.push(val1 * val2);
            } else if (tokens[i] == "/") {
                int val1 = stk.top(); stk.pop(); 
                int val2 = stk.top(); stk.pop();
                
                stk.push(val2 / val1);
            }
            // cout << "top: " << stk.top() << endl;
        }
        
        return stk.top();
    }
};
