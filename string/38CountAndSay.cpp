#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string s="1";
		if(n<1) return "";
		int d = 1;
		while(d<=n){
			string s_new = "";
			char prev = s[0];
			int count = 1;
			for(auto it=s.begin()+1;it!=s.end();it++){
				char curr = *it;
				if(curr==prev){
					count++;
				}else{
					s_new.push_back((char) '0'+count);
					s_new.push_back(prev);
					
					// reset
					count = 1;
					prev = curr;
				}
			}
			// push the last
			s_new.push_back((char) '0'+count);
			s_new.push_back(prev);
			s = s_new;
			cout<<s_new<<endl;
			d++;
		}
		return s;
	}

};


int main(){
	string s = "1";
	Solution sol;
	int n=10;
	sol.countAndSay(n);
	return 1;
}
