class Solution {
public:
    struct CharFreq {
        char c;
        int freq;
        
        CharFreq(char c, int freq):c(c), freq(freq) {}
    };
    
    string customSortString(string S, string T) {
        map<char, int> hash;
        for (int i = 0; i < S.size(); i++) {
            hash[S[i]] = i;
        }
        
        vector<CharFreq> result(26, CharFreq('#', 0));
        
        string noMapping;
        for (int i = 0; i < T.size(); i++) {
            if (hash.find(T[i]) != hash.end()) {
                CharFreq value = result[hash[T[i]]];
                value.c = T[i];
                value.freq++;
                result[hash[T[i]]] = value;
            } else {
                noMapping.push_back(T[i]);
            }
        }
        
        string resultString;
        for (int i = 0; i < result.size(); i++) {
            while (result[i].freq != 0) {
                resultString.push_back(result[i].c);
                result[i].freq--;
            }
        }
        
        return resultString + noMapping;
    }
};
