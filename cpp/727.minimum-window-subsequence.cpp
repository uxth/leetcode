/*

Description
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: S = “abcdebdde”, T = “bde”

Output: “bcde”

Explanation:

“bcde” is the answer because it occurs before “bdde” which has the same length.

“deb” is not a smaller window because the elements of T in the window must occur in order.

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
Solution
If S and T are equal, then simply return S.

Use sliding window. If a substring W of S exists such that T is a subsequence of W, then a substring of S that is longer than or have the same length as W must also exist. Therefore, find such a substring of S starting from index 0 in S and index 0 in T. If the last character of T is reached, then the current index in S is the end index of the substring, and find the maximum possible start index of the substring in S. After the start index and the end index are found, the minimum window size can be updated, and store the start index and the end index as well. Then set the index in T to 0 and try to find another substring in S. Repeat the process until the end of S is reached.

After all the characters in S are visited, the minimum substring length can be obtained, and return the shortest substring. If the length still equals to S.length(), then such a substring does not exist, so return an empty string.

*/

class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        int p = 0, k = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s2[n - 1] && f[i][n]) {
                int j = f[i][n] - 1;
                if (i - j < k) {
                    k = i - j;
                    p = j;
                }
            }
        }
        return k > m ? "" : s1.substr(p, k);
    }
};