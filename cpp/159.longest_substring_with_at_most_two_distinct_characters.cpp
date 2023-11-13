/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

/*
https://leetcode.ca/2016-05-07-159-Longest-Substring-with-At-Most-Two-Distinct-Characters/
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) ++cnt;
            while (cnt > 2) {
                if (m[s[i++]]-- == 1) --cnt;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};