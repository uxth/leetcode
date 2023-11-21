/*

Description
A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill’s lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person’s ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

Note:

A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
Person’s IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
Example 1:

Input:

[[0,1,10], [2,0,5]]

Output:

2

Explanation:

Person #0 gave person #1 $10.

Person #2 gave person #0 $5.

Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.

Example 2:

Input:

[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

Output:

1

Explanation:

Person #0 gave person #1 $10.

Person #1 gave person #0 $1.

Person #1 gave person #2 $5.

Person #2 gave person #0 $5.

Therefore, person #1 only need to give person #0 $4, and all debt is settled.

Solution
First loop over transactions and obtain each person’s remaining amount of money (either 0, positive or negative). Then do backtrack.

Starting from index 0 and transaction count 0, loop over each remaining amount after the start index. If a next amount has a different sign with the amount at the start index, then add the amount of the start index by the current amount with the number of transactions increased by 1, and do backtrack using the current index as the start index. If the end is reached, update the minimum number of transactions. Finally, return the minimum number of transactions.

*/

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int g[12]{};
        for (auto& t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        vector<int> nums;
        for (int x : g) {
            if (x) {
                nums.push_back(x);
            }
        }
        int m = nums.size();
        int f[1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    s += nums[j];
                }
            }
            if (s == 0) {
                f[i] = __builtin_popcount(i) - 1;
                for (int j = (i - 1) & i; j; j = (j - 1) & i) {
                    f[i] = min(f[i], f[j] + f[i ^ j]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
};