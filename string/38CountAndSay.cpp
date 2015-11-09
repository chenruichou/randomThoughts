#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string s="1";
		string s_new="";
		if(n<1) return "";
		int d = 1;
		char prev = s[0];
		char curr = 'x';
		while(d<=n){
			int count = 1;
			for(auto it=s.begin();it!=s.end();it++){
				cout<<*it<<endl;
				curr = *it;
				if(curr==prev){
					count++;
				}else{
					s_new.push_back((char)('0'+count));
					s_new.push_back(prev);
					
					// reset
					count = 1;
					prev = curr;
				}
			}
			cout<<s_new<<endl;
			s = s_new;
			s_new.clear();
			d++;
		}
		return s;
	}

};


int main(){
	string s = "1";
	Solution sol;
	int n=3;
	sol.countAndSay(n);
	return 1;
}
