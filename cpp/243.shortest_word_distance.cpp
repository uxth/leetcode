/*

Question
Formatted question description: https://leetcode.ca/all/243.html

Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
 

Constraints:

2 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
Algorithm
It is enough to traverse the array once, initialize the two variables p1, p2 to -1, and then traverse the array.

When word 1 is encountered, its position is stored in p1, and if word 2 is encountered, its position is stored in p2. If p1, p2 are not -1 anymore, then update the result.

*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int prev1 = -1, prev2 = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                if (prev2 != -1) ans = min(ans, i - prev2);
                prev1 = i;
            }
            if (words[i] == word2) {
                if (prev1 != -1) ans = min(ans, i - prev1);
                prev2 = i;
            }
        }
        return ans;
    }
};