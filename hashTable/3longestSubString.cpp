#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string &s, string &s_out) {
        unordered_map<char,int> map;
	int len=0;
	for (auto it=s.begin(); it!=s.end(); it++){
		if (map[*it]==0){
			// not yet seen
			s_out += *it;
			len+=1;
			map[*it]=it-s.begin()+1;
		}
	}
	return len;
    }
};


int main(){
	Solution sol;
	string s = "abbceabecabdcbb";
	string s_out = "";
	int len = sol.lengthOfLongestSubstring(s,s_out);
	cout << "string = " << s_out << ", length = " << len << endl;

	return 1;
}
