#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        // kmp: make a list of iterative terms to save time re-searching
	vector<int> p(26,-1); // for 26 chars
	int curr_max = 0;
	for(auto it=needle.begin();it!=needle.end();it++){
		++p[*it-'a'];
	}
	
	

	if(haystack.size()==0 && needle.size()==0) return 0;
	else if(needle.size()==0) return 0;
	int i=0;
	while(i<haystack.size()){
		int j=0;
		int curr = i;
		while(haystack[i]==needle[j] && j<needle.size() && i<haystack.size()){
			i++;
			j++;
		}
		if(j==needle.size())
			return i-j;
		i=curr;
		i++;
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
