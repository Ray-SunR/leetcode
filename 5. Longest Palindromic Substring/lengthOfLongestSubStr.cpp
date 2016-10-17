#include <unordered_map>
#include <iostream>

class Solution {
public:
typedef unordered_map<char, int> UMapChar;
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty()) { return 0; }

        int begin_pos = 0;
        int end_pos = 0;
        int maxLength = 1;
        UMapChar hash_table;
        int size = s.size();
        while (end_pos < size)
        {
            UMapChar::const_iterator result = hash_table.find(s[end_pos]);
            if (result != hash_table.end() && result->second >= begin_pos)
            {
                maxLength = maxLength > end_pos - begin_pos ? maxLength : end_pos - begin_pos;
                begin_pos = hash_table[s[end_pos]] + 1;
            }
            hash_table[s[end_pos]] = end_pos;
            end_pos++;
        }
        return maxLength > end_pos - begin_pos ? maxLength : end_pos - begin_pos;
    }
};


int main(void)
{
    using namespace std;
    Solution s;
    cout << "dvdf: " << s.lengthOfLongestSubstring("dvdf") << endl;
    cout << "aabcda: " << s.lengthOfLongestSubstring("aabcda") << endl;
    cout << "tffgummmtf: " << s.lengthOfLongestSubstring("tffgummmtf") << endl;
    return 0;
}