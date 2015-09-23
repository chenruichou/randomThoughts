#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()==0 && needle.size()==0) return 0;
	else if(needle.size()==0) return 0;
	
	// kmp: make a list of iterative terms to save time re-searching
	vector<int> loc(26,-1); // for 26 chars
	vector<int> p(needle.size(),0); // for 26 chars
	int curr_max = 0;
	for(int i=0;i<needle.size();i++){
		if(loc[needle[i]-'a']==-1){
			loc[needle[i]-'a']=i;
			p[i]=0;
		}else{
			if(loc[needle[i]-'a']>0 && needle[loc[needle[i]-'a']-1]==needle[i-1]){
				p[i] = p[i-1]+1;
				loc[needle[i]-'a']=i;
			}else{
				p[i] = 0;
			}
		}
	}
	
	int i=0;
	int j=0;
	while(i<haystack.size()){
		int curr = i;
		while(haystack[i]==needle[j] && j<needle.size() && i<haystack.size()){
			i++;
			j++;
		}
		if(j==needle.size())
			return i-j;
		i=curr;
		i++;
		j = p[j-1]+1;
	}
	return -1; // not found
    }
};

int main(){
	Solution sol;
	string haystack = "mississippi";
	string needle = "issip";
	int indx = sol.strStr(haystack,needle);
	cout << haystack << ","<<needle<<","<<indx << endl;
	return 1;
}
