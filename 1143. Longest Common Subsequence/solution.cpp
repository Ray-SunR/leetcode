class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int> > d(text1.size() + 1, vector<int>(text2.size() + 1, 0));  
        return helper(text1, text1.size() - 1, text2, text2.size() - 1, d);
    }
    
    int helper(string& a, int m, string& b, int n, vector<vector<int>>& d) {
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (a[i] == b[j]) {
                    d[i][j] = 1 + d[i + 1][j + 1];
                } else {
                    d[i][j] = max(d[i + 1][j], d[i][j + 1]);
                }
            }
        }
        return d[0][0];
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
//     void print(vector<vector<int>>& d) {
//         for (int i = 0; i < d.size(); i++) {
//             for (int j = 0; j < d[i].size(); j++) {
//                 cout << d[i][j] << " "
//             }
//             cout << endl;
//         }
//         cout << "-----" << endl;
//     }
};
