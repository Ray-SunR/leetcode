class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0;
        while (index < gas.size() && gas[index] < cost[index]) {
            index++;
        }
        while (index < gas.size()) {
            bool ok = true;
            int tank = 0;
            int i = index;
            do {
                tank += gas[i % gas.size()];
                tank -= cost[i % gas.size()];
                if (tank < 0) {
                    ok = false;
                    break;
                }
                i++;
            } while (i % gas.size() != index);
            
            if (ok) { return index; }
            
            index++;
        }
        return -1;
    }
};
