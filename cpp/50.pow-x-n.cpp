/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // double myPow(double x, int n) {
    //     if(n == 0) return 1;
    //     double y = myPow(x, abs(n)/2);
    //     y = y * y * (n%2 ? x : 1);
    //     return n<0 ? 1.0 / y : y;
    // }

   double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        return n%2==0 ? myPow(x*x,n/2) : x*myPow(x,n-1);
    }
};
// @lc code=end

