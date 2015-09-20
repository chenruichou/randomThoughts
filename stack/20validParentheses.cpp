#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
	unordered_map<char,char> m;
	m['{']='}';
	m['[']=']';
	m['(']=')';
        stack<char> t;
	t.push(s[0]);
	
//	cout<<*(s.end()-1)<<endl;
	for(auto it=s.begin()+1;it!=s.end();it++){
		char c = t.top();
		if (m[c]!=*it){
			t.push(*it);
		}else{
			t.pop();
		}
	}
	return t.empty();
    }
};


int main(){
	Solution sol;
	string in = "{[]}";
	bool out = sol.isValid(in);
	cout<<out<<endl;
	return 1;
}
