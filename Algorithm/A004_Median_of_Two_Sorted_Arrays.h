#pragma once
#include <vector>
using namespace std;

class Solution {
public:

    //Solution 1. merge two arrays, then find median (timeing O(m+n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;

        vector<int> nums;

        while (i1 != nums1.size() && i2 != nums2.size())
        {
            if (nums1[i1] < nums2[i2])
            {
                nums.push_back(nums1[i1]);
                i1++;
            }
            else
            {
                nums.push_back(nums2[i2]);
                i2++;
            }
        }

        if (i1 == nums1.size())
        {
            for (int j = i2; j < nums2.size(); j++)
            {
                nums.push_back(nums2[j]);
            }
        }
        else
        {
            for (int j = i1; j < nums1.size(); j++)
            {
                nums.push_back(nums1[j]);
            }
        }

        int totalsize = nums.size();
        if (totalsize % 2 == 0)
        {
            return (nums[totalsize / 2 - 1] + nums[totalsize / 2]) / 2.f;
        }
        else
        {
            return nums[totalsize / 2];
        }
    }

};