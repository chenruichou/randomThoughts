#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
	vector<vector<int>> curr(grid.size(),vector<int>(grid[0].size(),0));
	findMinPath(grid, 0, 0,curr);
	return curr[0][0];
    }
    void findMinPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &curr){
	int m = grid.size();
	int n = grid[0].size();
	if(i==m-1 && j==n-1){
		curr[i][j] = grid[i][j];
		return;
	} 
	int fromDown=999;
	int fromRight=999;
	if(i+1<m){
		findMinPath(grid,i+1,j,curr);
		fromDown = curr[i+1][j];
	}
	if(j+1<n) {
		findMinPath(grid,i,j+1,curr);
		fromRight = curr[i][j+1];
	}
	curr[i][j] = min(fromDown,fromRight)+grid[i][j];
	return;
    }
};

int main(){
	vector<vector<int>> grid(3,vector<int> (3,2));
	grid[1][1]=1;
	Solution sol;
	cout << sol.minPathSum(grid) << endl;
	return 1;
}
