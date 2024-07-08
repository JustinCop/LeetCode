#pragma once
#include <string>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    // Solution 1. dynamic programming
    string longestPalindrome(string s) {
        assert(s.size() >= 1 && s.size() <= 1000);
        
        if (s.size() < 2)
        {
            return s;
        }

        const int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n));
        // dp[left, right] -> whether s[left]~s[right] is a palindrome.

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        
        int begin = 0;
        int maxLen = 1;
        // 外圈循环是长度，因为更长的sub-string需要上一个长度的结果。
        for (int L = 2; L <= n; L++)    // 长度上限无所谓，反正会判断
        {
            for (int left = 0; left < n; left++)
            {
                int right = left + L - 1;
                if (right >= n)
                {
                    break;
                }

                if (s[left] != s[right])
                {
                    dp[left][right] = false;
                }
                else
                {
                    if (L == 2)
                    {
                        dp[left][right] = true;
                    }
                    else
                    {
                        dp[left][right] = dp[left + 1][right - 1];
                    }
                    if (dp[left][right] && L > maxLen)
                    {
                        begin = left;
                        maxLen = L;
                    }
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};