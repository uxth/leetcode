/*

Question
Formatted question description: https://leetcode.ca/all/340.html

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50
Algorithm
Same as Longest Substring with At Most Two Distinct Characters.

change from 2 to k
Link at here.

*/

// OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, ans = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            while (distinct > k) distinct -= --cnt[s[i++]] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};