#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<vector<int>> permutation(vector<int> &nums){
			vector<vector<int>> out;
			//out.push_back(nums); //push the original
			findPermutation(nums, 0, out);
			return out;
		}
		void findPermutation(vector<int> &nums, int indx, vector<vector<int>> &out){
			if(indx==nums.size()-1) return;
			int start;
			if(indx==0)
				start = 0; // tricky!  To special process the first case
			else
				start = indx+1;
			
			for(int i=start; i<nums.size();i++){
				vector<int> nums_copy(nums);
				//swap from "indx" to "i"
				int temp = nums_copy[indx];
				nums_copy[indx] = nums_copy[i];
				nums_copy[i] = temp;
				out.push_back(nums_copy);
				findPermutation(nums_copy, indx+1, out);
			}
			return ;
		}
};

int main(){
	Solution sol;
	vector<int> nums = {1,2,3};
	vector<vector<int>> out = sol.permutation(nums);
	for(int i=0; i<out.size();i++){
		for(int j=0;j<out[i].size();j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}
