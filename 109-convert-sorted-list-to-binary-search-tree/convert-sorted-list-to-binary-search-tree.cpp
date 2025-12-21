/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* curr;  // global pointer

    TreeNode* build(int n) {
        if (n <= 0) return NULL;

        // build left subtree
        TreeNode* left = build(n / 2);

        // current list node becomes root
        TreeNode* root = new TreeNode(curr->val);
        root->left = left;

        // move list pointer
        curr = curr->next;

        // build right subtree
        root->right = build(n - n / 2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;

        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }

        return build(n);
    }
};
