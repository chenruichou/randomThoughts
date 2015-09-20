#include<vector>
#include<iostream>
using namespace std;
template <typename T>
struct link{
	link *next;
	T val;
	link(int v): val(v), next(NULL) {}   
};

class Solution{
	public:
	struct link<int> *rmNode(int n, struct link<int> *l){
		int indx_curr=0;
		int indx_out=0;
		link<int> *l0=l;
		link<int> *out_prev = l;
		link<int> *out = l;
		while(l!=NULL){
			//skiped
			if(indx_curr-indx_out>n-1){
				out_prev = out;
				out = out->next;
				indx_out++;
			}
			l=l->next;
			indx_curr++;			
		}
		if(indx_out==0)
			return NULL;
		else{
			out_prev->next = out->next;		
			return l0;
		}
	}
};

int main(){
	Solution sol;
	link<int> *l = new link<int>(0);
	link<int> *l0 = l;
	for(int i=1;i<15;i++){
		l->next = new link<int>(i);
		l = l->next;
	}
	l = l0;
	while (l!=NULL){
		cout << l->val  << endl;
		l=l->next;
	}
	struct link<int> *out = sol.rmNode(1, l0);
	l=out;
	while (l!=NULL){
                cout << l->val  << endl;
                l=l->next;
        }
	return 1;
}
