#include<iostream>
#include<vector>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if(head==NULL) return NULL;
			if(k<=0) return head;

			ListNode *head_ori = head;
			ListNode *node_lastk = head;
			ListNode *node_curr=head;
			ListNode *node_lastk_prev=head;
			int count = 0;
			while(head!=NULL){
				if(count>=k){
					node_lastk_prev = node_lastk;
					node_lastk = node_lastk->next;
				}
				count++;
				node_curr = head;
				head = head->next;
			}
			if(k%count==0 || count==1) return head_ori;
			if(count < k){
				k = k%count;
				// do it again
				head = head_ori;
				node_lastk = head;
				node_curr=head;
				node_lastk_prev=head;
				count = 0;
				while(head!=NULL){
					if(count>=k){
						node_lastk_prev = node_lastk;
						node_lastk = node_lastk->next;
					}
					count++;
					node_curr = head;
					head = head->next;
				}
			}

			node_curr->next = head_ori;
			head = node_lastk;
			node_lastk_prev->next = NULL;
			return head;

		}
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	(head->next)->next = new ListNode(3);
	((head->next)->next)->next = new ListNode(4);
	head = sol.rotateRight(head, 5);
	while(head!=NULL){
		cout << head->val << " ";
		head = head->next;	
	}
	cout << endl;
	return 1;
}

