/*

Description
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if “great” and “good” are similar, and “fine” and “good” are similar, then “great” and “fine” are similar.

Similarity is also symmetric. For example, “great” and “fine” being similar is the same as “fine” and “great” being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
Solution
First check whether words1 and words2 have the same length. If their lengths are different, return false.

Use two maps to map each word to its group and to map each group to the list of words in the group, respectively.

For each pair of similar words, update both maps. If two words that were originally from different groups are in the same pair, then the two groups are merged into one group, with the smaller group number maintained.

After all pairs are dealt with, loop over both arrays and check whether the two words at the same index are similar. If there exist two words at the same index that are not similar, return false. If all words are similar, return true.

*/

class Solution {
public:
    vector<int> p;
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
            return false;
        int n = similarPairs.size();
        p.resize(n << 1);
        for (int i = 0; i < p.size(); ++i)
            p[i] = i;
        unordered_map<string, int> words;
        int idx = 0;
        for (auto e : similarPairs) {
            string a = e[0], b = e[1];
            if (!words.count(a))
                words[a] = idx++;
            if (!words.count(b))
                words[b] = idx++;
            p[find(words[a])] = find(words[b]);
        }
        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i])
                continue;
            if (!words.count(sentence1[i]) || !words.count(sentence2[i]) || find(words[sentence1[i]]) != find(words[sentence2[i]]))
                return false;
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
};