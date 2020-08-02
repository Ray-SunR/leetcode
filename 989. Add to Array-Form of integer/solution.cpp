class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        int indexA = A.size() - 1;
        int carry = 0;
        while (indexA >= 0 || K) {
            int digit = K - K / 10 * 10;
            K /= 10;
            int val = indexA >= 0 ? digit + A[indexA] + carry : digit + carry;
            carry = val / 10;
            int remainder = val % 10;
            result.push_back(remainder);
            indexA--;
        }
        
        if (carry != 0) {
            result.push_back(carry);
        }
        
        std::reverse(result.begin(), result.end());

        return result;
    }
};
