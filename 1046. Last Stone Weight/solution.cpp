class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        // cout << pq.top() << endl;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            // cout << "pop: " << a << " and " << b << endl;
            if (a < b) {
                pq.push(b - a);
                // cout << "push: " << b - a << endl;
            } else if (a > b) {
                pq.push(a - b);
                // cout << "push: " << a - b << endl;
            }
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};
