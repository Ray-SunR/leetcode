class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        while (index < s.size()) {
            int begin, end;
            while (index < s.size() && s[index] == ' ') { index++; }
            begin = index;
            end = index;
            while (end < s.size() && s[end] != ' ') { end++; }
            
            std::reverse(s.begin() + begin, s.begin() + end);
            
            index = end + 1;
        }
        
        return s;
    }
    
    
};
