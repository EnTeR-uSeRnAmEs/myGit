/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 鏈夋晥鐨勬嫭鍙�
 */

//private include
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len % 2 == 1)
            return false;
        unordered_map<char,char> umap {
            {')', '('},
            {']', '['},
            {'}', '{'} };
        stack<char> stk;
        for (int i = 0; i < len; ++i){
            if (umap.count(s[i])){
                if (stk.empty() || umap[s[i]] != stk.top()) 
                    return false;
                else
                    stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return stk.empty();
    }
};
// @lc code=end

