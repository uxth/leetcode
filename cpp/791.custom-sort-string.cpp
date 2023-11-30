/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 *
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (65.66%)
 * Likes:    760
 * Dislikes: 189
 * Total Accepted:    66.7K
 * Total Submissions: 101.6K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * S and T are strings composed of lowercase letters. In S, no letter occurs
 * more than once.
 * 
 * S was sorted in some custom order previously. We want to permute the
 * characters of T so that they match the order that S was sorted. More
 * specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 * 
 * Return any permutation of T (as a string) that satisfies this property.
 * 
 * 
 * Example :
 * Input: 
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation: 
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
 * and "a". 
 * Since "d" does not appear in S, it can be at any position in T. "dcba",
 * "cdba", "cbda" are also valid outputs.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string useMap(string& S, string& T) {
        vector<int> m(256, 0);
        // unordered_map<char,int> m;
        for(char c : T) m[c]++;
        string res;
        for(char c : S)
        {
            // res += m.count(c) ? string(m[c], c) : "";
            // m.erase(c);
            res += string(m[c], c);
            m[c] = 0;
        }
        // for(auto& i : m) res += string(i.second, i.first);
        for(char i = 'a'; i<='z'; ++i) res+=string(m[i], i);
        return res;
    }

    string useSort(string& S, string& T){
        unordered_map<char,int> ind;
        for(int i=0; i<S.size(); ++i)ind[S[i]] = i;
        sort(begin(T), end(T), [&](char a, char b){
            int aInd = ind.count(a) ? ind[a] : INT_MAX;
            int bInd = ind.count(b) ? ind[b] : INT_MAX;
            return aInd < bInd;
        });
        return T;
    }
    string customSortString(string S, string T) {
        return useMap(S, T);
        // return useSort(S, T); // sort is slower since O(nlog(n))
    }

};
// @lc code=end

