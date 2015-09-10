#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p=="" && s=="")
		return true;
	else if(p!="" && s=="")
		return false;
	else if (p=="" && s!="")
		return false;
	else if(p[0]=='.'){
		return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
	}else if(p[0]=='*'){
		//find the next
		bool ret=false;
		for(int i=0; i<s.size(); i++){
			ret = ret || isMatch(s.substr(i+1,s.size()-i-1),p.substr(1,p.size()-1));
		}
		return ret;	
	}else{
		if(s[0]!=p[0])
			return false;
		else{
			return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
		}
	}
    }
};

int main(){
	Solution sol;
	bool out = sol.isMatch("aab","c*a*b");
	cout << out << endl;	
	return 1;
}
