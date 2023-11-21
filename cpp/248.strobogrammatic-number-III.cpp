/*

Question
Formatted question description: https://leetcode.ca/all/248.html

Given two strings low and high that represent two integers low and high where low <= high, return the number of strobogrammatic numbers in the range [low, high].

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: low = "50", high = "100"
Output: 3
Example 2:

Input: low = "0", high = "0"
Output: 1
 

Constraints:

1 <= low.length, high.length <= 15
low and high consist of only digits.
low <= high
low and high do not contain any leading zeros except for zero itself.
Algorithm
Goal is to get the number of symmetry numbers in a given range.

Initialize the cases of n=0 and n=1, and then recurse based on them.

The recursion length len is traversed from low to high, and then see if the current word length reaches len,

If it is reached, first remove the multiple digits that start with 0,
Then remove the numbers with the same length as low but less than low, and numbers with the same length as high but greater than high,
Then the result is incremented by 1,
Then add the five pairs of symmetric numbers to the left and right of the current word, and continue to call recursively

*/

using ll = long long;

class Solution {
public:
    const vector<pair<char, char>> pairs = { {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'} };

    int strobogrammaticInRange(string low, string high) {
        int n;
        function<vector<string>(int)> dfs = [&](int u) {
            if (u == 0) return vector<string>{""};
            if (u == 1) return vector<string>{"0", "1", "8"};
            vector<string> ans;
            for (auto& v : dfs(u - 2)) {
                for (auto& [l, r] : pairs) ans.push_back(l + v + r);
                if (u != n) ans.push_back('0' + v + '0');
            }
            return ans;
        };

        int a = low.size(), b = high.size();
        int ans = 0;
        ll l = stoll(low), r = stoll(high);
        for (n = a; n <= b; ++n) {
            for (auto& s : dfs(n)) {
                ll v = stoll(s);
                if (l <= v && v <= r) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};