/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (52.10%)
 * Likes:    950
 * Dislikes: 74
 * Total Accepted:    47.3K
 * Total Submissions: 90.3K
 * Testcase Example:  '[3,6,7,11]\r\n8\r'
 *
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has
 * piles[i] bananas.  The guards have gone and will come back in H hours.
 *
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she
 * chooses some pile of bananas, and eats K bananas from that pile.  If the
 * pile has less than K bananas, she eats all of them instead, and won't eat
 * any more bananas during this hour.
 *
 * Koko likes to eat slowly, but still wants to finish eating all the bananas
 * before the guards come back.
 *
 * Return the minimum integer K such that she can eat all the bananas within H
 * hours.
 *
 *
 * Example 1:
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 * Example 2:
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 * Example 3:
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23
 *
 *
 * Constraints:
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            long long timeNeeded = 0;
            for (int i : piles)
                timeNeeded += ceil((double)i / mid);

            if (timeNeeded > H)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
// @lc code=end
// [30,11,23,4,20]\n5
// [30,11,23,4,20]\n6
/*
[1000000000]\n2
[805306368,805306368,805306368]\n1000000000
*/