/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (53.84%)
 * Likes:    936
 * Dislikes: 801
 * Total Accepted:    86.3K
 * Total Submissions: 160.3K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * 
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,2,3,1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 * Explanation: 
 * The degree is 3 because the element 2 is repeated 3 times.
 * So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int findShortestSubArray(vector<int>& nums) {
    //     unordered_map<int, int> m;
    //     int fre = 0;
    //     vector<int> degree;
    //     for(int i : nums)
    //     {
    //         ++m[i];
    //         if(m[i] > fre)
    //         {
    //             degree.clear();
    //             fre = m[i];
    //             degree.push_back(i);
    //         }
    //         else if(m[i] == fre)
    //         {
    //             degree.push_back(i);
    //         }
    //     }
    //     int res = INT_MAX;
    //     for(int num : degree)
    //     {
    //         int l = 0;
    //         while(l<nums.size() && nums[l] != num) l++;
    //         int r = nums.size() -1;
    //         while(r>=0 && nums[r] != num) r--;
    //         res= min(res, r-l+1);
    //     }
    //     return res;
    // }

    struct data{
        int key;
        int fre;
        int start;
        int end;
    };
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, data> m;
        for(int i=0; i<nums.size(); ++i)
        {
            if(m.count(nums[i]) == 0)
            {
                m[nums[i]].key = nums[i];
                m[nums[i]].fre = 1;
                m[nums[i]].start = i;
                m[nums[i]].end = i;
            }
            else
            {
                m[nums[i]].fre++;
                m[nums[i]].end = i;
            }
        }
        vector<data> v;
        for(auto& [key, d] : m) v.push_back(d);
        sort(v.begin(), v.end(), [](data& a, data& b){
            if(a.fre == b.fre) return a.end-a.start < b.end-b.start;
            return a.fre > b.fre;
        });
        return v.front().end - v.front().start + 1;
    }
};
// @lc code=end
// [2,1,1,2,1,3,3,3,1,3,1,3,2]
