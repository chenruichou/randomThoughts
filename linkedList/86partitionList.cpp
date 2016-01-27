#include<vector>
#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            if(head==NULL) return NULL;
            ListNode *curr = head;
            ListNode *small_begin=NULL;
            ListNode *small_end=NULL;
            ListNode *large_begin=NULL;
            ListNode *large_end = NULL;
            while(curr!=NULL){
                if(curr->val < x){
                    if(small_begin==NULL){
                        small_begin = curr;
                        small_end = curr;
                    }else{
                        small_end->next = curr;
                        small_end = curr;
                    }
                    
                }else{
                    if(large_begin==NULL){
                        large_begin = curr;
                        large_end = curr;
                    }else{
                        large_end->next = curr;
                        large_end = curr;
                    }
                }
                curr = curr->next;
            }
            if(small_end!=NULL){
                small_end->next = large_begin;
            }else{
                small_begin = large_begin;
            }
            if(large_end!=NULL){
                large_end->next = NULL;// add NULL at the end
            }
            return small_begin;
        }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode *out = sol.partition(head, 3);
    while(out!=NULL){
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl;
    return 1;
}
