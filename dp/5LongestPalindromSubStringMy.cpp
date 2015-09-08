#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
	string longestPalindromString(string s){
		int n = s.size();
		vector<vector<int>> isPalinMat;
		// Resize to initialize
		isPalinMat.resize(n);
		for (int i=0; i<n; i++){
			isPalinMat[i].resize(n);
		}
		
		// Set the matrix for palindrom with length 1
		for (int i=0; i<n; i++){
			isPalinMat[i][i] = 1;
		}
		
		//Set the matrix for palindrom with length 2
		for (int i=0; i<n-1; i++){
			if(s[i]==s[i+1]){
				isPalinMat[i][i+1]=1;
			}
		}
		// Set the matrix for palindrom with lenght 3 to n
		int longestIndex = 0;
		int longestLen = 0;
		for (int len=2; len<n; len++){
			for (int i=0; i< n-len;i++){
				if(s[i]==s[i+len] && isPalinMat[i+1][i+len-1]==1){
					isPalinMat[i][i+len]=1;
					longestIndex = i;
					longestLen = len+1;
				}
			}
		}
		return s.substr(longestIndex,longestLen);
	}
};




int main(){
	Solution sol;
	string s = "forgeeksskeegfor";	
	string s_out = sol.longestPalindromString(s);
	cout << s << "=>" << s_out << endl;
	return 1;
}
