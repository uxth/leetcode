/*

Question
Formatted question description: https://leetcode.ca/all/358.html

Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

 

Example 1:

Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least a distance of 3 from each other.
Example 2:

Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.
Example 3:

Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least a distance of 2 from each other.
 

Constraints:

1 <= s.length <= 3 * 105
s consists of only lowercase English letters.
0 <= k <= s.length
Algorithm
We need a hash table to establish the mapping between characters and their occurrences, and then a heap is needed to store each heap of mappings, sorted according to the number of occurrences.

Then if the heap is not empty, we start the loop. We find the smaller value between the length of k and str, and then traverse from 0 to this smaller value.

For each traversed value,

if the heap is empty at this time, indicating that this position cannot be filled with characters, return an empty string,
otherwise we take a pair of mappings from the top of the heap, and then add letters to the result, then the number of mappings is reduced by 1,
if the number after subtracting 1 If it is still greater than 0, we add this mapping to the temporary set v, and at the same time the number of str len is reduced by 1.
After traversing once, we add the mapping pairs in the temporary set to the heap.

*/

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        string res;
        int len = (int)str.size();
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (auto a : str) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({it->second, it->first});
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (q.empty()) return "";
                auto t = q.top(); q.pop();
                res.push_back(t.second);
                if (--t.first > 0) v.push_back(t);
                --len;
            }
            for (auto a : v) q.push(a);
        }
        return res;
    }
};
