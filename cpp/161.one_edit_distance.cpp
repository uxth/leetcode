/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

/*
https://leetcode.ca/2016-05-09-161-One-Edit-Distance/
*/


class Solution {
private:
    int editDistance(string &s, string &t) {
        if (s.size() < t.size()) swap(s, t);
        int M = s.size(), N = t.size();
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) dp[i] = i;
        for (int i = 1; i <= M; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j) {
                int tmp = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[N];
    }
public:
    bool isOneEditDistance(string s, string t) {
        return editDistance(s, t) == 1;
    }
};