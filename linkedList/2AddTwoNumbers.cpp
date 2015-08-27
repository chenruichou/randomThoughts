/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {} // constructor
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflowBit = 0;
	ListNode *out = l1;
	ListNode *last = NULL;
	while(l1!=NULL){
		if(l1->val+l2->val+overflowBit <10){
			l1->val += l2->val+overflowBit;
			overflowBit = 0;
		}else{
			l1->val += l2->val+overflowBit-10;
			overflowBit = 1;
		}
		last = l1;
		l1=l1->next;
		l2=l2->next;
	}
	if(overflowBit==1){
		last->next = new ListNode(1);
		overflowBit=0;
	}
	return out;
    }
};


int main(){
	ListNode *l1=new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2=new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(6);
	
	// print the testing linked lists
	ListNode *curr=l1;
	while(curr->next!=NULL){
		cout << curr->val << "->";
		curr=curr->next;
	}
	cout << curr->val << endl;

        curr=l2;      
        while(curr->next!=NULL){
                cout << curr->val << "->";
                curr=curr->next;
        }
        cout << curr->val << endl;

	Solution s;
	ListNode *out = s.addTwoNumbers(l1,l2);
	// print the calculated sum
	cout << "Calculated Sum: ";
	curr=out;
        while(curr->next!=NULL){
                cout << curr->val << "->";
                curr=curr->next;
        }
        cout << curr->val << endl;
	return 0;
}
