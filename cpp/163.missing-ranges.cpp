/*
You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the shortest sorted list of ranges that exactly covers all the missing numbers. That is, no element of nums is included in any of the ranges, and each missing number is covered by one of the ranges.

 

 

Example 1:

Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
Example 2:

Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.
 

Constraints:

-109 <= lower <= upper <= 109
0 <= nums.length <= 100
lower <= nums[i] <= upper
All the values of nums are unique.
*/
/*
https://leetcode.ca/2016-05-11-163-Missing-Ranges/

*/


class Solution {
    string formatRange(int lower, int upper) {
        if (lower == upper) return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& A, int lower, int upper) {
        vector<string> ans;
        int i = lower, j = 0, N = A.size();
        while (j < N) {
            if (i == A[j]) {
                ++i;
                ++j;
            } else {
                int first = i, last = A[j] - 1;
                ans.push_back(formatRange(first, last));
                i = A[j++] + 1;
            }
        }
        if (i <= upper) ans.push_back(formatRange(i, upper));
        return ans;
    }

    vector<string> find(vector<int>& A, int lower, int upper){
        vector<string> res;
        long long l = (long long)lower;
        long long u = (long long)upper;
        for(int num : A) {
            if(l == num){
                l++;
            }else if(l < num){
                if(l + 1 == num){
                    res.push_back(to_string(l));
                }else{
                    res.push_back(to_string(l) + "->" + to_string(num - 1));
                }
                l = num + 1;
            }
        }
        if(l == u) res.push_back(to_string(l));
        else res.push_back(to_string(l) + "->" + to_string(u));
        return res;
    }
};