class Solution {
public:
//     vector<vector<int>> intervalIntersection1(vector<vector<int>>& A, vector<vector<int>>& B) {
//         A.insert(A.end(), B.begin(), B.end());
//         std::sort(A.begin(), A.end(), [](const vector<int> & a, const vector<int> & b) -> bool {
//             if (a[0] == b[0]) {
//                 return a[1] < b[1];
//             }
//             return a[0] < b[0];
//         });
        
//         vector<vector<int>> result;
//         int index = 1;
//         int targetIndex = 0;
//         while (index < A.size()) {
//             if (A[index][0] <= A[targetIndex][1]) {
//                 vector<int> ret;
//                 ret.push_back(max(A[index][0], A[targetIndex][0])); 
//                 ret.push_back(min(A[targetIndex][1], A[index][1]));
//                 result.push_back(ret);
//                 if (!(A[targetIndex][0] <= A[index][0] && A[targetIndex][1] >= A[index][1])) {
//                     targetIndex = index;
//                 }
//             } else {
//                 targetIndex = index;
//             }
            
//             index++;
//         }
        
//         return result;
//     }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int indexA = 0;
        int indexB = 0;
        vector<vector<int>> result;

        while (indexA < A.size() && indexB < B.size()) {
            int lower = max(A[indexA][0], B[indexB][0]);
            int higher = min(A[indexA][1], B[indexB][1]);
            if (higher >= lower) {
                result.push_back({lower, higher});
            }
            
            if (A[indexA][1] > B[indexB][1]) {
                indexB++;
            } else {
                indexA++;
            }
        }
        
        return result;
    }
};
