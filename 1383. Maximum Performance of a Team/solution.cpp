class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // efficiency, speed
        vector<pair<int, int>> engineers;
        for (int i = 0; i < efficiency.size(); i++) {
            engineers.push_back(std::make_pair(efficiency[i], speed[i]));
        }
        
        std::sort(engineers.begin(), engineers.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.first > b.first; });
        
        // for (int i = 0; i < engineers.size(); i++) {
        //     cout << engineers[i].first << "," << engineers[i].second << endl;
        // }
        priority_queue<int, vector<int>, greater<int>> pq;
                                                                  
        // now the engineers are sorted by efficiency.
        int i = 0;
        long speed_sum = 0;
        long min_efficiency = INT_MAX;
        long max_performance = INT_MIN;
        while (pq.size() != k) {
            speed_sum += engineers[i].second;
            min_efficiency = min(min_efficiency, (long) engineers[i].first);
            max_performance = max(max_performance, speed_sum * min_efficiency);
            pq.push(engineers[i].second);
            // cout << "pushed: " << engineers[i].second << endl;
            i++;
        }
        
        // cout << "top: " << pq.top() << endl;
        // cout << "max_performance: " << max_performance << endl;
        while (i < engineers.size()) {
            int speed = pq.top();
            pq.pop();
            pq.push(engineers[i].second);
            speed_sum = speed_sum - speed + engineers[i].second;
            max_performance = max(max_performance, speed_sum * engineers[i].first);
            i++;
        }
        
        return (int) (max_performance % 1000000007);
    }
};
