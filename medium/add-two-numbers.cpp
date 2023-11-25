#include <iostream>

/* Runtimr: 32 ms, Memory Usage: 71.7 MB */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int extra = 0;
    ListNode* result = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        ListNode* node = new ListNode((l1->val + l2->val + extra) % 10, result);
        result = node;

        if (l1->val + l2->val + extra > 9) {
            extra = 1;
        } else {
            extra = 0;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {
        ListNode* node = new ListNode((l1->val + extra) % 10, result);
        result = node;

        if (l1->val + extra > 9) {
            extra = 1;
        } else {
            extra = 0;
        }
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        ListNode* node = new ListNode((l2->val + extra) % 10, result);
        result = node;

        if (l2->val + extra > 9) {
            extra = 1;
        } else {
            extra = 0;
        }
        l2 = l2->next;
    }

    if (extra) {
        ListNode* node = new ListNode(1, result);
        result = node;
    }

    ListNode *prev = nullptr, *now = result, *next = result->next;

    while (next != nullptr) {
        now->next = prev;
        prev = now;
        now = next;
        next = next->next;
    }
    now->next = prev;
    prev = now;
    result->next = nullptr;

    return prev;
}

int main()
{
    ListNode arg1_1(3);
    ListNode arg1_2(4, &arg1_1);
    ListNode arg1_3(2, &arg1_2);
    ListNode arg2_1(4);
    ListNode arg2_2(6, &arg2_1);
    ListNode arg2_3(5, &arg2_2);
    ListNode* result = addTwoNumbers(&arg1_3, &arg2_3);

    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}
