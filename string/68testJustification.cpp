#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> out;
			vector<int> num_char;
			int curr_num_char=0;
			// Scanning through the strings
			for(int i=0;i<words.size();i++){
				curr_num_char+=words[i].size()+1;
				if(curr_num_char>maxWidth+1){
					// save and start a new line
						
				}
			}
			return words;
		}
};


int main(){
	vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	Solution sol;
	vector<string> out = sol.fullJustify(words, 16);
	for(int i=0;i<out.size();i++){
		for(int j=0;j<out[i].size();j++)
			cout << out[i][j] << " ";
		cout << endl;
	}
	return 1;
}
