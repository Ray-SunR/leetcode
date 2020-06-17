class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < manager.size(); i++) {
            hash[manager[i]].push_back(i);
        }
        
        int maxResult = 0;
        helper(headID, maxResult, hash, informTime);
        return maxResult;
    }
    
    int helper(int headID, int& maxResult, unordered_map<int, vector<int>>& hash, vector<int>& informTime) {
        int localMax = INT_MIN;
        if (hash.find(headID) == hash.end()) {
            return 0;
        }
        const vector<int>& children = hash[headID];
        for (int i = 0; i < children.size(); i++) {
            int myMax = helper(children[i], maxResult, hash, informTime);
            // cout << "headID: " << headID << " i: " << i << " max: " << myMax << endl;
            localMax = max(localMax, informTime[headID] + myMax);
        }
        maxResult = max(maxResult, localMax);

        // cout << "headID: " << headID << " localMax: " << (!flag ? 0 : localMax) << endl;
        
        return localMax;
    }
};
