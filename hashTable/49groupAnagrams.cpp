#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> out;
			vector<string> strs_origin(strs);
			unordered_map<string,vector<int>> m; // sorted string to index mapping
			for(int i=0;i<strs.size();i++){
				sort(strs[i].begin(),strs[i].end());
				m[strs[i]].push_back(i); 
			}
			// scan through the hashtable
			for(auto it=m.begin();it!=m.end();it++){
				//NOTE!! check if not empty
				if(it->second.size()>1) {
					// not sorted
					vector<string> v;
					for(int i=0;i<it->second.size();i++){
						v.push_back(strs_origin[it->second[i]]);
					
					}
					out.push_back(v);

				}else{
					out.push_back(vector<string> (1,strs_origin[it->second[0]]));
				}

			} 
			return out;   
		}
};

int main(){
	Solution sol;
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> out = sol.groupAnagrams(strs);
	for(int i=0;i<out.size();i++){
		for(int j=0; j<out[i].size();j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}
