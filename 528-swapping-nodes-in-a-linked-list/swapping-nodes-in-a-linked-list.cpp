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
class Solution {
public:
    void trav(ListNode* head,vector<int> &arr)
    {
        while(head != NULL)
        {
            arr.push_back(head -> val);
            head = head -> next;
        }
        return;
    }
    ListNode* form(vector<int> arr)
    {
        ListNode* node = new ListNode(arr[0]);
        ListNode* head = node;
        int n = arr.size();

        for(int i=1;i<n;i++)
        {
            ListNode* temp = new ListNode(arr[i]);
            node -> next = temp;
            node = node -> next;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        trav(head,arr);

        int n = arr.size();
        for(auto it : arr) cout << it << " ";
        swap(arr[k-1],arr[n-k]);
        for(auto it : arr) cout << it << " ";
        head = form(arr);
        return head;
    }
};