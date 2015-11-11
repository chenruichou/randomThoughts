#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
	//swap four pixels simutaneously, index through a quadran
	int n=matrix.size();	 
	// tearing onion
	int l1 = n%2==0 ? n/2 : (n+1)/2;
	for(int i=0;i<l1;i++){
		int l2 = n%2==0 ? n/2 : n/2;
		for(int j=0; j<l2; j++){
			int temp = matrix[i][j];
			matrix[i][j]=matrix[n-j-1][i];
			matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
			matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
			matrix[j][n-i-1] = temp;
		}
	}
	return;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> m(10,vector<int> (10,1));
	m[2][1]=3;
	sol.rotate(m);
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 1;
}
