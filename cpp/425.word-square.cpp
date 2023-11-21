/*

Description
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:

There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Solution
First construct a trie using all the words in words. Then find all word squares from the trie. A word square must have the same number of rows and columns and be symmetric. Use backtrack to find all word squares.

*/

// OJ: https://leetcode.com/problems/word-squares/
// Time: O(MN)
// Space: O(MN)
struct TrieNode {
    TrieNode *next[26] = {};
    vector<int> indices;
};
class Solution {
    void addWord(TrieNode *node, string &s, int i) {
        node->indices.push_back(i);
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->indices.push_back(i);
        }
    }
    vector<int> getWords(TrieNode *node, string &s) {
        for (char c : s) {
            node = node->next[c - 'a'];
            if (!node) return {};
        }
        return node->indices;
    }
public:
    vector<vector<string>> wordSquares(vector<string>& A) {
        int N = A[0].size(), M = A.size();
        vector<vector<string>> ans;
        vector<string> tmp(N, string(N, ' '));
        TrieNode root;
        for (int i = 0; i < M; ++i) addWord(&root, A[i], i);
        function<void(int)> dfs = [&](int i) {
            if (i == N) {
                ans.push_back(tmp);
                return;
            }
            auto prefix = tmp[i].substr(0, i);
            for (auto &index : getWords(&root, prefix)) {
                for (int k = i; k < N; ++k) {
                    tmp[i][k] = tmp[k][i] = A[index][k];
                }
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};