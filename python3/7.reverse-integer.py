#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x):
        if x < 0:
            return -1 * self.reverseUtil(-x)
        return self.reverseUtil(x)
        
    def reverseUtil(self, x):
        result = 0
        while x != 0:
            digit = x % 10
            result = result * 10 + digit
            x = x // 10
			
        return 0 if result > pow(2, 31) - 1 or result < -pow(2, 31) else result
# @lc code=end

