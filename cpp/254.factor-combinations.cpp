/*

Question
Formatted question description: https://leetcode.ca/all/254.html

Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

 

Example 1:

Input: n = 1
Output: []
Example 2:

Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
Example 3:

Input: n = 37
Output: []
 

Constraints:

1 <= n <= 107
Algorithm
Iterate from 2 to n. If the current number i is divisible by n, it means that i is a factor of n. Store it in a onePath list, and then recursively call n/i.

At next recursion, do not traverse from 2. It traverses from i to n/i, and the condition for stopping is when n is equal to 1, if there is a factor in onePath at this time, store this combination in the result.

Pitfall
Need to avoid case: n=32, and only 32 in this list, add check if (onePath.size() > 1)

*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> t;
        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&](int n, int i) {
            if (t.size()) {
                vector<int> cp = t;
                cp.emplace_back(n);
                ans.emplace_back(cp);
            }
            for (int j = i; j <= n / j; ++j) {
                if (n % j == 0) {
                    t.emplace_back(j);
                    dfs(n / j, j);
                    t.pop_back();
                }
            }
        };
        dfs(n, 2);
        return ans;
    }
};