#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeKLists(vector<ListNode *> &lists) {
  int k = lists.size();
  if (k == 0)
    return nullptr;
  if (k == 1)
    return lists[0];
  priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>,
                 greater<pair<int, ListNode *>>>
      pq;
  for (ListNode *node : lists)
    if (node)
      pq.push({node->val, node});

  ListNode *head = new ListNode(-1);
  ListNode *temp = head;
  while (!pq.empty()) {
    auto node = pq.top().second;
    pq.pop();
    
    temp->next = node;
    temp = temp->next;

    if (node->next) {
      node = node->next;
      pq.push({node->val, node});
    }
  }
  return head->next;
}
