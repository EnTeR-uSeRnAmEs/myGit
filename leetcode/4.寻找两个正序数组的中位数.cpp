/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// private include
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int p1nums1 = 0, p1nums2 = 0, p2nums1 = nums1.size() - 1, p2nums2 = nums2.size() - 1;
        int mnums1 = 0, mnums2 = 1;
        while (mnums1 != mnums2)
        {
            mnums1 = (nums1[(p1nums1 + p2nums1) / 2] + nums1[(p1nums1 + p2nums1 + 1) / 2]);
            mnums2 = (nums2[(p1nums2 + p2nums2) / 2] + nums2[(p1nums2 + p2nums2 + 1) / 2]);
            if (mnums1 < mnums2)
            {
                p1nums1 = (p1nums1 + p2nums1 + 1) / 2;
                p2nums2 = (p1nums2 + p2nums2) / 2;
            }
            else
            {
                p1nums2 = (p1nums1 + p2nums1 + 1) / 2;
                p2nums1 = (p1nums2 + p2nums2) / 2;
            }
            cout << mnums1 << " " << mnums2 << endl;
            cout << p1nums1 << " " << p2nums1 << endl;
            cout << p1nums2 << " " << p2nums2 << endl;
        }
        double re = mnums1 / 2;
        return re;
    }
};
// @lc code=end
