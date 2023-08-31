/*
 * @lc app=leetcode id=1577 lang=cpp
 *
 * [1577] Number of Ways Where Square of Number Is Equal to Product of Two Numbers
 */

// @lc code=start
class Solution {
    int count(vector<int> &A, vector<int> &B) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int n : B) m[n]++;
        for (int a : A) {
            long target = (long)a * a;
            for (auto &[b, cnt] : m) {
                if (target % b || m.count(target / b) == 0) continue;
                if (target / b == b) ans += cnt * (cnt - 1);
                else ans += cnt * m[target / b];
            }
        }
        return ans / 2;
    }
public:
    int numTriplets(vector<int>& A, vector<int>& B) {
        return count(A, B) + count(B, A);
    }
};
// @lc code=end

