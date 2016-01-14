#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			//search in the row
			int left = 0;
			int right = matrix.size()-1;
			while(left<right-1){
				int mid = (left+right)/2;
				if(matrix[mid][0]==target){ 
					return true;
				}else if(matrix[mid][0]>target){
					right = mid;
				}else{
					left = mid;
				}	
			}
			int r=0;
			if(matrix[left][0]==target) return true;
			if(matrix[right][0]==target) return true;
			if(target>matrix[right][0]) r = right;
			else r = left;

			//search in the column
			left=0;
			right = matrix[r].size();
			while(left<right-1){
				int mid=(left+right)/2;
				if(matrix[r][mid]==target){
					return true;
				}else if(matrix[r][mid]>target){
					right = mid;
				}else{
					left = mid;
				}
			}
			if(matrix[r][left]==target) return true;
			if(matrix[r][right]==target) return false;

			return false;
		}
};

int main(){
	Solution sol;
	vector<vector<int>> matrix(3,vector<int> (4,0));
	matrix = {
		{1,   3,  5,  7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
			};
	int target = 30;
	bool out = sol.searchMatrix(matrix, target);
	cout << out << endl;
	return 1;
}
