#include<vector>
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL) {}
};

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head){
            if(head==NULL) return NULL;
            if(head->next==NULL) return head; // one node
            // multi nodes
            ListNode *prev = NULL; // firmed
            ListNode *curr = head; // testing
            ListNode *out = NULL;
            while(curr!=NULL){
                if(curr->next==NULL || curr->val != curr->next->val){
                    if(prev!=NULL){
                        prev->next = curr;
                        prev = curr;
                    }else{
                        prev = curr;
                        out = prev;
                    }
                    curr = curr->next;
                }else{
                    while(curr->next!=NULL && curr->val==curr->next->val){
                        curr = curr->next;
                    }
                    curr = curr->next;
                }
            }
            if(prev)
                prev->next = NULL;
            return out;
        }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    ListNode *out = sol.deleteDuplicates(head);
    // print results
    while(out!=NULL){
        cout << out->val << " ";    
        out = out->next;
    }
    cout << endl;
    return 1;
}
