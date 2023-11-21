/*

Description
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9

Output: 0.500000

Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.
Solution
Use binary search. Sort stations and initialize low to 0 and high to the difference between the maximum element in stations and the minimum element in stations. While high - low > 1e-6, do binary search. Each time set mid to be the average of low and high and use mid as a candidate of D to calculate the minimum number of gas stations to be added. If the minimum number of gas stations to be added is less than or equal to K, then set high = mid. Otherwise, set low = mid. Finally, return low.

*/

// OJ: https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// Time: O(N * (logN + logM))
// Space: O(1)
class Solution {
    bool valid(vector<int> &A, double M, int k) {
        for (int i = 1; i < A.size(); ++i) {
            k -= (int)((A[i] - A[i - 1]) / M);
            if (k < 0) return false;
        }
        return true;
    }
public:
    double minmaxGasDist(vector<int>& A, int k) {
        double L = 0, R = 1e8, eps = 1e-6;
        while (R - L >= eps) {
            double M = (L + R) / 2;
            if (valid(A, M, k)) R = M;
            else L = M;
        }
        return L;
    }
};