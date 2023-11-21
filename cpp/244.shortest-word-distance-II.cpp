/*

Formatted question description: https://leetcode.ca/all/244.html

Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.
 

Example 1:

Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1
 

Constraints:

1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
At most 5000 calls will be made to shortest.
Algorithm
Need to call the function to find the shortest word distance multiple times, then the solution to the previous problem [243 Shortest-Word-Distance] is very inefficient.

Use HashMap to create a mapping between each word and all its appearing positions, and then when looking for the shortest word distance, you only need to take out the word’s mapped position array in HashMap for pairwise comparison.

*/

// OJ: https://leetcode.com/problems/shortest-word-distance-ii/
// Time:
//     * WordDistance: O(N)
//     * shortest: O(N)
// Space: O(N)
class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        auto &a = m[word1], &b = m[word2];
        int i = 0, j = 0, dist = INT_MAX;
        while (i < a.size() && j < b.size() && dist > 1) {
            dist = min(dist, abs(a[i] - b[j]));
            if (a[i] > b[j]) ++j;
            else ++i;
        }
        return dist;
    }
};