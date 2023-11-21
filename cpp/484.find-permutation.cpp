/*

Description
By now, you are given a secret signature consisting of character ‘D’ and ‘I’. ‘D’ represents a decreasing relationship between two numbers, ‘I’ represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature “DI” can be constructed by array [2,1,3] or [3,1,2], but won’t be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can’t represent the “DI” secret signature.

On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, … n] could refer to the given secret signature in the input.

Example 1:

Input: “I”

Output: [1,2]

Explanation: [1,2] is the only legal initial spectial string can construct secret signature “I”, where the number 1 and 2 construct an increasing relationship.

Example 2:

Input: “DI”

Output: [2,1,3]

Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature “DI”, but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3].

Note:

The input string will only contain the character ‘D’ and ‘I’.
The length of input string is a positive integer and will not exceed 10,000
Solution
To obtain the lexicographically smallest permutation, always use the smallest possible integer at each index. If a “D” is met, count the maximum number of consecutive “D”s, and the numbers at such indices are permuted in descending order. Find the minimum possible number for the first “D”, and fill in all the indices with “D”. If an “I” is met, simply use the smallest number that is greater than the previous largest number.

*/

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        iota(ans.begin(), ans.end(), 1);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == 'D') {
                ++j;
            }
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = max(i + 1, j);
        }
        return ans;
    }
};