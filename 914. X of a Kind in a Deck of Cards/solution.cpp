class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // cout << gcd(1, 3) << endl;
        unordered_map<int, int> hash;
        int min_group_size = INT_MAX;
        for (int i = 0; i < deck.size(); i++) {
            hash[deck[i]]++;
        }
        
        int ret = hash.begin()->second;
        unordered_map<int, int>::const_iterator it = hash.begin();
        while (it != hash.end()) {
            ret = gcd(it->second, ret);
            ++it;
        }
        
        return ret >= 2;
    }
    
    int gcd(int a, int b) {
        int r;
        while ((a % b) > 0) {
            r = a % b;
            a = b;
            b = r;
        }
        
        return b;
    }
};
