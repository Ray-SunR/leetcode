/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    typedef unordered_map<int, int> UMapInt;
    void Helper(vector<int>& result, UMapInt::const_iterator& first, UMapInt::const_iterator& sec)
    {
        if (first->second > sec->second)
        {
            result.push_back(sec->second + 1);
            result.push_back(first->second + 1);
        }
        else
        {
            result.push_back(first->second + 1);
            result.push_back(sec->second + 1);
        }
    }
    
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> result;
        UMapInt umap;
        for (int i = 0;i < nums.size(); i++)
        {
            UMapInt::const_iterator jt = umap.find(target - nums[i]);
            if (jt == umap.end())
            {
                umap[target - nums[i]] = i;
            }
            else if (jt->first * 2 == target)
            {
                // Key conflicts meaning that's the answer
                if (jt->second < i)
                {
                    result.push_back(jt->second + 1);
                    result.push_back(i + 1);
                }
                else
                {
                    result.push_back(i + 1);
                    result.push_back(jt->second + 1);
                }
                return result;
            }
            
            UMapInt::const_iterator other = umap.find(nums[i]);
            UMapInt::const_iterator that = umap.find(target - nums[i]);
            if (other != that && other != umap.end() && that != umap.end())
            {
                // Found it
                Helper(result, other, that);
                return result;
            }
        }
        return result;
    }
};

int main(void)
{
    int inputArray[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
    vector<int> input(inputArray, inputArray + sizeof(inputArray) / sizeof(inputArray[0]));
    Solution s;
    std::vector<int> result = s.twoSum(input, 542);
    std::cout << result[0] << ", " << result[1] << std::endl;
    return 0;
}
