// Leetcode 2 Add Two Numbers

// https://leetcode.com/problems/add-two-numbers/description/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are 
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* dummy = new ListNode();
            ListNode* curr = dummy;

            while(l1 || l2 || carry) {
                int sum = carry;

                if(l1) {
                    sum += l1->val;
                    l1 = l1->next;
                }

                if(l2) {
                    sum += l2->val;
                    l2 = l2->next;
                }

                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                carry = (sum >= 10) ? 1 : 0;
            }

            return dummy->next;
        }

};

ListNode* addNodes(std::vector<int>& values);
void displayList(const ListNode* head);

int main() {
    std::vector<int> l1 = {2,4,3};
    std::vector<int> l2 = {5,6,4};

    Solution sol;

    ListNode* head1 = addNodes(l1);
    ListNode* head2 = addNodes(l2);
    ListNode* sum;

    std::cout << "l1: ";
    displayList(head1);
    
    std::cout << "l2: ";
    displayList(head2);

    sum = sol.addTwoNumbers(head1,head2);
    std::cout << "l1 + l2 = ";
    displayList(sum);

    return 0;
}


ListNode* addNodes(std::vector<int>& values) {
    if(values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    for(int i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    return head;
}

void displayList(const ListNode* head) {
    const ListNode* curr = head;

    while(curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}