/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (67.69%)
 * Likes:    717
 * Dislikes: 48
 * Total Accepted:    61.9K
 * Total Submissions: 91.5K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * Constraints:
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    //     int key[1001], idx = 0;
    //     for (int i = 0; i < 1001; i++) key[i] = 1000+i;
    //     for (int b : arr2) key[b] = idx++;
    //     sort(arr1.begin(), arr1.end(), [key](int c, int d){
    //         return key[c] < key[d];
    //     });
    //     return arr1;
    // }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0}; // since numbers are from [0, 1000]
        for (int& num : arr1) count[num]++;

        int i = 0;
        // To follow the same ordering of arr2
        for (int& num : arr2) {
            while (count[num]-- > 0)
                arr1[i++] = num;
        }

        // For remaining elements that were not in arr2
        for (int j = 0; j < 1001; j++) {
            while (count[j]-- > 0) {
                arr1[i++] = j;
            }
        }

        return arr1;
    }
};
// @lc code=end

