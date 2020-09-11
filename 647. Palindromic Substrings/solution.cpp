class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 1; i < 2 * s.size() + 1; i++) {
            extend(count, s, (i - 1) / 2, i / 2);
        }
        return count;
    }

    void extend(int& count, const string& s, int leftIndex, int rightIndex) {
        while (leftIndex >= 0 && rightIndex < s.size() && s[leftIndex] == s[rightIndex]) {
            count++;
            leftIndex--;
            rightIndex++;
        }
    }
};
