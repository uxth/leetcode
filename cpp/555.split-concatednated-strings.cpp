/*

Description
Given a list of strings, you could concatenate these strings together into a loop, where for each string you could choose to reverse it or not. Among all the possible loops, you need to find the lexicographically biggest string after cutting the loop, which will make the looped string into a regular one.

Specifically, to find the lexicographically biggest string, you need to experience two phases:

Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
Cut and make one breakpoint in any place of the loop, which will make the looped string into a regular one starting from the character at the cutpoint.
And your job is to find the lexicographically biggest one among all the possible regular strings.

Example:

Input: “abc”, “xyz”

Output: “zyxcba”

Explanation: You can get the looped string “-abcxyz-“, “-abczyx-“, “-cbaxyz-“, “-cbazyx-“, where ‘-‘ represents the looped status. The answer string came from the fourth looped one, where you could cut from the middle character ‘a’ and get “zyxcba”.

Note:

The input strings will only contain lowercase letters.
The total length of all the strings will not over 1,000.
Solution
If the split takes place inside a string, then only this string and its reversed string should be both tried, and for the remaining strings, a string that is lexicographically bigger will always lead to a lexicographically bigger result. So first loop over strs and for each string, reverse it if the reversed string is lexicographically bigger than the original string.

Then for each string in strs, try all possible positions of splitting and form each concatenated string with each splitting position, and return the lexicographically biggest string.

*/

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        for (auto& s : strs) {
            string t{s.rbegin(), s.rend()};
            s = max(s, t);
        }
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < strs.size(); ++i) {
            auto& s = strs[i];
            string t;
            for (int j = i + 1; j < n; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < i; ++j) {
                t += strs[j];
            }
            for (int j = 0; j < s.size(); ++j) {
                auto a = s.substr(j);
                auto b = s.substr(0, j);
                auto cur = a + t + b;
                if (ans < cur) {
                    ans = cur;
                }
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                cur = b + t + a;
                if (ans < cur) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};