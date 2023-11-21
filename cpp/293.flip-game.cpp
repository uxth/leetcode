/*

Question
Formatted question description: https://leetcode.ca/all/293.html

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return all possible states of the string currentState after one valid move. You may return the answer in any order. If there is no valid move, return an empty list [].

 

Example 1:

Input: currentState = "++++"
Output: ["--++","+--+","++--"]
Example 2:

Input: currentState = "+"
Output: []
 

Constraints:

1 <= currentState.length <= 500
currentState[i] is either '+' or '-'.
Algorithm
Start traversing from the second letter, each time it is judged whether the current letter is +, and the previous letter is +, if both are plus, the reversed string will be stored in the result.
*/

// OJ: https://leetcode.com/problems/flip-game/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 1, N = s.size(); i < N; ++i) {
            if (s[i] != '+' || s[i - 1] != '+') continue;
            ans.push_back(s);
            ans.back()[i] = ans.back()[i - 1] = '-';
        }
        return ans;
    }
};