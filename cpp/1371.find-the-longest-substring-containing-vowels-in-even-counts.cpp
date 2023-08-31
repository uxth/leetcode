/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 *
 * https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 *
 * algorithms
 * Medium (61.37%)
 * Likes:    581
 * Dislikes: 24
 * Total Accepted:    11.7K
 * Total Submissions: 19.1K
 * Testcase Example:  '"eleetminicoworoep"'
 *
 * Given the string s, return the size of the longest substring containing each
 * vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must
 * appear an even number of times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "eleetminicoworoep"
 * Output: 13
 * Explanation: The longest substring is "leetminicowor" which contains two
 * each of the vowels: e, i and o and zero of the vowels: a and u.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "leetcodeisgreat"
 * Output: 5
 * Explanation: The longest substring is "leetc" which contains two e's.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "bcbcbc"
 * Output: 6
 * Explanation: In this case, the given string "bcbcbc" is the longest because
 * all vowels: a, e, i, o and u appear zero times.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 x 10^5
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    // int findTheLongestSubstring(string s) {
    //     unordered_map<string, int> pos;
    //     unordered_map<char, int> vowel{{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
    //     string flag = "00000";
    //     pos[flag]=-1;
    //     int res = 0;
    //     for(auto i=0; i<s.size(); ++i)
    //     {
    //         auto it = vowel.find(s[i]);
    //         if(it!=vowel.end()) flag[it->second] = flag[it->second]=='0'?'1':'0';
    //         auto last = pos.find(flag);
    //         if(last!=pos.end()) res = max(res, i-last->second);
    //         else pos[flag]=i;
    //     }
    //     return res;
    // }

    int findTheLongestSubstring(string s) {
        int char_to_mask[26] = {1, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};
        // a = 00001, e = 00010, i = 00100, o = ...
        int result = 0;
        int mask = 0;
        
        vector<int> seen(32, -1);
        
        for (int i = 0; i < s.size(); i++) {
            mask ^= char_to_mask[s[i] - 'a'];
            
            if (mask && seen[mask] == -1) {
                seen[mask] = i;
            }
            
            result = max(result, i - seen[mask]);
        }
        return result;
    }
};
// @lc code=end
// ""leetcodeisgreat""
// ""id""
// ""tyrwpvlifrgjghlcicyocusukhmjbkfkzsjhkdrtsztchhazhmcircxcauajyzlppedqyzkcqvffyeekjdwqtjegerxbyktzvrxwgfjnrfbwvhiycvoznriroroamkfipazunsabwlseseeiimsmftchpafqkquovuxhhkpvphwnkrtxuiuhbcyqulfqyzgjjwjrlfwwxotcdtqsmfeingsxyzbpvmwulmqfrxbqcziudixceytvvwcohmznmfkoetpgdntrndvjihmxragqosaauthigfjergijsyivozzfrlpndygsmgjzdzadsxarjvyxuecqlszjnqvlyqkadowoljrmkzxvspdummgraiutxxxqgotqnxwjwfotvqglqavmsnmktsxwxcpxhuujuanxueuymzifycytalizwnvrjeoipfoqbiqdxsnclcvoafqwfwcmuwitjgqghkiccwqvloqrxbfjuxwriltxhmrmfpzitkwhitwhvatmknyhzigcuxfsosxetioqfeyewoljymhdwgwvjcdhmkpdfbbztaygvbpwqxtokvidtwfdhmhpomyfhhjorsmgowikpsdgcbazapkmsjgmfyuezaamevrbsmiecoujabrbqebiydncgapuexivgvomkuiiuuhhbszsflntwruqblrnrgwrnvcwixtxycifdebgnbbucqpqldkberbovemywoaxqicizkcjbmbxikxeizmzdvjdnhqrgkkqzmspdeuoqrxswqrajxfglmqkdnlescbjzurknjklikxxqqaqdekxkzkscoipolxmcszbebqpsizhwsxklzulmjotkrqfaeivhsedfynxtbzdrviwdgicusqucczgufqnaslpwzjhgtphnovlrgz""