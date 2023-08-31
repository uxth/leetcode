/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (63.48%)
 * Likes:    4332
 * Dislikes: 112
 * Total Accepted:    651.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
template<typename It>
    bool next_permutation(It begin, It end)
    {
        if (begin == end) return false;

        It i = begin;
        ++i;
        if (i == end) return false;

        i = end;
        --i;

        while (true)
        {
            It j = i;
            --i;

            if (*i < *j)
            {
                It k = end;
                while (!(*i < *--k)) /* pass */;
                iter_swap(i, k);
                reverse(j, end);
                return true;
            }

            if (i == begin)
            {
                reverse(begin, end);
                return false;
            }
        }
    }
    bool my_permutation2(vector<int>& nums)
    {
        if(nums.size() <= 1) return false;
        int i=nums.size()-1;
        while(i>0 && nums[i] <= nums[i-1]) i--;
        if(i>0)
        {
            int j=nums.size()-1;
            while(nums[j]<=nums[i-1])--j;
            swap(nums[j], nums[i-1]);
        }
        int left = i, right = nums.size()-1;
        while(left<right)
            swap(nums[left++], nums[right--]);
        return i!=0;
    }
    bool nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0 && nums[i]<=nums[i-1])--i;
        if(i==0) {reverse(nums.begin(), nums.end());return false;}
        int j = nums.size()-1;
        while(j>i && nums[j]<=nums[i-1]) --j;
        swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
    bool nextPermutationForString(string str)
    {
        int i = str.size()-1;
        while(i>0 && str[i]<=str[i-1])--i;
        if(i==0)
        {
            reverse(str.begin(), str.end());
            return false;
        }
        int j = str.size()-1;
        while(j>i && str[j]<=str[i-1]) --j;
        swap(str[i-1], str[j]);
        reverse(str.begin()+i, str.end());
        return true;
    }
    void dfs(string& input, string& str, vector<bool>& flag, vector<string>& res)
    {
        if(str.size() == input.size())
        {
            res.push_back(str);
            return;
        }
        for(int i=0;i<input.size(); ++i)
        {
            if(flag[i]) continue;

            flag[i]= true;
            str.push_back(input[i]);
            dfs(input, str, flag, res);
            str.pop_back();
            flag[i]= false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do
        {
            res.push_back(nums);
        }while(nextPermutation(nums));
        return res;
    }
};
// @lc code=end

