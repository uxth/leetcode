/*

Question
Formatted question description: https://leetcode.ca/all/271.html

271. Encode and Decode Strings
Level
Medium

Description
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:

vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:

The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
Solution
In encode() method, store each string’s length so that the strings can be uniquely determined. For each string str in strs, encode it as the following format: str.length() + "/" + str.

For example, “encode” is encoded as 6/encode. All strings’ encoding results are concatenated together.
In decode() method, each time find the first index of "/", and the substring before "/" is an integer that represents the length of the next string. Convert the substring before "/" into an integer, obtain the substring with the determined length just after "/", and add the substring after "/" to the result list. After one string is decoded, continue with the remaining strings. Finally, return the result list.

You can also use a simpler compression method, add a newline character \0 at the end of each string, which also belongs to a string, so when decoding, just look for the newline character.
*/

// OJ: https://leetcode.com/problems/encode-and-decode-strings/
// Time: O(N)
// Space: O(1)
class Codec {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (string &str : strs) {
            for (char c : str) {
                if (c == '$') ans.push_back(c);
                ans.push_back(c);
            }
            ans.push_back('$');
            ans.push_back('x');
        }
        return ans;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, N = s.size();
        while (i < N) {
            string str;
            for (; i < N; ++i) {
                if (s[i] != '$') str.push_back(s[i]);
                else if (i + 1 < N && s[i + 1] == '$') str.push_back(s[i++]);
                else {
                    i += 2;
                    break;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};