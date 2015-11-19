#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			if(m<1 || n <1) return 0;
			return findPath(m,n,0,0); 
		}
		int findPath(int m,int n,int i,int j){
			if(i==m-1||j==n-1) return 1;
			int c_down=0;
			int c_right=0;
			if(i+1<m) c_down = findPath(m,n,i+1,j);
			if(j+1<n) c_right = findPath(m,n,i,j+1);
			return c_down+c_right;
		}
};

int main(){
	Solution sol;
	int out = sol.uniquePaths(23,12);
	cout << out << endl;
	return 1;
}
