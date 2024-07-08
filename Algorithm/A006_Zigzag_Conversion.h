#pragma once
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<string> mat(numRows);

        int row = 0;
        int goingDown = 1;

        int id = 0;
        while (id < s.size())
        {
            mat[row].push_back(s[id]);

            row += goingDown;

            if (row == numRows - 1 || row == 0)
            {
                goingDown = -goingDown;
            }

            id++;
        }

        string result;

        for (int i = 0; i < numRows; i++)
        {
            result += mat[i];
        }

        return result;
    }
};