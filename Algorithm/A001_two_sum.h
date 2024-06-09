#pragma once
#include <vector>
#include <unordered_map>
using namespace std;


// 1. Two's sum
class Solution {
public:
    //// Solution 1. brute force
    //vector<int> twoSum(vector<int> &nums, int target) {
    //    for (int i = 0; i < nums.size(); i++)
    //    {
    //        int a = nums[i];
    //        int b = target - a;
    //        for (int j = i + 1; j < nums.size(); j++)
    //        {
    //            if (nums[j] == b)
    //            {
    //                return { i, j };
    //            }
    //        }
    //    }
    //    return {};
    //}

    // Solution 2. Use hash table
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashTable;  // (value, index)
        for (int i = 0; i < nums.size(); i++)
        {
            const int &value = nums[i];
            auto iter = hashTable.find(target - value);
            if (iter != hashTable.end())
            {
                return { i, iter->second };
            }
            else
            {
                hashTable.insert({ value, i });
            }
        }
        return {};
    }
};

