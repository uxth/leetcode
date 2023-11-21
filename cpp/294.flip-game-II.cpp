/*

Question
Formatted question description: https://leetcode.ca/all/294.html

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.

 

Example 1:

Input: currentState = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Example 2:

Input: currentState = "+"
Output: false
 

Constraints:

1 <= currentState.length <= 60
currentState[i] is either '+' or '-'.
 

Follow up: Derive your algorithm's runtime complexity.

Algorithm
The function canWin means “In the current state, there is at least one possible option that can make him/her win”.

*/


// OJ: https://leetcode.com/problems/flip-game-ii/
// Time: O(N!)
// Space: O(N!)
class Solution {
public:
    bool canWin(string s) {
        bitset<60> bs;
        int cnt = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '+') {
                bs.set(i);
                ++cnt;
            }
        }
        unordered_map<bitset<60>, bool> m;
        function<bool()> dp = [&]() {
            if (cnt == 0 || cnt == 1) return false;
            if (m.count(bs)) return m[bs];
            bool ans = false;
            for (int i = 0; i + 1 < N && !ans; ++i) {
                if (bs.test(i) && bs.test(i + 1)) {
                    bs.reset(i);
                    bs.reset(i + 1);
                    cnt -= 2;
                    if (!dp()) ans = true;
                    bs.set(i);
                    bs.set(i + 1);
                    cnt += 2;
                }
            }
            return m[bs] = ans;
        };
        return dp();
    }
};