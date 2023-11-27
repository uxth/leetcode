/*

Imagine you have a special keyboard with the following keys:

A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

 

Example 1:

Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A
Example 2:

Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
 

Constraints:

1 <= n <= 50
Algorithm
Logical
We can analyze the examples in the question and find that N steps can print at least N A, because we can print A at every step.

Then, if you can exceed N, copy and paste must be used. Here, since selecting all and copying take up two steps, the operation to increase the number of A is actually only N-2 steps, so how do we determine how many A to print, before pasting?

Actually, it’s a trade off. If you print too many or too few A, you won’t get the maximum result. So the times of printing A and pasting should be close. The easiest way is to go through all the conditions and take the maximum , The number of printing A is between [1, N-3], the number of pasting is N-2-i, plus the printed part, it is N-1-i.

DP
This problem can also be done with DP. We use a one-dimensional array dp, where dp[i] represents the maximum number of A that can be printed when the total number of steps is i, initialized to N+1, and then we decide how to find the DP formula.

For dp[i], the method is actually the same as the above method. It is still necessary to traverse all the number of printed A, and then multiply by the number of pasting times plus 1 to update dp[i].

*/

// OJ: https://leetcode.com/problems/4-keys-keyboard/
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/4-keys-keyboard/solution/
class Solution {
public:
    // int maxA(int N) {
    //     vector<int> dp(N + 1);
    //     for (int i = 1; i <= N; ++i) {
    //         dp[i] = dp[i - 1] + 1;
    //         for (int j = 2; j < i - 1; ++j) dp[i] = max(dp[i], dp[i - j - 1] * j);
    //     }
    //     return dp[N];
    // }

    int maxA(int N) {
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            dp[i] = i;
            for (int j = 1; j < i - 2; ++j) dp[i] = max(dp[i], dp[j] + (i-j-2)*dp[j]);
        }
        return dp[N];
    }
};