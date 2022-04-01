/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子�?
 */

//private include
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, length = 0, count = 0;
        while(right < s.length()) {
        	for(int i = left; i < right; i++) {
        		if(s[i] == s[right]) {
					left = i+1;
                    break;
				}
			}
            length = right-left+1;
			count = max(count,length);
			right++;
        }
        return count;
    }
};
// @lc code=end

