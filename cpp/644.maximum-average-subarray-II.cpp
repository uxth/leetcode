/*

Description
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4

Output: 12.75

Explanation:

When length is 5, maximum average value is 10.8,

When length is 6, maximum average value is 9.16667.

Thus return 12.75.

Note:

1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.
Solution
Use binary search. Initialize min and max to be the minimum element in nums and the maximum element in nums, respectively. Each time calculate mid as the average of min and max, and maintain prevMid which stores the previous value of mid. After mid is calculated, check whether there exists a subarray of nums such that its average value is at least mid. If so, set min = mid. Otherwise, set max = mid. Then calculate the error as the absolute difference between mid and prevMid and set prevMid = mid. The binary search ends when the error does not exceed 10^-5. Finally, return min.

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double eps = 1e-5;
        double l = *min_element(nums.begin(), nums.end());
        double r = *max_element(nums.begin(), nums.end());
        auto check = [&](double v) {
            double s = 0;
            for (int i = 0; i < k; ++i) {
                s += nums[i] - v;
            }
            if (s >= 0) {
                return true;
            }
            double t = 0;
            double mi = 0;
            for (int i = k; i < nums.size(); ++i) {
                s += nums[i] - v;
                t += nums[i - k] - v;
                mi = min(mi, t);
                if (s >= mi) {
                    return true;
                }
            }
            return false;
        };
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};