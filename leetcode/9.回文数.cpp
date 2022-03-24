/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        else if (x == 0) {
            return true;
        }
        else{
            int len;
            int num[99] = {0};
            for (len = 0;x ; ++len){
                num[len] = x % 10;
                x /= 10;
            };
            for (int i = 0; i <= len / 2; ++i){
                if (num[i] != num[len - i - 1]){
                    return false;
                }
            }
            return true;
        }
    }
};
// @lc code=end

