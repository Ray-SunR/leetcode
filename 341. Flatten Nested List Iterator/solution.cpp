/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> values;
    int index;
    vector<int> helper(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                // cout << nestedList[i].getInteger() << endl;
                result.push_back(nestedList[i].getInteger());
            } else {
                vector<int> helperResult = helper(nestedList[i].getList());
                result.insert(result.end(), helperResult.begin(), helperResult.end());
            }
        }
        return result;
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->values = this->helper(nestedList);
        this->index = 0;
    }
    
    int next() {
        return values[index++];
    }
    
    bool hasNext() {
        return index < values.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
