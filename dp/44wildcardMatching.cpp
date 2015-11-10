#include<iostream>
#include<vector>
#include<string>
using namespace std;            
class Solution {
	public:
		bool isMatch(string s, string p){
			if (s=="" && p=="") return true;
			if (s=="" && p!="") return false;
			if (s!="" && p=="") return false;
			if (p[0]=='?') return isMatch(s.substr(1, s.size()-1),p.substr(1,p.size()-1));
			if (p[0]=='*') {
				bool ret=false;
				//backtracking
				for(int i=0;i<s.size();i++){
					// skipped i items
					ret |= isMatch(s.substr(i+1,s.size()-i-1),p.substr(1,p.size()-1));
				}
				return ret;
			}
		}
};

int main(){
	Solution sol;
	cout<< sol.isMatch("ab","?*") << endl;
	return 1;
}
