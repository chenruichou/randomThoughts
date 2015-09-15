#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	int d=0;
	bool is_quit=0;
	while (!is_quit){
		char c = (strs[0])[d];
		for (auto it=strs.begin()+1;it!=strs.end();it++){
			if((*it).size()<d+1 || (*it)[d]!=c)
				is_quit = 1;		
		}
		if(!is_quit)
			d++;
	}
	return (strs[0]).substr(0,d);
    }
};

int main(){
	vector<string> strs = {"hallo","hallow","half"};
	Solution sol;
	string out = sol.longestCommonPrefix(strs);
	if(!out.empty())
		cout<<out<<endl;
	else
		cout<<"Nothing matched"<<endl;	
	return 1;
}
