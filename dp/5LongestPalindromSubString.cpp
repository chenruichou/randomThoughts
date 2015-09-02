#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
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
			fillMatrix(s,a,0,n-1);
			return NULL;        
		}
		void fillMatrix(string s, vector<vector<int>> &a, int i, int j){
			// fill a[i][j] with 1 if indices i to j is a palindrome
			// otherwise, 0
			if (i-1>=0 && j+1<s.size() &&  [i-1]==s[j+1]){
				a[i-1][j+1]=1;
			}
				 
			return;	
		}

};

int main(){
	string s = "ourfatherinheavenhallowbeyourname";
	Solution sol;
	string s_palin = sol.longestPalindrome(s);
	cout << "longest palindrome = "<< s_palin << endl;
	return 1;
}
