#include <vector>
#include <iostream>
using namespace std;

class Solution{
	public:
		vector<vector<int>> subsets(vector<int> &nums){
			vector<vector<int>> out;
			vector<int> curr;
			subsets_sol(nums,0,curr,out);
			return out;
		}
		void subsets_sol(vector<int> &nums, int i, vector<int> &curr, vector<vector<int>> &out){
			if(i==nums.size()){
				out.push_back(curr);
				return;
			}
			curr.push_back(nums[i]);
			subsets_sol(nums, i+1, curr, out);
			curr.pop_back();
			subsets_sol(nums, i+1, curr, out);
			return;	
		}

};

int main(){
	Solution sol;
	vector<int> nums = {1,2,3,4};
	vector<vector<int>> out = sol.subsets(nums);
	for(int i=0;i<out.size();i++){
		for(int j=0;j<out[i].size();j++)
			cout << out[i][j] << " ";
		cout << endl;
	}

	return 1;
}

