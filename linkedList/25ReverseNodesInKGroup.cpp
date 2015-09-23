#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode *> s;
	ListNode *curr = head;
	if(k==1 || head==NULL || head->next==NULL)
            return head;
	ListNode *prev = NULL;
	while(curr!=NULL){
		s.push(curr);
		if(s.size()<k){
			curr=curr->next;
		}else{ //s.size()==2
			ListNode *second = s.top();
			s.pop();
			if(prev!=NULL){
				prev->next = second;
			}else{
				head = second;
			}
			curr = second->next;
			ListNode *first;
			while(s.size()>0){
				first = s.top();
				s.pop();
				second->next = first;
				second = first;
			}
			prev = first;
			prev->next = curr;
		}
	}
	
	return head;
    }
};


int main(){
	Solution sol;
	ListNode *head = new ListNode(0);
	ListNode *curr = head;
	for(int i=1;i<10;i++){
		curr->next = new ListNode(i);
		curr=curr->next;
	}
	//ListNode *out = sol.swapPairs(head);
	ListNode *out = sol.reverseKGroup(head, 3);
	while(out!=NULL){
		cout<<out->val<< " ";
		out=out->next;
	}
	cout << endl;
	return 1;
}
