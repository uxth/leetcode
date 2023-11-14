/*

Question
Formatted question description: https://leetcode.ca/all/291.html

Given a pattern and a string s, return true if s matches the pattern.

A string s matches a pattern if there is some bijective mapping of single characters to strings such that if each character in pattern is replaced by the string it maps to, then the resulting string is s. A bijective mapping means that no two characters map to the same string, and no character maps to two different strings.

 

Example 1:

Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"
Example 2:

Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"
Example 3:

Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false
 

Constraints:

1 <= pattern.length, s.length <= 20
pattern and s consist of only lowercase English letters.
Algorithm
To use HashMap to establish the mapping between pattern characters and words, you also need to use variables p and r to record the position of the pattern character and word string currently recursed to.

In the recursive function, if p and r are equal to the length of the pattern string and the word string respectively, it means that the matching has ended successfully at this time, and ture is returned.
On the contrary, if one is reached and the other is not, it means that the match has failed, and false is returned.
If the above conditions are not met, take out the pattern character at the current position, and then traverse backward from position r of the word string, taking out one word each time,
If the pattern character already exists in the HashMap, and the corresponding word and the extracted word are also equal, then call the recursive function again in the next position,
If it returns true, then return true.
On the contrary, if the pattern character is not in the HashMap, it depends on whether other pattern characters have been mapped to the word currently taken out.
If not, create a new mapping and call the recursive function
Note that if the recursive function returns false, delete this mapping in the HashMap
Pitfall
Don’t forget below part during DFS.

map.remove(patternChar); // @note: need to remove, since this attempt is failed
inverseMap.remove(tentativeMatchString);

*/

// OJ: https://leetcode.com/problems/word-pattern-ii/
// Time: O(PS)
// Space: O(S)
class Solution {
public:
    bool wordPatternMatch(string p, string s) {
        unordered_map<char, string> m;
        unordered_set<string> seen;
        function<bool(int,int)> dfs = [&](int i, int j) {
            if (i == p.size()) return j == s.size();
            if (m.count(p[i])) {
                auto t = m[p[i]];
                return s.substr(j, t.size()) == t && dfs(i + 1, j + t.size());
            } else {
                string t;
                for (int k = j; k < s.size(); ++k) {
                    t += s[k];
                    if (seen.count(t)) continue;
                    seen.insert(t);
                    m[p[i]] = t;
                    if (dfs(i + 1, k + 1)) return true;
                    seen.erase(t);
                    m.erase(p[i]);
                }
            }
            return false;
        };
        return dfs(0, 0);
    }
};