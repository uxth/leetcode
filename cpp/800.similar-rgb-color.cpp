/*

In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:  
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same (highest) similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters, and the output is 7 characters.
Companies:
Google

Related Topics:
Math, String


*/

// OJ: https://leetcode.com/problems/similar-rgb-color/
// Time: O(1)
// Space: O(1)
class Solution {
private:
    const string digits = "0123456789abcdef";
public:
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 0; i < 3; ++i) {
            char a = color[1 + i * 2], b = color[2 + i * 2];
            int hex1 = stoi(color.substr(1 + i * 2, 2), nullptr, 16);
            int best = 0, bestSim = INT_MIN;
            for (int j = 0; j < 16; ++j) {
                int hex2 = j * 16 + j;
                int sim = -pow(hex1 - hex2, 2);
                if (sim > bestSim) {
                    bestSim = sim;
                    best = j;
                }
            }
            char c = digits[best];
            ans += c;
            ans += c;
        }
        return ans;
    }
};