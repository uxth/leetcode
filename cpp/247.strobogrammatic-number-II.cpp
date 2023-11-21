/*
Question
Formatted question description: https://leetcode.ca/all/247.html

Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: n = 2
Output: ["11","69","88","96"]
Example 2:

Input: n = 1
Output: ["0","1","8"]
 

Constraints:

1 <= n <= 14
Algorithm
Let us first enumerate the cases where n is 0,1,2,3,4:

n = 0: none

n = 1: 0, 1, 8

n = 2: 11, 69, 88, 96

n = 3: 101, 609, 808, 906, 111, 619, 818, 916, 181, 689, 888, 986

n = 4: 1001, 6009, 8008, 9006, 1111, 6119, 8118, 9116, 1691, 6699, 8698, 9696, 1881, 6889, 8888, 9886, 1961, 6969, 8968, 9966
Pay attention to the observation of n=0 and n=2, you can find that the latter is based on the former, and the left and right sides of each number are increased by [1 1], [6 9], [8 8], [9 6]

Look at n=1 and n=3, it’s more obvious, increase [1 1] around 0, become 101, increase around 0 [6 9], become 609, increase around 0 [8 8] , Becomes 808, increases [9 6] to the left and right of 0, becomes 906, and then adds the four sets of numbers to the left and right sides of 1 and 8 respectively

In fact, it starts from the m=0 layer and adds layer by layer. It should be noted that when the n layer is added.

[0 0] cannot be added to the left and right sides, because 0 cannot appear at the beginning of two or more digits. In the process of recursive in the middle, it is necessary to add 0 to the left and right sides of the number.
*/

// OJ: https://leetcode.com/problems/strobogrammatic-number-ii/
// Time: O(5^(N/2))
// Space: O(N)
const char pairs[5][2] = { {'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'} };
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string s(n, '0');
        vector<string> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == (n + 1) / 2) {
                ans.push_back(s);
                return;
            }
            int j = n - 1 - i;
            for (auto &[a, b] : pairs) {
                if (i == j && a != b) continue;
                if (i == 0 && n > 1 && a == '0') continue;
                s[i] = a;
                s[j] = b;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};