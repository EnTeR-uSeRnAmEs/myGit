/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

//private include
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str_re = strs[0];
        for (int i = 1; i < strs.size(); ++i){
            for (int j = 0; j < str_re.length(); ++j){
                if (strs[i][j] != str_re[j]){
                    str_re = str_re.substr(0, j);
                    break;
                }
            }
        }
        return str_re;
    }
};
// @lc code=end

