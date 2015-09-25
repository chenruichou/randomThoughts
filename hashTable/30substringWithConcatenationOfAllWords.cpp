#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> out;
	int n=words[0].size(); // length of each word
	unordered_map<string, int> m;
	// emplace into hashtable
	for(auto it=words.begin();it!=words.end();it++){
		m[*it] = it-words.begin()+1;
	}
	
	// scan to find all of the occurences
	int c=0;
	int r=0; // number of matched words 
	vector<bool> isVisited(words.size(),0);
	while(c<s.size()){
		string testStr = s.substr(c,n); 
		if(m[testStr]>0){
			if(isVisited[m[testStr]-1]==1){
				// already visited
				isVisited = reset(isVisited);
				r=0;
				c++;
			}else{
				isVisited[m[testStr]-1]=1;
				r++;
				c+=n;
				if(r==words.size()){
					out.push_back(c-n*words.size());
					r=0;
					isVisited = reset(isVisited);
				}
			}
		}else{
			c++;
			r=0;
			isVisited = reset(isVisited);
		}
	}
	return out;
    }
    vector<bool> reset(vector<bool> &isVisited){
    	for(auto it=isVisited.begin();it!= isVisited.end();it++){
		*it = 0;
	}
	return isVisited;
    }
};

int main(){
	Solution sol;
	string s = "barfoothefoobarman";
	vector<string> words = {"foo","bar"};
	vector<int> out = sol.findSubstring(s, words);
	cout << out.size() << "found!" << endl;
	for(auto it=out.begin();it!=out.end();it++){
		cout << *it << " ";
	}
	cout<<endl;

	return 1;
}
