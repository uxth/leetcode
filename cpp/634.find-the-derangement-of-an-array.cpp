/*

Description
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There’s originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:

Input: 3

Output: 2

Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

Note:

n is in the range of [1, 106].

Solution
Let f(n) be the number of derangement that can be generated using n integers. Obviously, f(1) = 0 and f(2) = 1. For n > 2, how to calculate f(n)?

Use dynamic programming, where f(n) can be obtained using f(n - 1) and f(n - 2). If there are n numbers, then the greatest number n can be placed in any position from 1 to n - 1. Suppose number n is placed in position m where 1 <= m < n, then number m must be in a position that is not its original position. If number m is in position n, then the situation becomes a derangement of n - 2 remaining numbers, so the number of derangement is f(n - 2). If number m is not in position n, then for each number from 1 to n - 1, there is exactly one position that the number can’t be in. For number m, the one position it can’t be in is position n. For other numbers like number k where k != m and k < n, the one position it can’t be in is position k. So the number of derangement is f(n - 1). In conclusion, if there are n numbers and number n is placed in position m where 1 <= m < n, then the number of derangement is f(n - 2) + f(n - 1). Since there are n - 1 possible values for m, the number of derangement in total is f(n) = (f(n - 2) + f(n - 1)) * (n - 1).

For each m such that 1 <= m <= n, after f(m) is calculated, do the modulo operation. Finally, return f(n).

*/

class Solution {
public:
    int findDerangement(int n) {
        long long a = 1, b = 0;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            long long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};