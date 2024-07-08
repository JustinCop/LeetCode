#pragma once
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        bool xLessThanZero = (x < 0);

        x = std::abs(x);

        while (x > 0)
        {
            int i = x % 10;

            // multiply by 10, judge if it overflow
            if (result > INT32_MAX / 10 || result < INT32_MIN / 10)
            {
                return 0;
            }
            
            result = result * 10 + i;
            if (result < 0) // overflow
            {
                return 0;
            }
            x /= 10;
        }

        if (xLessThanZero)
        {
            return -result;
        }
        else
        {
            return result;
        }


    }
};