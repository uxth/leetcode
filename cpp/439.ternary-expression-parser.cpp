/*

Description
Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"
Solution
Use two stacks stack1 and stack2 to store the characters in expression. Loop over expression from left to right and add each character into stack1.

While stack1 contains more than one element, do operation on stack1. Each time pop two elements c1 and c2 from stack1, where c1 must be a digit or a boolean letter, and c2 must be a ? or :. If c2 is :, then there will be more elements before meeting a ?, so push c1 into stack2. If c2 is ?, then pop one more element from stack1, which must be a boolean letter. If the boolean letter is T, then c1 is the result of the current ternary expression. Otherwise, the top element of stack2 is the result of the current ternary expression. Pop one element from stack2 and push the result of the current ternary expression into stack1. Repeat the process until there is only one element in stack1.

Finally, pop the one element from stack1, convert it into a string and return.

*/

// OJ: https://leetcode.com/problems/ternary-expression-parser/
// Time: O(NL) where L is the level of nesting
// Space: O(NL)
class Solution {
public:
    string parseTernary(string s) {
        if (s.size() == 1) return s;
        bool left = s[0] == 'T';
        int cnt = 0, N = s.size(), i = 2;
        for (; i < N && cnt >= 0; ++i) {
            if (s[i] == '?') ++cnt;
            else if (s[i] == ':') --cnt;
        }
        return parseTernary(left ? s.substr(2, i - 3) : s.substr(i));
    }
};