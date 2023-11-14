/*
Given a character array s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

Your code must solve the problem in-place, i.e. without allocating extra space.

 

Example 1:

Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Example 2:

Input: s = ["a"]
Output: ["a"]
 

Constraints:

1 <= s.length <= 105
s[i] is an English letter (uppercase or lowercase), digit, or space ' '.
There is at least one word in s.
s does not contain leading or trailing spaces.
All the words in s are guaranteed to be separated by a single space.
Algorithm
First flip each word, then the entire string,

Or you can reverse the order, first flip the entire string, and then flip each word.
*/

/*
https://leetcode.ca/2016-06-03-186-Reverse-Words-in-a-String-II/
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int i = 0, N = s.size();
        while (i < N) {
            int start = i;
            while (i < N && s[i] != ' ') ++i;
            reverse(begin(s) + start, begin(s) + i);
            ++i;
        }
        reverse(begin(s), end(s));
    }
};