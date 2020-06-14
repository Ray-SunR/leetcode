 /* Defiion of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

#include <iostream>
#include <algorithm>
#include <queue>

struct Interval {
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Compare
{
public:
    bool operator() (const Interval& lhs, const Interval& rhs)
    {
        return lhs.end - rhs.end > 0;
    }
};

using namespace std;

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        std::priority_queue<Interval, std::vector<Interval>, Compare> pq;
        std::sort(intervals.begin(), intervals.end(), [] (const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        
        int count = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (!pq.empty()) {
                const Interval& top = pq.top();
                if (intervals[i].start < top.end) {
                    count++;
                } else {
                    pq.pop();
                }
            } else {
                count++;
            }
            pq.push(intervals[i]);
        }
        
        return count;
    }
};

int main(void) {
  return 0;
}
