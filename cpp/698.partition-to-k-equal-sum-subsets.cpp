/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (44.95%)
 * Likes:    1952
 * Dislikes: 120
 * Total Accepted:    90K
 * Total Submissions: 200.1K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>& nums, int pos, vector<int>& targets, int met)
    {
        if(met == targets.size()) return true;
        
        for(int i=0; i<targets.size(); ++i)
        {
            if(targets[i] >= nums[pos])
            {
                targets[i] -= nums[pos];
                met += targets[i] == 0 ? 1 : 0;
                if(dfs(nums, pos+1, targets, met)) return true;
                met -= targets[i] == 0 ? 1 : 0;
                targets[i] += nums[pos];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(),nums.end(), greater<int>());
        vector<int> targets(k, target);
        
        return dfs(nums, 0, targets, 0);
    }

    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    bool bfs(vector<int>& nums, int k, int target)
    {
        queue<vector<int>> q;
        q.push(vector<int>(k, 0));
        for(int n : nums)
        {
            int size = q.size(); 
            while(size--)
            {
                vector<int>& f = q.front();
                for(int i=0; i<f.size(); ++i)
                {
                    if(f[i] + n > target) continue;
                    vector<int> tmp = f;
                    tmp[i] += n;
                    q.push(tmp);
                }
                q.pop();
            }
        }

        while(!q.empty())
        {
            if(all_of(q.front().begin(), q.front().end(), [&](int i){return i==target;}))
                return true;
            q.pop();
        }
        return false;
    }
};
// @lc code=end

// [10,10,10,7,7,7,7,7,7,6,6,6]\n3
// [5,2,5,5,5,5,5,5,5,5,5,5,5,5,5,3]\n15
// [1739,5391,8247,236,5581,11,938,58,1884,823,686,1760,6498,6513,6316,2867]\n6
// [2,2,2,2,3,4,5]\n4
// [7628, 3147, 7137, 2578, 7742, 2746, 4264, 7704, 9532, 9679, 8963, 3223, 2133, 7792, 5911, 3979]\n6