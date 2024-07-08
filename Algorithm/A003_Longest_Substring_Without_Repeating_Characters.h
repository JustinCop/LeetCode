#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
        {
            return 0;
        }

        unordered_map<char, int> hashTable;
        int str_id_start = 0;
        int longest_length = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            auto iter = hashTable.find(s[i]);
            if (iter == hashTable.end() ||
                hashTable[s[i]] < str_id_start)
            {
                // current char is not yet shown
                hashTable[s[i]] = i;
            }
            else
            {
                // current char already exists
                if (i - str_id_start > longest_length)
                {
                    longest_length = i - str_id_start;
                }
                str_id_start = hashTable[s[i]] + 1;
                hashTable[s[i]] = i;
            }
        }

        // check the last sub-string's length
        if (s.length() - str_id_start > longest_length)
        {
            longest_length = s.length() - str_id_start;
        }

        return longest_length;
    }
};