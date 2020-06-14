class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1 || intervals.size() == 0) { return intervals; }
        
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& left, vector<int>& right) {
            return left[0] < right[0];
        });
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size()) {
            while (i < intervals.size() && intervals[i][0] <= result[result.size() - 1][1]) {
                result[result.size() - 1][1] = max(intervals[i][1], result[result.size() - 1][1]);
                i++;
            }
            if (i < intervals.size()) {
                result.push_back(intervals[i++]);
            }
        }
        return result;
    }
};
