#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
		string longestPalindromeDP(string s) {
			int n = s.length();
			int longestBegin = 0;
			int maxLen = 1;
			bool table[1000][1000] = {false};
			for (int i = 0; i < n; i++) {
				table[i][i] = true;
			}
			for (int i = 0; i < n-1; i++) {
				if (s[i] == s[i+1]) {
					table[i][i+1] = true;
					longestBegin = i;
					maxLen = 2;
				}
			}
			for (int len = 3; len <= n; len++) {
				for (int i = 0; i < n-len+1; i++) {
					int j = i+len-1;
					if (s[i] == s[j] && table[i+1][j-1]) {
						table[i][j] = true;
						longestBegin = i;
						maxLen = len;
					}
				}
			}
			return s.substr(longestBegin, maxLen);
		}
		string longestPalindrome(string s) {
			const size_t n=s.size();
			//2d vector initialization
			vector<vector<int>> a;
			int num_cols = n;
			int num_rows = n;
			a.resize(num_rows);
			for(int i=0;i<num_rows;i++){
				a[i].resize(num_cols);
			}
			cout << "a[5][5]=" << a[5][5] << endl;
			fillMatrix(s,a,0,n-1,n);
			return NULL;        
		}
		void fillMatrix(string s, vector<vector<int>> &a, int i, int j, int n){
			// fill a[i][j] with 1 if indices i to j is a palindrome
			// otherwise, 0

			if (i+1<n && j-1>=0 && a[i+1][j-1]==1 && s[i]==s[j]){
				a[i][j]=1;
			}
			if (i-1>=0 && j+1<s.size() &&  s[i-1]==s[j+1]){
				a[i-1][j+1]=1;
			}

			return;	
		}

};

int main(){
	string s = "forgeeksskeegfor";
	Solution sol;
	string s_palin = sol.longestPalindromeDP(s);
	cout << "longest palindrome = "<< s_palin << endl;
	return 1;
}
