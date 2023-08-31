/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 *
 * https://leetcode.com/problems/pyramid-transition-matrix/description/
 *
 * algorithms
 * Medium (54.60%)
 * Likes:    305
 * Dislikes: 350
 * Total Accepted:    21.3K
 * Total Submissions: 38.9K
 * Testcase Example:  '"BCD"\n["BCG","CDE","GEA","FFF"]'
 *
 * We are stacking blocks to form a pyramid. Each block has a color which is a
 * one letter string.
 * 
 * We are allowed to place any color block C on top of two adjacent blocks of
 * colors A and B, if and only if ABC is an allowed triple.
 * 
 * We start with a bottom row of bottom, represented as a single string. We
 * also start with a list of allowed triples allowed. Each allowed triple is
 * represented as a string of length 3.
 * 
 * Return true if we can build the pyramid all the way to the top, otherwise
 * false.
 * 
 * Example 1:
 * 
 * 
 * Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
 * Output: true
 * Explanation:
 * We can stack the pyramid like this:
 * ⁠   A
 * ⁠  / \
 * ⁠ G   E
 * ⁠/ \ / \
 * B   C   D
 * 
 * We are allowed to place G on top of B and C because BCG is an allowed
 * triple.  Similarly, we can place E on top of C and D, then A on top of G and
 * E.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
 * Output: false
 * Explanation:
 * We can't stack the pyramid to the top.
 * Note that there could be allowed triples (A, B, C) and (A, B, D) with C !=
 * D.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * bottom will be a string with length in range [2, 8].
 * allowed will have length in range [0, 200].
 * Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E',
 * 'F', 'G'}.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(string bottom, int start, unordered_map<string,vector<char>>& m, string level)
    {
        if(bottom.size()==1) return true;
        if(start==bottom.size()-1) return dfs(level, 0, m, "");
        for(char c : m[bottom.substr(start, 2)])
            if(dfs(bottom, start+1, m, level+c)) return true;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for(string& i : allowed)
            m[i.substr(0,2)].push_back(i.back());
        return dfs(bottom, 0, m, "");
    }
};
// @lc code=end

// "AABA"\n["AAA", "AAB", "ABA", "ABB", "BAC"]
// "BDBBAA"\n["ACB","ACA","AAA","ACD","BCD","BAA","BCB","BCC","BAD","BAB","BAC","CAB","CCD","CAA","CCA","CCC","CAD","DAD","DAA","DAC","DCD","DCC","DCA","DDD","BDD","ABB","ABC","ABD","BDB","BBD","BBC","BBA","ADD","ADC","ADA","DDC","DDB","DDA","CDA","CDD","CBA","CDB","CBD","DBA","DBC","DBD","BDA"]