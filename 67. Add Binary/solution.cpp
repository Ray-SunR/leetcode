class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) { return addBinary(b, a); }
        
        string ret;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            int val = a[i] - '0' + b[j] - '0' + carry;
            if (val == 0) {
                ret.insert(ret.begin(), '0');
                carry = 0;
            } else if (val == 1) {
                ret.insert(ret.begin(), '1');
                carry = 0;
            } else if (val == 2) {
                ret.insert(ret.begin(), '0');
                carry = 1;
            } else if (val == 3) {
                ret.insert(ret.begin(), '1');
                carry = 1;
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (carry == 1) {
                if (a[i] == '0') {
                    ret.insert(ret.begin(), '1');
                    carry = 0;
                } else {
                    ret.insert(ret.begin(), '0');
                    carry = 1;
                }
            } else {
                ret.insert(ret.begin(), a[i]);
            }
            
            i--;   
        } 
        
        if (carry == 1) {
            ret.insert(ret.begin(), '1');
        }
        
        return ret;
    }
};
