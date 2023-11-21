/*

Question
Formatted question description: https://leetcode.ca/all/245.html

Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, return the shortest distance between the occurrence of these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3
 

Constraints:

1 <= wordsDict.length <= 105
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
Algorithm
A condition is added here, that is, two words may be the same.

When word1 and word2 are equal, use p1 to save the result of p2, and p2 is assigned to the current position i, so that the result can be updated.

If word1 and word2 are not equal, the same logic is still valid.

*/

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int ans = n;
        if (word1 == word2) {
            for (int i = 0, j = -1; i < n; ++i) {
                if (wordsDict[i] == word1) {
                    if (j != -1) {
                        ans = min(ans, i - j);
                    }
                    j = i;
                }
            }
        } else {
            for (int k = 0, i = -1, j = -1; k < n; ++k) {
                if (wordsDict[k] == word1) {
                    i = k;
                }
                if (wordsDict[k] == word2) {
                    j = k;
                }
                if (i != -1 && j != -1) {
                    ans = min(ans, abs(i - j));
                }
            }
        }
        return ans;
    }
};
