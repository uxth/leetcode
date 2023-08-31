/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    2127
 * Dislikes: 63
 * Total Accepted:    370.4K
 * Total Submissions: 791K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
    bool my_permutation(vector<int>& nums)
    {
        if(nums.size() <= 1) return false;
        int i = nums.size()-1;
        while(true)
        {
            int j=i--;
            if(nums[i] < nums[j])
            {
                int k=nums.size()-1;
                while(!(k>=0 && nums[k] > nums[i])) k--;
                swap(nums[i], nums[k]);
                int left = j, right = nums.size()-1;
                while(left<right) swap(nums[left++], nums[right--]);
                return true;
            }

            if(i==0)
            {
                int left = 0; int right = nums.size()-1;
                while(left<right) swap(nums[left++], nums[right--]);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do
        {
            // for(int i:nums)cout<<i; cout<<endl;
            res.push_back(nums);
        } while (nextPermutation(nums));
        return res;
    }
};
// @lc code=end
// [1,2,3,4,5]

