/*

Description
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1+1"
Output: 2
Example 2:

Input: s = "6-4/2"
Output: 4
Example 3:

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
 

Constraints:

1 <= s <= 104
s consists of digits, '+', '-', '*', '/', '(', and ')'.
s is a valid expression.
Solution
Three steps to evaluate a simple expression string:
Step 1:
Reformat the expression string by removing all empty spaces. If a minus sign ‘-‘ appears at the beginning of the expression string or immediately after an open parenthesis ‘(‘, add a zero ‘0’ before the minus sign.

Step 2:
Convert the infix expression to postfix expression. Use a stack to store operators. Loop over the infix expression from start to end. If the current element is a digit, generate the number by considering one or more consecutive digits. If the element is an operator, separate it from the expression. Take into account the precedence of the current operator and the operator at the top of the stack. Note that ‘*’ and ‘/’ have higher precedence than ‘+’ and ‘-‘.

If the precedence of the current operator is equal to or lower than the precedence of the operator at the top of the stack, pop operators from the stack and append them to the postfix expression in the same order they are popped, until either the stack is empty or the top operator has lower precedence than the current operator. Push the current operator onto the stack.
If the current element is an open parenthesis, push it onto the stack. If it is a close parenthesis, pop operators from the stack and append them to the postfix expression in the same order they are popped, until the top of the stack is an open parenthesis. Finally, pop the open parenthesis from the stack.
If the stack is not empty, pop the remaining operators from the stack and append them to the postfix expression in the same order they are popped.
Step 3:
Evaluate the postfix expression using a stack to store numbers. Loop over the postfix expression from start to end. If the current element is a number, push it onto the stack. If it is an operator, pop two numbers from the stack, perform the corresponding operation, and push the result back onto the stack. After iterating through the entire postfix expression, there should be only one number remaining in the stack, which represents the result of the expression. Pop the stack and return the result.

*/


// OJ: https://leetcode.com/problems/basic-calculator-iii/
// Time: O(N)
// Space: O(N)
class Solution {
    stack<long> num;
    stack<char> op;
    unordered_map<char, int> priority{ {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
    void eval() {
        long b = num.top(); num.pop();
        char c = op.top(); op.pop();
        switch (c) {
            case '+': num.top() += b; break;
            case '-': num.top() -= b; break;
            case '*': num.top() *= b; break;
            case '/': num.top() /= b; break;
        }
    }
public:
    int calculate(string s) {
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                long n = 0;
                while (i < N && isdigit(s[i])) n = n * 10 + s[i++] - '0';
                --i;
                num.push(n);
            } else if (s[i] == '('){
                op.push(s[i]);
            } else if (s[i] == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                while (op.size() && op.top() != '(' && priority[op.top()] >= priority[s[i]]) eval();
                op.push(s[i]);
            }
        }
        while (op.size()) eval();
        return num.top();
    }
};