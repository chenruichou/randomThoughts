#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
    public:
    ListNode *reverseBetween(ListNode *head, int m, int n){
        int c=1;
        ListNode *curr = head;
        ListNode *before=NULL;
        ListNode *t;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(c<=n){
            if(c<m){
                if(c==m-1)
                    before = curr;
                next = curr->next;  
            }else{
                if(c==m)
                    t = curr;
                next = curr->next;
                curr->next = prev;
            }
            prev = curr;
            curr = next;
            c++;
        }
        t->next = curr;
        if(before!=NULL)
            before->next = prev;
        else
            head = prev;
        return head;        
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    for(int i=1;i<5;i++){
        curr->next = new ListNode(i+1);
        curr = curr->next;
    }
    ListNode *out = sol.reverseBetween(head, 1, 4);
    while(out!=NULL){
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl;
    return 1;
}
