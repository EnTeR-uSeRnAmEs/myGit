/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字�?整数
 */

//private include
#include <bits/stdc++.h>
using namespace std;
#define I 1

// @lc code=start
class Solution {
public:
    inline bool judge1(char a, char b) {
        if (a == 'I' && b == 'V' || a == 'I' && b == 'X') {return true;}
        else if (a == 'X' && b == 'L' || a == 'X' && b == 'C') {return true;}
        else if (a == 'C' && b == 'D' || a == 'C' && b == 'M') {return true;}
        else {return false;}
    };
    inline int judge2(char a) {
        switch (a) {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return 0;
        }
    };
    int romanToInt(string s) {
        int re = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != 0 && judge1(s[i - 1], s[i])) {
                re += (judge2(s[i]) - 2 * judge2(s[i - 1]));
            }
            else re += judge2(s[i]);
        }
        return re;
    }
};
// @lc code=end

