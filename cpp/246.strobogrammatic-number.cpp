/*
Question
Formatted question description: https://leetcode.ca/all/246.html

Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: num = "69"
Output: true
Example 2:

Input: num = "88"
Output: true
Example 3:

Input: num = "962"
Output: false
 

Constraints:

1 <= num.length <= 50
num consists of only digits.
num does not contain any leading zeros except for zero itself.
Algorithm
There are actually few numbers that meet this condition, only 0,1,8,6,9.

This question can actually be regarded as a special case of finding the number of palindromes, or use double pointers to detect it.

If the first and last two numbers are equal, only if they are one of 0,1,8,
If they are not equal, one is 6 and the other is 9, or one is 9 and the other is 6.
All other cases return false

*/
// OJ: https://leetcode.com/problems/strobogrammatic-number/
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool same(char a, char b) {
        return a == b && (a == '0' || a == '1' || a == '8');
    }
    bool match(char a, char b) {
        if (a > b) swap(a, b);
        return same(a, b) || (a == '6' && b == '9');
    }
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        for (; i <= j; ++i, --j) {
            if ((i != j && !match(num[i], num[j]))
               || (i == j && !same(num[i], num[j]))) return false;
        }
        return true;
    }
};