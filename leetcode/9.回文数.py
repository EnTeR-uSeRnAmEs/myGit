#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        flag = 1
        for i in range(len(x) // 2):
            if x[i] != x[-i - 1]:
                flag = 0
                break
        if flag:
            return True
        else:
            return False
# @lc code=end

