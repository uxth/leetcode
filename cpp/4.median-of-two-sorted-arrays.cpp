/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (30.62%)
 * Likes:    8890
 * Dislikes: 1369
 * Total Accepted:    831.8K
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * Follow up: The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int total = nums1.size() + nums2.size();
    //     if (total % 2 == 1) {
    //         return findKth(nums1, 0, nums2, 0, total / 2 + 1);
    //     } else {
    //         return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
    //     }
    // }
    // double findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
    //     if (nums1.size() - i > nums2.size() - j) return findKth(nums2, j, nums1, i, k);
    //     if (nums1.size() == i) return nums2[j + k - 1];
    //     if (k == 1) return min(nums1[i], nums2[j]);
    //     int pa = min(i + k / 2, int(nums1.size())), pb = j + k - pa + i;
    //     if (nums1[pa - 1] < nums2[pb - 1]) 
    //         return findKth(nums1, pa, nums2, j, k - pa + i);
    //     else if (nums1[pa - 1] > nums2[pb - 1]) 
    //         return findKth(nums1, i, nums2, pb, k - pb + j);
    //     else 
    //         return nums1[pa - 1];
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) {
            return 0;
        }
        
        int length = nums1.size() + nums2.size();
        int i1 = 0;
        int i2 = 0;
        double median = 0;
        double medianMinus1 = 0;
        for (int pos = 0; pos <= length/2; ++pos) {
            if (i1 < nums1.size() && i2 < nums2.size()) {
                if (nums1[i1] <= nums2[i2]) {
                    medianMinus1 = median;
                    median = nums1[i1];
                    ++i1;
                } else {
                    medianMinus1 = median;
                    median = nums2[i2];
                    ++i2;
                }
            } else if (i1 < nums1.size()) {
                medianMinus1 = median;
                median = nums1[i1];
                ++i1;
            } else {
                medianMinus1 = median;
                median = nums2[i2];
                ++i2;
            }
        } 
        return length % 2 == 0 ? (median + medianMinus1)/2 : median;
    }
};
// @lc code=end
// [0,0]\n[1,1]
