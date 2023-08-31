#
# @lc app=leetcode id=231 lang=python3
#
# [231] Power of Two
#

# @lc code=start
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        count = 0
        while n != 0:
            count += 1 if n & 1 == 1 else 0
            if count > 1:
                return False
            n = n >> 1
        return True
# @lc code=end

