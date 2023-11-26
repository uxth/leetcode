/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (61.21%)
 * Likes:    3819
 * Dislikes: 231
 * Total Accepted:    474K
 * Total Submissions: 768.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> m;
    //     for(int n : nums) ++m[n];
    //     vector<pair<int,int>> data(m.begin(), m.end());
    //     sort(data.begin(), data.end(), [](auto& a, auto& b){return a.second > b.second;});
    //     vector<int> res;
    //     for(int i=0; i<k && i<data.size(); ++i) res.push_back(data[i].first);
    //     return res;
    // }

    vector<int> topKFrequent(vector<int> &nums, int k) {
      int size = nums.size();
      unordered_map<int, int> numMap;
      for (int n : nums) 
        ++numMap[n];
      vector<vector<int>> freqGroups(size + 1);
      for (auto pair : numMap) 
        freqGroups[pair.second].push_back(pair.first);
      vector<int> result;
      for (int i = size; i >= 0; --i)
        for (int num : freqGroups[i])
          if (result.size() < k)
            result.push_back(num);

      return result;
    }
};
// @lc code=end

