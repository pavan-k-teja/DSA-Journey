/** Leetcode-109
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
            return new TreeNode(head->val);

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow;
        prev->next=nullptr;

        TreeNode *left = sortedListToBST(head);
        TreeNode *right = sortedListToBST(mid->next);

        TreeNode *node = new TreeNode(mid->val, left, right);
        return node;
    }
};