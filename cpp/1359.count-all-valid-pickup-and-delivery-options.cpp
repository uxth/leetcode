/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 *
 * https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/
 *
 * algorithms
 * Hard (57.91%)
 * Likes:    191
 * Dislikes: 21
 * Total Accepted:    7K
 * Total Submissions: 12K
 * Testcase Example:  '1'
 *
 * Given n orders, each order consist in pickup and delivery services. 
 * 
 * Count all valid pickup/delivery possible sequences such that delivery(i) is
 * always after of pickup(i). 
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup
 * 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 6
 * Explanation: All possible orders: 
 * (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1)
 * and (P2,D2,P1,D1).
 * This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery
 * 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: 90
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 500
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        // DP思路：当n1=1时， res1=1
        // 当n2=2，结果为(3+2+1)*res1=(2*n2*(2*n2-1)/2)*res1=6
        // 当n3=3，结果为(4+3+2+1)*res2=90
        // 当之前的n的结果已知后，就会有2*n个位置可以增加一个P，然后每个D的位置确定后就会有n个P的位置可以确定，累加起来就是前n项和公式。再乘以之前的结果可得到最终结果
        long long res = 1;
        long long mod = 1e9+7;
        for(int i=2;i<=n; ++i)
        {
            res = (res*i*(2*i-1))%mod;
        }
        return res;
    }
};
// @lc code=end

