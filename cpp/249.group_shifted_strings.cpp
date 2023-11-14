/*

Question
Formatted question description: https://leetcode.ca/all/249.html

We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

 

Example 1:

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
Example 2:

Input: strings = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strings.length <= 200
1 <= strings[i].length <= 50
strings[i] consists of lowercase English letters.
Algorithm
The relative distance between each letter of the string and the first character is equal.

For example, abc and efg are mutually offset. For abc, the distance between b and a is 1, and the distance between c and a is 2. For efg, the distance between f and e is 1, and the distance between g and e is 2.

Let’s look at another example. The distance between az and yx, z and a is 25, and the distance between x and y is also 25 (direct subtraction is -1, which is the reason for adding 26 and taking the remainder).

Then, in this case, all strings that are offset from each other have a unique distance difference. According to this, the mapping can be well grouped.

*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strings) {
            int diff = s[0] - 'a';
            string t = s;
            for (int i = 0; i < t.size(); ++i) {
                char d = t[i] - diff;
                if (d < 'a') d += 26;
                t[i] = d;
            }
            cout << t << endl;
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& e : mp)
            ans.push_back(e.second);
        return ans;
    }
};