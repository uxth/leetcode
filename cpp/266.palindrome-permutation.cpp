/*

Question
Formatted question description: https://leetcode.ca/all/266.html

Given a string s, return true if a permutation of the string could form a palindrome and false otherwise.

 

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
 

Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.
Algorithm
Use HashSet to traverse the string

If a letter is not in the HashSet, we add this letter,
If the letter already exists, we delete the letter, So in the end, if there are no letters or only one letter in the HashSet, it means that it is a palindrome.

*/

// OJ: https://leetcode.com/problems/palindrome-permutation/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[26] = {}, single = 0;
        for (char c : s) cnt[c - 'a']++;
        for (int n : cnt) {
            single += n % 2;
            if (single > 1) return false;
        }
        return true;
    }
};