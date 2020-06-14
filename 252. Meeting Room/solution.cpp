/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include <vector>
#include <algorithm>

struct Interval {
     int start, end;
     Interval(int start, int end) {
         this->start = start;
         this->end = end;
     }
};

using namespace std;

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        std::sort(intervals.begin(), intervals.end(), [ ]( const Interval& lhs, const Interval& rhs )
        {
            return lhs.start < rhs.start;
        });
        int currentStart = -1;
        int currentEnd = -1;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start < currentEnd) {
                return false;
            }
            currentStart = intervals[i].start;
            currentEnd = intervals[i].end;
        }
        return true;
    }
};

int main(void) {
  
  return 0;
}
