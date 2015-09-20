#include<iostream>
//#include<vector>
using namespace std;

struct ListNode {
	ListNode *next;
	int val;
	ListNode(int v): val(v), next(NULL) {} 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *out;
	if (l1==NULL && l2==NULL)
		return NULL;
	else if(l2==NULL){
		out = l1;
		l1=l1->next;
	}else if(l1==NULL){
		out = l2;
		l2 = l2->next;
	}else if(l1->val<=l2->val){
		out = l1;
		l1=l1->next;
	}else{
		out = l2;
		l2=l2->next;
	}
	ListNode *out0=out;
	while(l1!=NULL || l2!=NULL){
		if(l1==NULL){
			out->next = l2;
			break;
		}else if(l2==NULL){
			out->next = l1;
			break;
		}else if(l1->val <= l2->val){
			out->next = l1;
			out = out->next;
			l1=l1->next;
		}else if(l1->val > l2->val){
			out->next = l2;
			out = out->next;
			l2=l2->next;
		}
	}
	return out0;	        
    }
};


int main(){
	ListNode *l1 = new ListNode(0);
	ListNode *l10=l1;
	for (int i=0;i<5;i++){
		l1->next = new ListNode(2*i);
		l1=l1->next;
	}
        ListNode *l2 = new ListNode(1);
	ListNode *l20=l2;
        for (int i=0;i<10;i++){
                l2->next = new ListNode(2*i+1);
		l2 = l2->next;
        }
	Solution sol;
	ListNode *out =  sol.mergeTwoLists(l10,l20);

	while(out!=NULL){
		cout<<out->val<<endl;
		out=out->next;
	}
	return 1;
}

