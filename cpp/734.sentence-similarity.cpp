/*

Given two sentences words1, words2 (each represented as an array of strings),
 and a list of similar word pairs pairs, determine if two sentences are similar.

 For example, "great acting skills" and "fine drama talent" are similar,
 if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

 Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar,
 and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

 However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

 Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar,
 even though there are no specified similar word pairs.

 Finally, sentences can only be similar if they have the same number of words.
 So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].


 Note:
     The length of words1 and words2 will not exceed 1000.
     The length of pairs will not exceed 2000.
     The length of each pairs[i] will be 2.
     The length of each words[i] and pairs[i][j] will be in the range [1, 20].

Algorithm
Just create a mapping between a word and a set of all similar words. For example, if great and fine are similar, and great and good are similar, then there is the following mapping:

great -> {fine, good}

So when we check the corresponding words in the two sentences one by one, we can directly find them in the mapping. Note that the words that may be encountered are reversed, such as fine and great, so we must bring both words into the mapping.

To search, as long as one can be found, it means that it is similar. On the contrary, if both are not found, it means that they are not similar, and return false directly

*/

// OJ: https://leetcode.com/problems/sentence-similarity/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool areSentencesSimilar(vector<string>& A, vector<string>& B, vector<vector<string>>& similarPairs) {
        if (A.size() != B.size()) return false;
        unordered_set<string> s;
        for (auto &p : similarPairs) s.insert(p[0] + '#' + p[1]);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == B[i]) continue;
            auto a = A[i] + '#' + B[i], b = B[i] + '#' + A[i];
            if (!s.count(a) && !s.count(b)) return false;
        }
        return true;
    }
};