/*

Description
Given an array A (index starts at 1) consisting of N integers: A1, A2, …, AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you cant jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it’s not possible to reach the place indexed N then you need to return an empty array.

Example 1:

Input: [1,2,4,-1,2], 2

Output: [1,3,5]

Example 2:

Input: [1,2,4,-1,2], 1

Output: []

Note:

Path Pa1, Pa2, …, Pan is lexicographically smaller than Pb1, Pb2, …, Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
A1 >= 0. A2, …, AN (if exist) will in the range of [-1, 100].
Length of A is in the range of [1, 1000].
B is in the range of [1, 100].
Solution
Use dynamic programming. Create an array dp and an array next of length A.length, where dp[i] represents the total cost starting from index i to the end, and next[i] represents the next index of index i in the path with minimum cost.

Initialize dp such that all elements are Integer.MAX_VALUE and initialize next such that all elements are A.length. If the last element in A is not -1, then set the last element of dp to be the last element of A.

Loop over A backwards from index A.length - 2 to 0. At each index i, if A[i] is -1, then the place cannot be jumped to, so continue. For each index j from i + 1 to i + B (or A.length - 1 if i + B exceeds A.length - 1), if dp[j] is Integer.MAX_VALUE, continue since it is impossible to reach the end from j. Otherwise, if dp[j] + A[i] < dp[i], then update dp[i] = dp[j] + A[i] and next[i] = j.

If dp[0] is Integer.MAX_VALUE, then no path exists, so return an empty list. Otherwise, starting from index 0 to find a path that reaches the end, and return the path as a list.

*/

class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<int> ans;
        if (coins[n - 1] == -1) {
            return ans;
        }
        int f[n];
        const int inf = 1 << 30;
        f[n - 1] = coins[n - 1];
        for (int i = n - 2; ~i; --i) {
            f[i] = inf;
            if (coins[i] != -1) {
                for (int j = i + 1; j < min(n, i + maxJump + 1); ++j) {
                    f[i] = min(f[i], f[j] + coins[i]);
                }
            }
        }
        if (f[0] == inf) {
            return ans;
        }
        for (int i = 0, s = f[0]; i < n; ++i) {
            if (f[i] == s) {
                s -= coins[i];
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};