/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 *
 * https://leetcode.com/problems/pancake-sorting/description/
 *
 * algorithms
 * Medium (67.51%)
 * Likes:    613
 * Dislikes: 811
 * Total Accepted:    48.7K
 * Total Submissions: 71.5K
 * Testcase Example:  '[3,2,4,1]'
 *
 * Given an array of integers arr, sort the array by performing a series of
 * pancake flips.
 * 
 * In one pancake flip we do the following steps:
 * 
 * 
 * Choose an integer k where 1 <= k <= arr.length.
 * Reverse the sub-array arr[1...k].
 * 
 * 
 * For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k =
 * 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake
 * flip at k = 3.
 * 
 * Return the k-values corresponding to a sequence of pancake flips that sort
 * arr. Any valid answer that sorts the array within 10 * arr.length flips will
 * be judged as correct.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,2,4,1]
 * Output: [4,2,4,3]
 * Explanation: 
 * We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 * Starting state: arr = [3, 2, 4, 1]
 * After 1st flip (k = 4): arr = [1, 4, 2, 3]
 * After 2nd flip (k = 2): arr = [4, 1, 2, 3]
 * After 3rd flip (k = 4): arr = [3, 2, 1, 4]
 * After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
 * Notice that we return an array of the chosen k values of the pancake
 * flips.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,3]
 * Output: []
 * Explanation: The input is already sorted, so there is no need to flip
 * anything.
 * Note that other answers, such as [3, 3], would also be accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 100
 * 1 <= arr[i] <= arr.length
 * All integers in arr are unique (i.e. arr is a permutation of the integers
 * from 1 to arr.length).
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for(int i=arr.size()-1; i>=0; --i)
        {
            int target = i+1;
            if(arr[i] == target) continue;
            int j=0;
            while(j<arr.size() && arr[j]!=target) j++;
            res.push_back(j+1);
            reverse(arr.begin(), arr.begin()+j+1);
            res.push_back(i+1);
            reverse(arr.begin(), arr.begin()+i+1);
        }
        return res;
    }
};
// @lc code=end

