#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			if(obstacleGrid.size()<1 || obstacleGrid[0].size() <1) return 0;
			return findPath(obstacleGrid.size(),obstacleGrid[0].size(),0,0,obstacleGrid); 
		}
		int findPath(int m,int n,int i,int j, vector<vector<int>> &I){
			if(i==m-1||j==n-1) return 1;
			int c_down=0;
			int c_right=0;
			if(i+1<m && I[i+1][j]!=1) c_down = findPath(m,n,i+1,j,I);
			if(j+1<n && I[i][j+1]!=1) c_right = findPath(m,n,i,j+1,I);
			return c_down+c_right;
		}
};

int main(){
	Solution sol;
	vector<vector<int>> I(3,vector<int> (3,0));
	I[1][1]=1;
	int out = sol.uniquePathsWithObstacles(I);
	cout << out << endl;
	return 1;
}
