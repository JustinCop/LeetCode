#pragma once


// Definition for singly-linked list.


class Solution
{
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *CreateListNode(int arr[], int count)
    {
        if (count <= 0)
        {
            return nullptr;
        }
        ListNode *pHead = new ListNode(arr[0]);
        ListNode *pCur = pHead;
        for (int i = 1; i < count; i++)
        {
            pCur->next = new ListNode(arr[i]);
            pCur = pCur->next;
        }
        return pHead;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        const ListNode *p1 = l1;
        const ListNode *p2 = l2;

        ListNode *pHead = nullptr;
        ListNode *pCur = nullptr;
        
        int carry = 0;
        
        while (p1 != nullptr || p2 != nullptr)
        {
            // check if p1 or p2 is null
            int n1 = p1 ? p1->val : 0;
            int n2 = p2 ? p2->val : 0;
            int sum = n1 + n2 + carry;
            
            if (pHead == nullptr)
            {
                pHead = pCur = new ListNode(sum % 10);
            }
            else
            {
                pCur->next = new ListNode(sum % 10);
                pCur = pCur->next;
            }

            carry = pCur->val / 10;

            if (p1)
            {
                p1 = p1->next;
            }
            if (p2)
            {
                p2 = p2->next;
            }
        }

        // final carry
        if (carry)
        {
            pCur->next = new ListNode(carry);
        }

        return pHead;
    }
};