/*

Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
Companies:
Facebook

Related Topics:
String

Similar Questions:

Minimum Unique Word Abbreviation (Hard)
Word Abbreviation (Hard)
*/

// OJ: https://leetcode.com/problems/valid-word-abbreviation/
// Time: O(M+N)
// Space: O(1)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, M = word.size(), N = abbr.size();
        while (i < M && j < N) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                ++i;
                ++j;
                continue;
            }
            int len = 0;
            while (j < N && isdigit(abbr[j])) {
                len = 10 * len + (abbr[j++] - '0');
                if (!len) return false;
            }
            i += len;
        }
        return i == M && j == N;
    }
};