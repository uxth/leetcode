/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 *
 * https://leetcode.com/problems/adding-two-negabinary-numbers/description/
 *
 * algorithms
 * Medium (34.06%)
 * Likes:    124
 * Dislikes: 59
 * Total Accepted:    7.5K
 * Total Submissions: 21.8K
 * Testcase Example:  '[1,1,1,1,1]\n[1,0,1]'
 *
 * Given two numbers arr1 and arr2 in base -2, return the result of adding them
 * together.
 * 
 * Each number is given in array format:  as an array of 0s and 1s, from most
 * significant bit to least significant bit.  For example, arr = [1,1,0,1]
 * represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array
 * format is also guaranteed to have no leading zeros: either arr == [0] or
 * arr[0] == 1.
 * 
 * Return the result of adding arr1 and arr2 in the same format: as an array of
 * 0s and 1s with no leading zeros.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
 * Output: [1,0,0,0,0]
 * Explanation: arr1 represents 11, arr2 represents 5, the output represents
 * 16.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= arr1.length <= 1000
 * 1 <= arr2.length <= 1000
 * arr1 and arr2 have no leading zeros
 * arr1[i] is 0 or 1
 * arr2[i] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() >arr2.size()) swap(arr1, arr2);
        
        arr2.insert(arr2.begin(), 3, 0);
        for(int i = arr1.size() -1, j = arr2.size() - 1; j >= 0; i--, j--) {
            if(i >= 0) arr2[j] += arr1[i];
            if(arr2[j] == -1) {
                arr2[j] = 1;
                arr2[j - 1]++;
            }
            else if(arr2[j] == 2) {
                arr2[j] = 0;
                arr2[j - 1]--;
            }
            else if(arr2[j] == 3) {
                arr2[j] = 1;
                arr2[j - 1]--;
            }
        }
        
        while(arr2.front() == 0 && arr2.size() > 1) arr2.erase(arr2.begin());
        return arr2;
    }
};
// @lc code=end
// [1,0,0,0,0,1]\n[1]
// [1]\n[1]
// [1]\n[1,1]
// [1]\n[1,1,0,1]