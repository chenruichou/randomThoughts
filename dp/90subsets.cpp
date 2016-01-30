#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums){
		vector<vector<int>> out;
		vector<int> cand(nums.size(),0);
		subsetsWithDupSol(out,nums,cand,0);	
	}
	void subsetsWithDupSol(vector<vector<int>> &out, vector<int> &nums, vector<int> cand, int i){
		if(i==nums.size()){
			out.push_back(cand);
			return;
		}
		// recursion
	}

};

int main(){
	Solution sol;
	vector<int> nums = {1,2,2};
	vector<vector<int>> out = sol.subsetsWithDup(nums);
	for(int i=0;i<out.size();i++){
		for(int j=0;j<out[i].size();j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}
