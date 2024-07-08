#pragma once
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0)
        {
            return 0;
        }

        int id = 0;
        while (id < s.size() && s[id] == ' ')
        {
            id++;
        }
        if (id == s.size())
        {
            return 0;
        }

        int sign = 0;

        if (s[id] == '+')
        {
            sign = 1;
            id++;
        }
        else if (s[id] == '-')
        {
            sign = -1;
            id++;
        }
        else
        {
            sign = 1;
        }

        int number = 0;
        while (id < s.size() && ('0' <= s[id]) && (s[id] <= '9'))
        {
            // check if number * 10 overflows
            if (number > INT32_MAX / 10 ||
                (number == INT32_MAX / 10 && s[id] - '0' > INT32_MAX % 10))
            {
                return (sign == 1) ? INT32_MAX : INT32_MIN;
                break;
            }

            // No need to check if number < INT32_MIN / 10, since number and 10 are both positive
            //if (number < INT32_MIN / 10)
            //{
            //    number = INT32_MIN;
            //    break;
            //}

            number = number * 10 + (s[id] - '0');
            
            id++;
        }
        return sign * number;
    }
};