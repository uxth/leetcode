/*

Question
Formatted question description: https://leetcode.ca/all/320.html

A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent substrings and replacing them with their respective lengths.

For example, "abcde" can be abbreviated into:
"a3e" ("bcd" turned into "3")
"1bcd1" ("a" and "e" both turned into "1")
"5" ("abcde" turned into "5")
"abcde" (no substrings replaced)
However, these abbreviations are invalid:
"23" ("ab" turned into "2" and "cde" turned into "3") is invalid as the substrings chosen are adjacent.
"22de" ("ab" turned into "2" and "bc" turned into "2") is invalid as the substring chosen overlap.
Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.

 

Example 1:

Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
Example 2:

Input: word = "a"
Output: ["1","a"]
 

Constraints:

1 <= word.length <= 15
word consists of only lowercase English letters.
Algorithm
If you write a binary number from 0 to 15, each binary can correspond to a situation, as shown below:

0000 word 0001 wor1 0010 wo1d 0011 wo2 0100 w1rd 0101 w1r1 0110 w2d 0111 w3 1000 1ord 1001 1or1 1010 1o1d 1011 1o2 1100 2rd 1101 2r1 1110 3d 1111 4

Then we can observe the law, wherever 0 is the original letter, and a single 1 is still 1. If there are several 1s connected together, the number of 1s is required, and this number is used to replace the corresponding letter.

*/

// OJ: https://leetcode.com/problems/generalized-abbreviation/
// Time: O(2^W * W)
// Space: O(W)
class Solution {
private:
    string encode(string word, int mask) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (mask & (1 << i)) ++cnt;
            else {
                if (cnt) {
                    ans += to_string(cnt);
                    cnt = 0;
                }
                ans += word[i];
            }
        }
        if (cnt) ans += to_string(cnt);
        return ans;
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        for (int i = 0; i < (1 << word.size()); ++i) ans.push_back(encode(word, i));
        return ans;
    }
};