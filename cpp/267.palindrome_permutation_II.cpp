/*

Question
Formatted question description: https://leetcode.ca/all/267.html

Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.

 

Example 1:

Input: s = "aabb"
Output: ["abba","baab"]
Example 2:

Input: s = "abc"
Output: []
 

Constraints:

1 <= s.length <= 16
s consists of only lowercase English letters.
Algorithm
One thing to note is that if you use an array to save the result directly, and if there are repeated characters in t, there may be duplicates, such as t = “baa”, then the final result will have duplicates

When start=0 and i=1, aba is obtained after the exchange,
Later when start=1 and i=2, aab can be obtained after the exchange.
But after returning to the first layer after baa, when start=0, i=2, aab is obtained after the exchange, and repetition occurs.
In fact, the easiest way to de-duplicate is to define the result res as a HashSet, and use its de-duplication feature to ensure that there is no duplicate.

*/

class Solution {
public:
    int n;
    vector<string> ans;
    unordered_map<char, int> cnt;

    vector<string> generatePalindromes(string s) {
        n = s.size();
        for (char c : s) ++cnt[c];
        string mid = "";
        for (auto& [k, v] : cnt) {
            if (v & 1) {
                if (mid != "") {
                    return ans;
                }
                mid += k;
            }
        }
        dfs(mid);
        return ans;
    }

    void dfs(string t) {
        if (t.size() == n) {
            ans.push_back(t);
            return;
        }
        for (auto& [k, v] : cnt) {
            if (v > 1) {
                v -= 2;
                dfs(k + t + k);
                v += 2;
            }
        }
    }
};