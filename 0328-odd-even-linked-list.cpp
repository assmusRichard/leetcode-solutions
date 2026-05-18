// Leetcode 328 Odd Even Linked List

// https://leetcode.com/problems/odd-even-linked-list/description/

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes 
with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
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
        ListNode* oddEvenList(ListNode* head) {
            if(!head || !head->next) return head;

            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;

            while(even && even->next){
                odd->next = even->next;
                odd = odd->next;

                even->next = odd->next;
                even = even->next;
            }

            odd->next = evenHead;

            return head;
        }
};

ListNode* addNodes(std::vector<int>& values);
void displayList(ListNode* head);

int main() {

    std::vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    Solution sol;
    ListNode* head1 = addNodes(v1);

    std::cout << "list: ";
    displayList(head1);

    sol.oddEvenList(head1);

    std::cout << "after oddEven: ";
    displayList(head1);

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

void displayList(ListNode* head) {
    ListNode* curr = head;

    while(curr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}