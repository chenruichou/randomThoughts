#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
	string s(2*n,'*');
	int sum=0;
	int indx=0;
	genAllParentheses(indx,n,s,out,sum);
	return out;
    }

    void genAllParentheses(int indx, int n, string s, vector<string> &out,int sum){
	if(indx==2*n){
		out.push_back(s);
		return;
	}else{
		if(sum==0){
			s[indx]='(';
			genAllParentheses(indx+1,n,s,out,sum+1);
		}else if(sum==2*n-indx){
			s[indx]=')';
			genAllParentheses(indx+1,n,s,out,sum-1);
		}else{
			s[indx]='(';
			genAllParentheses(indx+1,n,s,out,sum+1);
			s[indx]=')';
			genAllParentheses(indx+1,n,s,out,sum-1);	
		}
		return;
	}
    }
};

int main(){
	Solution sol;
	vector<string> out;
	out = sol.generateParenthesis(3);
	for(auto it=out.begin();it!=out.end();it++){
		cout << *it << endl;
	}
	return 1;
}
