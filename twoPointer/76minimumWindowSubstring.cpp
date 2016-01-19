#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        
        // scan for the target set
        for(int i=0;i<t.size();i++){
            m[t[i]]=1; // build hashtable
        }

        unordered_map<char, int> n;

        // scan for the source set
        for(int i=0; i<s.size();i++){
            if(m[s[i]]==1)
                n[s[i]]++;
        }
    }
};


int main(){
	Solution sol;
	string s="hello";
	string t="eo";
	string out = sol.minWindow(s,t);
	cout << out << endl;
	return 1;
}
