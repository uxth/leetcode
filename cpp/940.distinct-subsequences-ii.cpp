/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 *
 * https://leetcode.com/problems/distinct-subsequences-ii/description/
 *
 * algorithms
 * Hard (44.22%)
 * Likes:    1641
 * Dislikes: 35
 * Total Accepted:    36.7K
 * Total Submissions: 85K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of distinct non-empty subsequences of s.
 * Since the answer may be very large, return it modulo 10^9 + 7.
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * Output: 7
 * Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac",
 * "bc", and "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: 6
 * Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and
 * "aba".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aaa"
 * Output: 3
 * Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2000
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        int size = s.size();
        int mod=1e9+7;
        vector<int> dp(size+1);
        dp[0]=1;
        unordered_map<char,int> map;
        for(int i=0; i<size; ++i){
            dp[i+1] = (dp[i]*2)%mod;
            if(map.count(s[i])){
                int repeatIndex = map[s[i]];
                dp[i+1]=(dp[i+1]-dp[repeatIndex])%mod;
            }
            map[s[i]] = i;
        }
        return (dp[size]+mod-1)%mod ;
    }

};
// @lc code=end

/*
""aba""
""yezruvnatuipjeohsymapyxgfeczkevoxipckunlqjauvllfpwezhlzpbkfqazhexabomnlxkmoufneninbxxguuktvupmpfspwxiouwlfalexmluwcsbeqrzkivrphtpcoxqsueuxsalopbsgkzaibkpfmsztkwommkvgjjdvvggnvtlwrllcafhfocprnrzfoyehqhrvhpbbpxpsvomdpmksojckgkgkycoynbldkbnrlujegxotgmeyknpmpgajbgwmfftuphfzrywarqkpkfnwtzgdkdcyvwkqawwyjuskpvqomfchnlojmeltlwvqomucipcwxkgsktjxpwhujaexhejeflpctmjpuguslmzvpykbldcbxqnwgycpfccgeychkxfopixijeypzyryglutxweffyrqtkfrqlhtjweodttchnugybsmacpgperznunffrdavyqgilqlplebbkdopyyxcoamfxhpmdyrtutfxsejkwiyvdwggyhgsdpfxpznrccwdupfzlubkhppmasdbqfzttbhfismeamenyukzqoupbzxashwuvfkmkosgevcjnlpfgxgzumktsexvwhylhiupwfwyxotwnxodttsrifgzkkedurayjgxlhxjzlxikcgerptpufocymfrkyayvklsalgmtifpiczwnozmgowzchjiop""
*/
