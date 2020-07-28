/*
    https://leetcode.com/problems/add-two-numbers/
*/

/*
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
 */
#include<iostream>
#include<limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *it = nullptr;
        ListNode *result = nullptr;
        ListNode **resIt = &result;
        int overflow = 0;
        int value;
        int val1, val2;

        if (l1) result = l1;
        else if (l2) result = l2;

        while (l1 && l2) {
            value = l1->val + l2->val + overflow;
            overflow = value / 10;
            value = value % 10;

            (*resIt)->val = value;
            resIt = &(*resIt)->next == nullptr ? nullptr : &(*resIt)->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if ((*resIt) == nullptr) {
            if (l1) (*resIt) = l1;
            else if (l2) (*resIt) = l2;
        }
        while (l1) {
            value = l1->val + overflow;
            overflow = value / 10;
            value = value % 10;
            (*resIt)->val = value;
            resIt = &(*resIt)->next == nullptr ? nullptr : &(*resIt)->next;
            l1 = l1->next;
        }
        while (l2) {
            value =  l2->val + overflow;
            overflow = value / 10;
            value = value % 10;
            (*resIt)->val = value;
            resIt = &(*resIt)->next == nullptr ? nullptr : &(*resIt)->next;
            l2 = l2->next;
        }
        if (overflow) {
            if (*resIt)
                (*resIt)->val = overflow;
            else
                (*resIt) = new ListNode(overflow);
        }
        return result;
    }
};

void printList (ListNode *list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << "\n";
}

int main ()
{
    ListNode list1 {2, new ListNode{4, new ListNode{3}}};
    ListNode list2 {5, new ListNode{6, new ListNode{4}}};

    ListNode list3 { 9};
    ListNode list4 { 1, new ListNode {9, new ListNode {9, new ListNode { 9,
                           new ListNode { 9, new ListNode { 9, new ListNode {9,
                            new ListNode {9, new ListNode { 9, new ListNode { 9}}}}}}}}}};

    Solution solution;
    ListNode *result = solution.addTwoNumbers(&list3, &list4);
    printList(result);

    return 0;
}