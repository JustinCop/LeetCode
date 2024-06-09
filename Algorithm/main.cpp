#include "A002_addTwoNumbers.h"

int main()
{
    Solution s;

    int arr1[] = { 9,9,9,9,9,9,9 };
    Solution::ListNode* l1 = s.CreateListNode(arr1, 7);

    int arr2[] = { 9,9,9,9 };
    Solution::ListNode *l2 = s.CreateListNode(arr2, 4);


    auto ret = s.addTwoNumbers(l1, l2);
}