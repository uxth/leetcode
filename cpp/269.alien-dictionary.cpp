/*

Question
Formatted question description: https://leetcode.ca/all/269.html

There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
Algorithm
It is actually a problem of directed graph traversal.

The solution consists of two steps:

Create the graph and indegree map:
For each character in the words, initialize its indegree to 0.
For each adjacent pair of words, find the first character that is different.
If the second character is not already in the adjacency list of the first character, add it and increment its indegree by 1.
Stop processing the current pair of words and move on to the next pair.
If all characters of the first word match the second word and the first word is longer than the second, it means that the order of characters is invalid, so return an empty string.
Topological sort
Add all characters with an indegree of 0 to the queue.
For each character in the queue, add it to the result and decrement the indegree of its neighbors.
If the indegree of a neighbor becomes 0, add it to the queue.
If the length of the result equals the length of the indegree map, return the result as a string. Otherwise, return an empty string.
*/

// OJ: https://leetcode.com/problems/alien-dictionary/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string alienOrder(vector<string>& A) {
        unordered_map<int, unordered_set<int>> G;
        int indegree[26] = {};
        for (auto &s : A) {
            for (char c : s) G[c - 'a'] = {};
        }
        for (int i = 1; i < A.size(); ++i) {
            int j = 0;
            for (; j < min(A[i - 1].size(), A[i].size()); ++j) {
                if (A[i - 1][j] == A[i][j]) continue;
                G[A[i - 1][j] - 'a'].insert(A[i][j] - 'a');
                break;
            }
            if (j == A[i].size() && j < A[i - 1].size()) return "";
        }
        for (auto &[from, tos] : G) {
            for (int to : tos) {
                indegree[to]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (G.count(i) && indegree[i] == 0) q.push(i);
        }
        string ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans += u + 'a';
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == G.size() ? ans : "";
    }
};