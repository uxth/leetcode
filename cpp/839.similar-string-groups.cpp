/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 *
 * https://leetcode.com/problems/similar-string-groups/description/
 *
 * algorithms
 * Hard (38.59%)
 * Likes:    367
 * Dislikes: 122
 * Total Accepted:    25.5K
 * Total Submissions: 66.2K
 * Testcase Example:  '["tars","rats","arts","star"]'
 *
 * Two strings X and Y are similar if we can swap two letters (in different
 * positions) of X, so that it equals Y. Also two strings X and Y are similar
 * if they are equal.
 * 
 * For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
 * and "rats" and "arts" are similar, but "star" is not similar to "tars",
 * "rats", or "arts".
 * 
 * Together, these form two connected groups by similarity: {"tars", "rats",
 * "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group
 * even though they are not similar.  Formally, each group is such that a word
 * is in the group if and only if it is similar to at least one other word in
 * the group.
 * 
 * We are given a list A of strings.  Every string in A is an anagram of every
 * other string in A.  How many groups are there?
 * 
 * 
 * Example 1:
 * Input: A = ["tars","rats","arts","star"]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= A.length <= 2000
 * 1 <= A[i].length <= 1000
 * A.length * A[i].length <= 20000
 * All words in A consist of lowercase letters only.
 * All words in A have the same length and are anagrams of each other.
 * The judging time limit has been increased for this question.
 * 
 * 
 */

// @lc code=start
class Solution {
    class disjoint_set {
        vector<int> v;
        int sz;
    public:
        disjoint_set(int n) {
            makeset(n);
        }

        void makeset(int n) {
            v.resize(n);
            iota(v.begin(), v.end(), 0);
            sz = n;
        }

        int find(int i) {
            if (i != v[i])
                v[i] = find(v[i]);
            return v[i];
        }
        
        void join(int i, int j) {
            int ri = find(i), rj = find(j);
            if (ri != rj) {
                v[ri] = rj;
                sz--;
            }
        }
        
        int size() {
            return sz;
        }
    };
public:
    bool similar(string &a, string &b) {
        int n = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && ++n > 2)
                return false;
        return true;
    }

    int numSimilarGroups(vector<string>& A) {
        disjoint_set ds(A.size());
        for (int i = 0; i < A.size(); i++)
            for (int j = i + 1; j < A.size(); j++)
                if (similar(A[i], A[j]))
                    ds.join(i, j);
        return ds.size();
    }
};
// @lc code=end
// ["kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"]

// ["qihcochwmglyiggvsqqfgjjxu","gcgqxiysqfqugmjgwclhjhovi","gjhoggxvcqlcsyifmqgqujwhi","wqoijxciuqlyghcvjhgsqfmgg","qshcoghwmglygqgviiqfjcjxu","jgcxqfqhuyimjglgihvcqsgow","qshcoghwmggylqgviiqfjcjxu","wcoijxqiuqlyghcvjhgsqgmgf","qshcoghwmglyiqgvigqfjcjxu","qgsjggjuiyihlqcxfovchqmwg","wcoijxjiuqlyghcvqhgsqgmgf","sijgumvhqwqioclcggxgyhfjq","lhogcgfqqihjuqsyicxgwmvgj","ijhoggxvcqlcsygfmqgqujwhi","qshcojhwmglyiqgvigqfgcjxu","wcoijxqiuqlyghcvjhgsqfmgg","qshcojhwmglyiggviqqfgcjxu","lhogcgqqfihjuqsyicxgwmvgj","xscjjyfiuglqigmgqwqghcvho","lhggcgfqqihjuqsyicxgwmvoj","lhgocgfqqihjuqsyicxgwmvgj","qihcojhwmglyiggvsqqfgcjxu","ojjycmqshgglwicfqguxvihgq","sijvumghqwqioclcggxgyhfjq","gglhhifwvqgqcoyumcgjjisqx"]
