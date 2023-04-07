// https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(!l1) return l2;
      if(!l2) return l1;

      // selecting small value as head
      ListNode* head = l1;
      if(l1->val > l2->val){
        head = l2;
        l2 = l2->next;
      } else {
        l1 = l1->next;
      }

      ListNode* curr = head;
      while(l1 && l2) {
        if(l1->val < l2->val) {
          curr->next = l1;
          l1 = l1->next;
        } else {
          curr->next = l2;
          l2 = l2->next;
        }
        curr = curr->next;
      }

      if(!l1) curr->next = l2;
      else curr->next = l1;

      return head;
    };
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Solution sol;
  ListNode* arr1 = new ListNode(1);
  arr1->next = new ListNode(2);
  arr1->next->next = new ListNode(4);
  ListNode* arr2 = new ListNode(1);
  arr2->next = new ListNode(3);
  arr2->next->next = new ListNode(4);
  sol.mergeTwoLists(arr1, arr2);
  return 0;
}