#include <iostream>
#include <stack>

/* Runtimr: 3 ms, Memory Usage: 15.5 MB */

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    std::stack<int> stack;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            stack.push(list1->val);
            list1 = list1->next;
        } else {
            stack.push(list2->val);
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        stack.push(list1->val);
        list1 = list1->next;
    }

    while (list2 != nullptr) {
        stack.push(list2->val);
        list2 = list2->next;
    }

    ListNode* result = nullptr;
    while (!stack.empty()) {
        ListNode* node = new ListNode(stack.top(), result);
        result = node;
        stack.pop();
    }

    return result;
}

int main()
{
    ListNode arg1_1(4);
    ListNode arg1_2(2, &arg1_1);
    ListNode arg1_3(1, &arg1_2);
    ListNode arg2_1(4);
    ListNode arg2_2(3, &arg2_1);
    ListNode arg2_3(1, &arg2_2);
    ListNode* result = mergeTwoLists(&arg1_3, &arg2_3);

    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}