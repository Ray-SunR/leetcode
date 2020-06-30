class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return transform(S) == transform(T);
    }
    
    string transform(string& s) {
        string newS;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (newS.size() != 0) {
                    newS.pop_back();    
                }
            } else {
                newS.push_back(s[i]);
            }
        }
        return newS;
    }
};
